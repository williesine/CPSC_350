/*

Queue

    The queue is very similar structually although behaves quite differently
    Visualize a line at the movies
        The first item to be inserted into the queue is the first to be removed
        Items are inserted from the rear of the queue
    A queue is a FIFO data structure ("First in first out")

    Queues are incredibly useful tools for programmers

    Direct applications --> Critical to OS process management
        Access to shared resources (printer)
        Priority Queue
        Waiting list, bureaucracy

    Indirect applications --> Auxiliary data structure for algorithms, component of other data structure

  Queue Interface (Non-circular Queue) --> where the space is reclaimed

    Insertions and deletions follow the FIFO scheme
    Main Queue Operations

      enqueue(object): inserts an element at the end of Queue
          throws an exception (error) if the array is full

      dequeue(): removes ovject at the front of the queue
          throws an exception if the queue is empty
          This exception specified in the Queue ADT

    Auxiliary Operations:
        object front(): returns the element at front without removing
            Also called peek()

        integer size() --> returns the number of elements stored

        boolean empty(): indicates whether queue is empty or not



  ARRAY BASED QUEUE

      Use an array of size N
    Three variables to be tracked:
          f --> index of front element
          r --> index immediately past the rear index
          n --> number of items in the queue


  QUEUE PERFORMANCE AND LIMITATION
      Performance:
          Let n be the number of elements in the QUEUE
          the space used is O(n)
          Each operation runs in time O(1)

      LIMITATIONS:
          The maximum size of the queue must be defined a priori and cannot be changed
          Trying to insert a new element into a full queueu causes an implementation-specific exception (error)
              Unless its a circular queue

      CIRCULAR QUEUES
          As we remove and push the front of the queue back, we end up with numerous unused elements in the ARRAY
          When the array gets full, we could always just make a new array and copy everything
              But it would be better if we could reuse the space at the front of the queue.

          When we insert an item and rear is at the last element in the array, we can just wrap it around to the front


      Other Types of Queues

          DE-Queue (Double Ended Queue)

          Priority Queue
            With a regular queue, order of items was irrelevant
            There may be situations in which we would like the contents of the queue sorted on some key value
                Ascending, descending, the value of the key of the item we want to insert is the items priority

            constant time access to elements with the maximum or minimum key elements
            The only change is the insert functions: which has to shift things around to find the right place for the queue

            















*/
