#include <core/packet/packet.hpp>

#include <iostream>

using namespace pf;


int
default_ctor()
{
  field f;
  int base = f._base;
  int offset = f._offset;
  int len = f._length;
  
  int expected = 0;
  
  bool base_chk = base == expected;
  bool offset_chk = offset == expected;
  bool len_chk = len == expected;

  if (!base_chk)
    std::cout << "base was " << base << '\n';
  if (!offset_chk)
    std::cout << "offset was " << offset << '\n';
  if (!len_chk)
    std::cout << "length was " << len << '\n';
  
  return !base_chk || !offset_chk || !len_chk;
}


int
main(int argc, char** argv)
{
  const std::string passed = "passed\n";
  const std::string failed = "failed\n";
  std::cout << "Field tests\n-------------------------------------------\n";
 
  int num_failed = 0;
 
  std::cout << "Test 'field::default ctor'...";
  if (default_ctor() != 0) {
    std::cout << failed;
    num_failed++;
  }
  std::cout << passed;

  std::cout << '\n';
  return num_failed;
}
