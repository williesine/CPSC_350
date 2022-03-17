/*

    Class c; --> Stack, temporary, as soon as out of scope, automatically GC'd
        If you only need a couple variables/functions, use STACK

    Class *c = new Class(); --> Heap, permanent until you manually GC the object
        Use this if the object is being used throughout the run time
        Use "delete" key word and use -> to use class methods in order to de-reference the object c


STACKS (LIFO data structure - Last in, First out):

    Like arrays, stacks are a container data
        They store objects (data) that we would like to efficiently work with

    With an array, we could access any element we chose.

    Not quite the same with a stack,

        The only element we have access to is the element sitting on the top of the stack
        Visualize a deck of playing cards

            When we want to remove an item from the deck, we remove from the top
            When we add a card (item/data) to the deck, we do so by placing it on top of the other cards

        In other words, we can only insert/remove from the top of the Stack

      Direct applications --> page-visited history in a web browser, undo sequence in text editor, chain of method calls in the c++ RT system

      Indirect applications --> Auxiliary data structure for algorithms & component of other data structure

    STACK INTERFACE:

        Main stack operations:
            push(object): inserts an element
            object pop(): removes the last inserted element

        Auxiliary stack operations:
            object top(): returns the last inserted element without removing it (Also referred to peek())
            integer size(): returns the number of elements sorted
            boolean empty(): indicates whether no elements are stored

    Array-based STACK

        A simple way of implementing the Stack ADT uses an array, we add elements from left to right
        A variable keeps track of the index of the top element
        The array storing the stack elements may become full
        A push operation will then throw a StackFull exception (error)
            Limitation of the array-based implementation


    Performance and Limitations

        Performance
            Let n be the number of elements in the stacks
            The space used is O(N)
            Each operation runs in time O(1)

        Limitations
            The maximum size of the stack must be defined a priori and cannot be changed
            Trying to push a new element into a full stack causes an implementation-specific exception (error)


*/
