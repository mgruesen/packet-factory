#include <core/packet/packet.hpp>

#include <iostream>

using namespace pf;


int
default_ctor()
{
  packet p;
  int len = p.length();
  auto data = p.data();

  bool len_chk = len == 0;
  bool data_chk = data == nullptr;

  if (!len_chk)
    std::cout << "length was " << len << '\n';
  
  if (!data_chk)
    std::cout << "data was NOT nullptr\n";

  return !len_chk || !data_chk;
}


int
ctor()
{
  unsigned char* input_data = new unsigned char[10];
  unsigned int input_len = 10;
  packet p(input_data, input_len);
  int len = p.length();
  auto data = p.data();
  
  bool len_chk = len == input_len;
  bool data_chk = data == input_data;
  
  if (!len_chk)
    std::cout << "length was " << len << '\n';
  
  if (!data_chk)
    std::cout << "data was NOT 'input_data'\n";
  
  return !len_chk || !data_chk;
}


int
main(int argc, char** argv)
{
  std::string passed = "passed\n";
  std::string failed = "failed\n";
  std::cout << "Packet tests\n-------------------------------------------\n";
  std::cout << "Test 'packet::default ctor'...";

  int num_failed = 0;

  if (default_ctor() != 0) {
    std::cout << failed;
    num_failed++;
  }
  std::cout << passed;


  std::cout << "Test 'packet::ctor'...";
  if (ctor() != 0) {
    std::cout << failed;
    num_failed++;
  }
  std::cout << passed;

  std::cout << '\n';
  return num_failed;
}
