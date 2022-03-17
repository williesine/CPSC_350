/*

INTRO TO ALGORITHIM ANALYSIS:


Algorithim - a process or set of rules to be followed to solve a problem (usually done by comp)

The Runtime of an algorithim is the time it takes to execute.
    Ex: (Zybook) if a comparison takes 1 microsecond, a linear search algorithim's runtime is up to 1s to search a list with 1,000,000 Elements


Most algorithims transform input objects into output objects
Given two algorithims that do same thing, we need a method to evaluate performance.
  Two Methods of measuring performance
      Empirical Analysis (Experimental analysis)
      Mathematical Analysis (Formal)

Empirical Analysis (Experimental ANALYSIS)

    Implement both algorithims and run experiment with the same input
    Obvious approach, but not an optimal solution

This type of analysis is not great for large data sets
Not cost efficient
  Algorithim needs to be implemented
    COSTS TiME AND MONEY

Dependent on many variables
  Platform/hardware
  compilers/linkers


Mathematical Analysis (Theoretical analysis)
  Determine factors that determine the run-time of an algorithim
    Input (size)
    Quality of code
        Nested for loops
        Proper use of data structures

  Run-time depends on input
      Algorithim can be defined as a function of the Input
      Takes into account all possible inputs
      T(n) = c*n^2, where c is a constant (Algo A)
      T(n) = c*5n , where c is a constant (Algo B)

  Very cost efficient
  NOT dependent on many variables
      Platform/hardware
      compilers/linkers


Algorithim Run Times (from fastest to slowest)
    T(n) = 1; CONSTANT RUN-TIME. Programs with instructions that are executed only once, few at most

    log N - logarithimic run time. An N grows, the program slows down slightly
        Takes input and is cut into series of smaller problems, cutting size by a constant at each step

    N - Linear RUN TIME; If N is a million, so is run-time

    N log N - when N (input) doubles, the run-time increases slighlty more than double
        Algorithims break problem into smaller problems, then combines results

    N^2 - quadratic run-time. When N doubles, run time increases by an order of 4

    N^3 - cubic run-time; when N doubles, run-TiME (T(n)) increases by an order of 8



Big O Notation
    Allows us to ignore all of the constants and lower-order term

    Formal definition: KNOW THIS VER BATUM:
    given two functions f(n) and g(n), f(n) = O(g(n)) if there exists constants
    c and n not such that f(n) <= cg(n) for all n > n not

        Saying an algorithim is O(f(n)) is saying that in the worst case, the run time of the algorithim to be about f(n)

        Big O provides a growth rate for an algorithim's upper bound (worst case

    Essentially, this bounds the error we get when we ignore constants and lower-order terms, and lets us analyze functions in regards
    to their asymptotic upper bounds for sufficiently large values of n

    In other words, Big O notation is a mathematical way of describing how a function (running time of an algorithim) generally
    behaves in relation to the input size. (Zybook)





















*/
