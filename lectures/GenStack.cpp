#include "GenStack.h"
#include <exception>

GenStack::GenStack(){
  mSize = 64; //default size
  top = -1;
  myArray = new char[mSize];
}

GenStack::GenStack(int maxSize){
  mSize = maxSize; //default size
  top = -1;
  myArray = new char[mSize];
}

GenStack::~GenStack(){
  cout << "stack destructed" << endl;
  delete[] myArray;
}

// void GenStack::push(char data){
//   // check if stack is full
//   if(isFull()){
//     throw runtime_error("Stack is full");
//   }
//   myArray[++top] = data; // --> preincrements it so that when it starts at -1, first index gets added to 0 index
//
// }

void GenStack::push(char data){
  // check if stack is full
  if(isFull()){
    cout << "stack is resizing" << endl;
    char *temp = new char[mSize*2];
    for(int i = 0; i < mSize: ++i){
      temp[i] = myArray[i];
    }
    mSize *= 2;
    delete[] myArray; // Garbage collects the pointer pointing to the old array.
    myArray = temp; // updates the array reference of the stack to the new updated larger array (temp)
  }
  myArray[++top] = data; // --> preincrements it so that when it starts at -1, first index gets added to 0 index

}

char GenStack::pop(){
  //make sure stack isn't empty before preceeding
  if(isEmpty()){
    throw runtime_error("Stack is empty, nothing to pop");
  }
  return myArray[top--];
}

char GenStack::peek(){
  //make sure stack isn't empty before preceeding
  if(isEmpty()){
    throw runtime_error("Stack is empty, nothing to peek");
  }
  return myArray[top];
}

bool GenStack::isFull(){
  return (top == mSize-1);
}

bool GenStack::isEmpty(){
  return (top == -1);
}

int GenStack::getSize(){
  return top + 1;
}
