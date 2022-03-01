#include "GenQueue.h"

GenQueue::GenQueue(){
  mSize = 128; //default size
  front = 0;
  rear = 0;
  numElements = 0;
  myQueue = new char[mSize];
}

GenQueue::GenQueue(int maxSize){
  mSize = maxSize;
  front = 0;
  rear = 0;
  numElements = 0;
  myQueue = new char[mSize];
}

GenQueue::~GenQueue(){
  delete [] myQueue;
}

void GenQueue::insert(char d){
  if(isFull()){
    throw runtime_error("queue is full");
  }

  myQueue[rear++] = d;
  rear %= mSize; // rear = rear % mSize; anything less keeps the value the same
  numElements++;

}

char GenQueue::remove(){
  if(isEmpty()){
    throw runtime_error("Queue is empty");
  }

  char c = '\0';
  c = myQueue[front++]; // post increment
  front %= mSize; // front = front % mSize
  numElements--;
  return c;
}

char GenQueue::peek(){
  return myQueue[front];
}

bool GenQueue::isFull(){
  return numElements == mSize;
}

bool GenQueue::isEmpty(){
  return numElements == 0;
}

unsigned int GenQueue::getSize(){
  return numElements;
}
