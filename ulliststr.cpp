#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
//////////////////////////////////////////////////////////


// PUSH BACK
void ULListStr::push_back(const std::string& val){

  //first check if the list is empty
  if (tail_ == nullptr){

    //make new item
    tail_ = new Item();
    head_ = tail_;
  }

  //then check if there is no room, ARRSIZE is already defined
  if (tail_->last == ARRSIZE) {
    
    //make new item
    Item *temp = new Item();
    temp->prev = tail_;
    tail_->next = temp;
    tail_ = temp;
  }

  //otherwise add to the tail
  tail_->val[tail_->last] = val;
  tail_->last++;
  size_++;

}

// PUSH FRONT O(1)

//lowkey similar to push_back
void ULListStr::push_front(const std::string& val){

  //if the list is empty
  if (head_ == nullptr){ 
    head_ = new Item();
    tail_ = head_;
    //the number of strings is `last - first`, so we have to
    //keep in mind that last-first = 0, and if the first is 0
    //and last is 10 then 10-0 = 10 which is full :/
    head_->first = ARRSIZE;
    head_->last = ARRSIZE;
  }

  //if there's no room at the front, make a new node
  if (head_->first == 0){
    Item *temp = new Item();
    temp->first = ARRSIZE;
    temp->last = ARRSIZE;
    temp->next = head_;
    head_->prev = temp;
    head_ = temp;
  }

  //otherwise there's space
  head_->first -= 1;
  head_->val[head_->first] = val;
  size_++;

}

// POP BACK O(1)

void ULListStr::pop_back(){

  //if list is empty
  if (tail_ == nullptr){
    return;
  }

  //just remove the last thing
  tail_->last--;
  size_--;

  //if the node becomes empty, then delete everything in it
  if (tail_->last == tail_->first){

    Item *temp = tail_;
    tail_ = tail_->prev;
    if (tail_ != nullptr){
      tail_->next = nullptr;
    } else {
      head_ = nullptr;
    }

    //deallocate
    delete temp;
  }

}

// POP FRONT

//pretty similar to pop back
void ULListStr::pop_front(){

  //if list is empty
  if (head_ == nullptr){
    return;
  }

  //remove last thing
  head_->first++;
  size_--;

  //if the node becomes empty, then delete everything in it
  if (head_->last == head_->first){

    Item *temp = head_;
    head_ = head_->next;
    if (head_ != nullptr){
      head_->prev = nullptr;
    } else {
      tail_ = nullptr;
    }

    //deallocate
    delete temp;
  }
}

// FRONT

std::string const & ULListStr::front() const {

  //head is inclusive so we can just start at `first`
  return head_->val[head_->first];

}

// BACK

std::string const & ULListStr::back() const {

  //tail is exclusive, so subtract 1
  return tail_->val[tail_->last - 1];
  
}

std::string* ULListStr::getValAtLoc(size_t loc) const {

  //check if loc is in bounds
  if (loc >= size_) {
    return NULL;
  }

  Item *curr = head_;
  while (curr != nullptr){

    //# of valid strings is always last-first
    size_t count = curr->last - curr->first;
    if (loc < count){
      
      //element is at (first + loc) and need to be
      //able to modify cuz `string*`
      return &curr->val[curr->first + loc];
    }
    
    //else skip this node
    loc -= count;
    curr = curr->next;
  }

  //return null if nothing found
  return NULL;
}



/////////////////////////////////////////////////////////

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
