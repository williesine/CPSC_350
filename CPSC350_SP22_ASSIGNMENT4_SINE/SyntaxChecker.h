#ifndef SYNTAXCHECKER_H
#define SYNTAXCHECKER_H

#include "GenStack.h"
#include "FileProcessor.h"

class SyntaxChecker{
public:
  SyntaxChecker();
  ~SyntaxChecker();

  void parseFile(string line);

private:
  GenStack<char> *delim_stack;

};


#endif
