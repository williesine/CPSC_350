/*



  Single Linked List
      What we need is a data structure that will allow us:
          Insert an arbitrary number of Items
          handle the usual operations: delete and search in an efficient manner

      A singly linked list is a concrete data structure consisting of a sequence of nodes
          each node stores: element(data) & Link (pointer) to the next node

      One obvious assessment of the Linked list vs. array
          nodes do not have an absolute position
          Linked list can grow and shrink as needed
              size is dynamic

          With a linked list, the only way to find an item is to start at the front of the list and scan through, following next ptrs
              While this may seem inefficient, in most cases we have to scan an array to find an item, so it's not a big deal

          Basic Operations:

              Insert,find/search, & delete


      Inserting at the Head (front)
          Allocate new node

          Insert new element
              Have new node point to old head
              Update head to point to new node

          Inserting code snippet`

          //assume node of integers

          void NaiveList::insertFront(int d){
            ListNode *node = new ListNode(d);
            node->next = front;
            front = node;
            ++size;
        }

      Removing at the Head/Front
          Update head to point to next node in list
          Allow GC to reclaim the former first node

          Code Snippet
          int NaiveList::removeFront(){
            int temp = front->data;
            ListNode *ft = front;
            front = front->next;
            ft->next = NULL;
            --size;
            delete ft;
            return temp;
        }


      Double-Ended Linked List
          Inserting at the back

        Performance
            Let n be the number of elements in the list
            The space used is 0(n)

            Each Operation
                Search O(n)
                  (same as array)

                Insert/delete, Insert back DE list O(1)

                Insert @ specific position & deleting last element = O(n)

        Limitations
            Performance, Search is linear, delete @ last element is linear, but we can do better


      DOUBLY LINKED LIST

          Extension of a Single Linked List but had added flexibility properties
          A doubly linked list is consist of a sequence of nodes

            Each node stores
              Element (data)
              Link (pointer) to the next node (also referred to forward ptr)
              Link (pointer) to the previous node (also referred to as backward)

          The most common implementation of the linked list is probably the doubly linked LIST
              preferred choice for in built-in libraries

          The forward and previous pointers allow:
              Efficient node deletion, faster fetching of end nodes (front/rear)
              more flexible iteration

          The added flexibilty comes at a cost
              More memory required, not ideal for embedded systems with limited resources


          Performance and Limitations

            Let n be the number of elements in the linked list

              The space used is O(n)

              Each operation:

                  Search is linear O(n)
                      same as array

                  Insert/Delete Front/Back O(1)

                  Insert/Delete O(n) if node is NOT Front or Back

            Limitations:

                Not the most efficient in terms of memory consumption





















*/
