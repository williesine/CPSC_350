#ifndef GENSTACK_H
#define GENTSTACK_H

#include "DoublyLinkedList.h"
#include <exception>

template <class T>
class GenStack{
public:
  GenStack();
  ~GenStack();

  void push(T data);
  T pop();
  T peek();
  bool isEmpty();

private:
  DoublyLinkedList<T> *stack;
};

//default constructor - instantiates DoublyLinkedList
template <class T>
GenStack<T>::GenStack(){
  stack = new DoublyLinkedList<T>();
}

//default destructor - deletes the pointer pointing to the DoublyLinkedList
template <class T>
GenStack<T>::~GenStack(){
  delete stack;
}

//push(T d) takes in parameter of type template data and inserts it to the front of the list
template <class T>
void GenStack<T>::push(T d){
  stack->insertFront(d);
}

// pop() returns a template type data representing the data of the top item on the stack.
template <class T>
T GenStack<T>::pop(){
  try{
    return stack->removeFront();
  }catch(runtime_error){
    throw runtime_error("Stack is empty, nothing to remove.");
  }
}

//peek() takes no params, returns a template type data using DoublyLinkedList getFront method
template <class T>
T GenStack<T>::peek(){
  try{
    return stack->getFront();
  }catch(runtime_error){
    throw runtime_error("Stack is empty, nothing to peek.");
  }
}

//isEmpty() returns true if empty, false if not
template <class T>
bool GenStack<T>::isEmpty(){
  return stack->isEmpty();
}


#endif
