#ifndef GENQUEUE_H
#define GENQUEUE_H

#include <iostream>
#include <exception>
using namespace std;

//array based queue
class GenQueue{
public:
  GenQueue(); // default constructor
  GenQueue(int maxSize); // overloaded constructor
  ~GenQueue(); //destructor

  //core functions
  void insert(char d); // aka enqueue
  char remove(); // aka dequeue
  void enqueue(char d); // priority queue

  //auxiliary functions
  char peek();
  bool isFull();
  bool isEmpty();
  unsigned int getSize(); // unsigned int means no negative, size will never be <0
  void printArray();
private:
  int mSize;
  int front;
  int rear;
  unsigned int numElements;
  char *myQueue;
};

#endif
