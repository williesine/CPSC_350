/*
SAME LIST USED IN ASSIGNMENT 5
*/

#ifndef GENLIST_HPP
#define GENLIST_HPP

#include "ListInterface.hpp"
#include "ListNode.hpp"
#include <iostream>
#include <exception>
using namespace std;

template<typename T>
class GenList : public ListInterface<T> {
private:
    ListNode<T> *front;
    ListNode<T> *back;
    unsigned int size;
public:

    GenList(){
        front = NULL;
        back = NULL;
        size = 0;
    }
    ~GenList(){
        ListNode<T> *node = front;
        ListNode<T> *nodeToDelete = front;
        while (node != NULL){
            nodeToDelete = node->next;
            delete node;
            node = nodeToDelete;
        }
    }
    /*done*/void append(T data){
        ListNode<T> *node = new ListNode<T>(data);

        if(isEmpty()){
            front = node;
        }
        else{
            node->prev = back;
            back->next = node;
        }
        back = node;
        ++size;
    } //appends data to end of list

    /*done*/void prepend(T data){
        ListNode<T> * node = new ListNode<T>(data);

        if(isEmpty()){
            back = node;
        }
        else{
            //it's not empty
            node->next = front;
            front->prev = node;
        }
        front = node;
        ++size;
    } //prepends data to front of list
    /*done*/bool insertAfter(T data, int index){
        if(index >= size){
            return false;
        }
        int location = 0;
        ListNode<T>* current = front;
        while(current != nullptr){
            if(location == index){
                break;
            }
            current = current->next;
            location++;
        }
        ListNode<T>* newNode = new ListNode<T>(data);
        if(index == size - 1){ //end of list insertion
            current->next = newNode;
            newNode->prev = current;
        }
        else{
            newNode->next = current->next;
            current->next->prev = newNode;
            current->next = newNode;
            newNode->prev = current;
        }
        return true;
    } //inserts data after index
    /*done*/T remove(T data){
        if(isEmpty()){
            cout << "List is empty" << endl;
            return NULL;
        }

        //we could leverage the find method

        ListNode<T> *curr = front;
        while(curr->data != data){
            curr = curr->next;

            if(curr == NULL)
                return NULL;
        }
        //but if we make it here, we found the value
        //we found it , let's proceed to remove it

        if(curr != front && curr != back){
            //it's in between front and back
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }

        if(curr == front){
            if(size == 1){
                delete front;
                front = nullptr;
            }
            else{
                front = curr->next;
                front->prev = NULL;
            }

        }

        if(curr == back){
            if(size == 1){
                delete back;
                back = nullptr;
            }
            else{
                back = curr->prev;
                back->next = NULL;
            }

        }

        curr->next = NULL;
        curr->prev = NULL;
        T data2 = curr->data;
        --size;
        delete curr;

        return data2;
    } // removes data from list and returns it
    /*done*/T search(T data){
        T pos = NULL;
        ListNode<T> *curr = front;

        while(curr != NULL){
            ++pos;
            if(curr->data == data)
                break;

            curr = curr->next;
        }
        //checks if curr is NULL which signifies value not in Linked List
        if(curr == NULL)
            pos = NULL;

        return pos;
    } //returns null if not found
    void printReverse(){} //prints list in reverse
    void sort(){} //sorts in ascending order
    /*done*/bool isEmpty(){
        return (size == 0);
    }//returns true if list has no items
    /*done*/int getLength(){
        return size;
    } //returns number of items in the list
    T getFront(){
        return front->data;
    }


    string toFileString(){
        string str = "";
        str += to_string(size);
        str += "\n";
        ListNode<T>* current = front;
        while(front != nullptr){
            str += to_string(current->data);
            str += "\n";
        }
        str = str.substr(0, str.length() - 1); //trim newline space from the loop
        return str;
    }

};


#endif
