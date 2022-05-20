

#ifndef LISTNODE_HPP
#define LISTNODE_HPP

#include <stdio.h>

template <typename T>
class ListNode{
    public:
        ListNode();
        ListNode(T d);
        ~ListNode();
        ListNode *next;
        ListNode *prev;
        T data;
};

//implementation
template <typename T>
ListNode<T>::ListNode(){}

template <typename T>
ListNode<T>::ListNode(T d){
    data = d;
    next = NULL; // 0 nullptr
    prev = NULL;
}

template <typename T>
ListNode<T>::~ListNode(){
    //research
}

#endif /* ListNode_hpp */
