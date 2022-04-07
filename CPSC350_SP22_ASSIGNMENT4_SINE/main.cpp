#include "SyntaxChecker.h"

int main(int argc, char **argv){
  SyntaxChecker syn;

  try{
    syn.parseFile(argv[0]);
  } catch (runtime_error){
    throw runtime_error("Improper input, bye!");
  }

  return 0;
}
