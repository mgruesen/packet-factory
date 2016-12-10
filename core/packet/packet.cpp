#include "packet.hpp"
#include <cassert>

namespace pf
{

////////////////////////// Field definitions ////////////////////////////////////
// Equality comparators.
bool
operator==(field& a, field& b)
{
  return a._base == b._base && a._offset == b._offset && a._length == b._length;
}

bool
operator==(field a, field b)
{
  return a._base == b._base && a._offset == b._offset && a._length == b._length;
}
////////////////////////// Field store definitions //////////////////////////////
// Field store ctor/dtor.
field_store::field_store()
  : _store()
{ }

field_store::~field_store()
{
  _store.clear();
}


// Accessors.
int
field_store::size() const
{
  return _store.size();
}

void
field_store::add_field(std::string& key, field val)
{
  assert(_store.find(key) == _store.end());

  if (_store.find(key) == _store.end())
    _store.emplace(key, val);
}

field
field_store::get_field(std::string& key) const
{
  assert(_store.find(key) != _store.end());

  return _store.at(key);
}


////////////////////////// Packet definitions //////////////////////////////////

// Packet ctors/dtor.
packet::packet()
  : _fields(), _length(0), _data(nullptr)
{ }


packet::packet(data_type data, uint32_t length)
  : _fields(), _length(length), _data(data)
{ }


packet::~packet()
{ }


auto
packet::data() const -> data_type
{
  return _data;
}


uint32_t
packet::length() const
{
  return _length;
}


} // End namespace pf
