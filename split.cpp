/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

  //probably check if null (nothing to return?)
  if (in == nullptr){
    odds = nullptr;
    evens = nullptr;
    return;
  } 

  //we need to go from the back to the front first
  Node *curr = in;
  Node *temp = curr->next;
  curr->next = nullptr;
  split(temp, odds, evens);

  //check if even
  if (curr->value % 2 == 0){
    curr->next = evens;
    evens = curr;
  }

  //check if odd
  else {
    curr->next = odds;
    odds = curr;
  }

  //finally set `in` to nullptr
  in = nullptr;
}

/* If you needed a helper function, write it here */
