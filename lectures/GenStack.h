#ifndef GENSTACK_H  // header gaurd
#define GENSTACK_H
#include <iostream>

using namespace std;

class GenStack{
public:
  GenStack(); //default constructor
  GenStack(int maxSize); //overloaded constructor
  ~GenStack(); // destructor

  //core functions
  void push(char data);
  char pop();
  char peek(); // aka top()

  //Auxiliary functions
  bool isEmpty();
  bool isFull();
  int getSize();

private:
  char *myArray;
  int top;
  int mSize;
};


#endif
