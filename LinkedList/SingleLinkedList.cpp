#include "SingleLinkedList.h"

SingleLinkedList::SingleLinkedList(){
  front = NULL;
  back = NULL;
  size = 0;
}

SingleLinkedList::~SingleLinkedList(){
  // build some character
  // do on your own, check zybooks
}

SingleLinkedList::insertFront(int d){
  ListNode *node = new ListNode(d); // must be on heap because it will get popped off after call if on stack

  if(isEmpty()){
    back = node;
  }
  node->next = front;
  front = node;
  size++;
}

void SingleLinkedList::insertBack(int d){
  ListNode *node = new ListNode(d);

  if(isEmpty()){
    front = node;
  } else{
    back->next = node;
  }
  back = node;
  size++;
}

bool SingleLinkedList::isEmpty(){
  return size == 0;
}

int SingleLinkedList::removeFront(){
  if(isEmpty()){
    cout << "list is empty" << endl;
    return -1;
  } else if(size == 1){
    back = NULL;
  }

  int temp = front->data;
  ListNode *ft = front;

  front = front->next;
  ft->next = NULL;
  delete ft;
  size--;
  return temp;
}

int SingleLinkedList::removeBack(){
  //do on your own
}

int SingleLinkedList::find(int value){
  int pos = -1;

  ListNode *curr = front;
  while(curr != NULL){
    ++pos;
    if(curr->data == value){
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

int SingleLinkedList::deleteAtPos(int pos){
//check if empty, and check if value exists
  int idx = 0;
  ListNode *curr = front;
  ListNode *prev = front;

  while(idx != pos){
    prev = curr;
    curr = curr->next;
    idx++
  }
// found it, proceed to delete

  prev->next = curr->next;
  curr->next = NULL;
  int d = curr->data;
  size--;

  delete curr;
  return d;

}









//as
