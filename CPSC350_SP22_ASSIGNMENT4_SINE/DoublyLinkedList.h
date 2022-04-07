#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
using namespace std;

template <class T>
class ListNode{
public:
  T data;
  ListNode *next;
  ListNode *prev;

  ListNode();
  ListNode(T d);
  ~ListNode();
};

// default
template <class T>
ListNode<T>::ListNode(){
  next = NULL;
  prev = NULL;
}

//overloaded, takes in template type and assigns it to node's data member variable
template <class T>
ListNode<T>::ListNode(T d){
  next = NULL;
  prev = NULL;
  data = d;
}

//default destructor
template <class T>
ListNode<T>::~ListNode(){}

template<class T>
class DoublyLinkedList{
private:
  ListNode<T> *front;
  ListNode<T> *back;
  unsigned int m_size;

public:
  DoublyLinkedList();
  ~DoublyLinkedList();

  void insertFront(T d);
  void insertBack(T d);
  T removeFront();
  T removeBack();
  T removeNode(T val);
  int find(T val);
  bool isEmpty();
  unsigned int getSize();
  T getFront();
  void printList(bool isPrintLink);
};

//default constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  m_size = 0;
  front = NULL;
  back = NULL;
}

/*
~DoublyLinkedList() is the destructor for the doubly linked list
iterates through the list until all the nodes are deleted, and then
finally deletes the front node.
*/
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  if(!isEmpty()){
    while(front->next != NULL){
      front->next->prev = NULL;

      ListNode<T> *temp = front;
      front = front->next;
      delete temp;
      --m_size;
    }
    delete front;
  }
}

/*
insertFront(T d) takes in a template data type and inserts it to the front
of the list, also handles case if list is empty
*/
template <class T>
void DoublyLinkedList<T>::insertFront(T d){
  ListNode<T> *node = new ListNode<T>(d);

  if(isEmpty()){
    back = node;
  } else{
    node->next = front;
    front->prev = node;
  }
  front = node;
  ++m_size;
}

/*
insertBack(T d) takes in a template data type and inserts to the back of the
list, additionally, handles case if list is empty
*/
template <class T>
void DoublyLinkedList<T>::insertBack(T d){
  ListNode<T> *node = new ListNode<T>(d);

  if(isEmpty()){
    front = node;
  } else{
    node->prev = back;
    back->next = node;
  }
  back = node;
  ++m_size;
}

/*
removeFront() returns a template type data representing the type of linked List
and deletes it from the list
*/
template <class T>
T DoublyLinkedList<T>::removeFront(){
  ListNode<T> *temp = front;

  if(front->next == NULL){
    back = NULL; //only one node in LL
  } else{
    front->next->prev = NULL;
  }

  front = front->next;
  temp->next = NULL;
  T tempData = temp->data;
  delete temp;
  --m_size;

  return tempData;
}

/*
removeBack() takes no parameters, returns a template type data
representing the data of the last node.
*/
template <class T>
T DoublyLinkedList<T>::removeBack(){
  ListNode<T> *temp = back;

  if(back->prev == NULL){
    front = NULL;
  } else{
    back->prev->next = NULL;
  }

  back = back->prev;
  temp->prev = NULL;
  T tempData = temp->data;
  delete temp;
  --m_size;

  return tempData;
}

/*
removeNode (T val) takes in and returns a template type data, representing the data
of the node at the specified parameter position.
*/
template <class T>
T DoublyLinkedList<T>::removeNode(T val){
  ListNode<T> *curr = front;

  while(curr->data !=val){
    curr = curr->next;
    if(curr == NULL){
      return -1; //not in list
    }
  }

  if(curr == front){
    front = curr->next;
  }else{
    curr->prev->next = curr->next;
  }

  if(curr == back){
    back = curr->prev;
  }else{
    curr->next->prev = curr->prev;
  }

  curr->next = NULL;
  curr->prev = NULL;
  T tempData = curr->data;
  --m_size;
  delete curr;

  return tempData;
}

// searches list until node with desired data is found and returns position.
template <class T>
int DoublyLinkedList<T>::find(T val){
  int pos = -1;
  ListNode<T> *curr = front;

  while(curr != NULL){
    ++pos;
    if(curr->data == val){
      break;
    }else{
      curr = curr->next;
    }
  }

  if(curr == NULL){
    pos = -1;
  }

  return pos;
}

//returns the data of the front node
template <class T>
T DoublyLinkedList<T>::getFront(){
  return front->data;
}

//returns the size of the list
template <class T>
unsigned int DoublyLinkedList<T>::getSize(){
  return m_size;
}

//isEmpty() returns a boolean true if empty, false if not empty
template <class T>
bool DoublyLinkedList<T>::isEmpty(){
  return (m_size == 0);
}


#endif
