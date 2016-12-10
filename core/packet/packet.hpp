#ifndef PF_PACKET_HPP
#define PF_PACKET_HPP

#include <string>
#include <cstdint>
#include <unordered_map>

// The abstraction of a packet. Contains a wrapper on top of raw
// packet data. Relevant fields, within 
namespace pf
{


// Gives the context needed to extract a value from a packet header.
// This is expressed in three parts: the absolute offset from the 
// beginning of the packet data as the header, the relative offset
// from the beginning of the header as the field, and the length of
// the field.
struct field
{
  uint16_t _base = 0;
  uint16_t _offset = 0;
  uint16_t _length = 0;
};

bool operator==(field, field);


// Manages the storage of fields. Maps a user defined label, string,
// to a field.
class field_store
{
  using store_type = std::unordered_map<std::string, field>;
public:
  // Ctor/dtor.
  field_store();
  ~field_store();

  // Accessor.
  int   size() const;
  field get_field(std::string&) const;
  
  // Mutator.
  void  add_field(std::string&, field);

private:
  // Data member.
  store_type _store;
};



// The abstraction of a network packet. Contains a pointer to the raw
// packet data, the total length of the packet data, and a store to
// manage the locations of packet headers and fields discovered by a
// decoder.
class packet
{
  using data_type = uint8_t*;
public:

  // Ctors/dtor.
  packet();
  ~packet();

  packet(data_type, uint32_t);

  // Accessors.
  field     get_field(std::string&) const;
  uint32_t  length() const;  
  data_type data() const;
  
  // Mutators.
  void add_field(std::string&, field);

protected:
  field_store _fields;
  uint32_t    _length;
  data_type   _data;
};


}

#endif
