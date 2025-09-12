#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;

  std::cout << "first test:" << std::endl;

  std::cout << "empty? " << list.empty() << " size: " << list.size() << std::endl;


  //push back
  std::cout << "push_back:" << std::endl;
  list.push_back("Apples");
  std::cout << "front: " << list.front() << " back: " << list.back()
            << " size: " << list.size() << std::endl;

  //push front
  std::cout << "push_front:" << std::endl;
  list.push_back("Bananas");
  std::cout << "front: " << list.front() << " back: " << list.back()
            << " size: " << list.size() << std::endl;

  //push back (again)
  std::cout << "push_back:" << std::endl;
  list.push_back("Oranges");
  std::cout << "front: " << list.front() << " back: " << list.back()
            << " size: " << list.size() << std::endl;

  //print
  std::cout << "list contents: " <<std::endl;
  for (size_t i = 0; i < list.size(); i++){
    std::cout << i << ": " << list.get(i) << std::endl;
  }

  //set
  std::cout << "setting st(1, 'Bayerische Motoren Werke') " <<std::endl;
  list.set(1,"Bayerische Motoren Werke");
  for (size_t i = 0; i < list.size(); i++){
    std::cout << i << ": " << list.get(i) << std::endl;
  }

  //pop back
  std::cout << "pop back:" << std::endl;
  list.pop_back();
  std::cout << "front: " << list.front() << " back: " << list.back()
            << " size: " << list.size() << std::endl;

  //pop front
  std::cout << "pop front:" << std::endl;
  list.pop_front();
  std::cout << "front: " << list.front() << " back: " << list.back()
            << " size: " << list.size() << std::endl;
}
