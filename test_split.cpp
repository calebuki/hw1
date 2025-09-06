/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

int main(int argc, char* argv[])
{

  //setup
  Node *test = new Node(0, nullptr);
  Node *tail = test;
  for (int i = 1; i <= 10; i++){
    tail->next = new Node(i, nullptr);
    tail = tail->next;
  }

  Node *odds = nullptr;
  Node *evens = nullptr;

  split(test,odds,evens);

  Node *counter1 = evens;
  Node *counter2 = odds;

  std::cout << "testing with a linked list from 1-10: " << std::endl;

  std::cout << "evens: ";
  while (counter1 != nullptr){
    std::cout << counter1->value << " ";
    counter1 = counter1->next;
  }
  std::cout << std::endl;

  std::cout << "odds: ";
  while (counter2 != nullptr){
    std::cout << counter2->value << " ";
    counter2 = counter2->next;
  }
  std::cout << std::endl;

  //delete
  counter1 = evens;
  counter2 = odds;
  while (counter1 != nullptr){
    Node *temp = counter1->next;
    delete counter1;
    counter1 = temp;
  }

  while (counter2 != nullptr){
    Node *temp = counter2->next;
    delete counter2;
    counter2 = temp;
  }
  

}
