#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include "ListNode.h"
//single because only one pointer to next
class SingleLinkedList{
private:
  ListNode *front;
  ListNode *back;
  unsigned int size;
public:
  SingleLinkedList();
  ~SingleLinkedList();
  void insertFront(int d);
  void insertBack(int d);
  int removeFront();
  int removeBack(); // finish by self
  int find(int value);
  int deleteAtPos(int pos);
  bool isEmpty();
  unsigned int getSize();
};


#endif
