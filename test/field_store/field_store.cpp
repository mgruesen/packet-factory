#include <core/packet/packet.hpp>

#include <iostream>
#include <string>

using namespace pf;


int
default_ctor()
{
  field_store store;
  
  return store.size();
}

int
insert()
{
  field_store store;
  
  field val = {0, 10, 5};
  std::string key = "ipv4";

  store.add_field(key, val);
  auto result = store.get_field(key);
  bool contains = store.size();
  bool matches = result == val;

  if (!contains)
    std::cout << "field_store is empty after insertion\n";
  if (!matches)
    std::cout << "field_store value returned does not match input\n";

  return !contains || !matches;
}

int
main(int argc, char** argv)
{
  const std::string passed = "passed\n";
  const std::string failed = "failed\n";
  std::cout << "Field_store tests\n-------------------------------------------\n";
  std::cout << "Test 'field_store::default ctor'...";
  
  int num_failed = 0;
  
  if (default_ctor()) {
    std::cout << failed;
    num_failed++;
  }
  std::cout << passed;

  std::cout << "Test 'field_store::insert'...";
  if (insert()) {
    std::cout << failed;
    num_failed++;
  }
  std::cout << passed;
  

  std::cout << '\n';
  return num_failed;
}
