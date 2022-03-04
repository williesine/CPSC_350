#include "FileProcessor.h"
/*
This is the driver class for all of the other source files
main() ensures that there are at least three command line args and the inputs
are valid in terms of either translation ("T2E"||"E2T") for proper reading/writing
then instantiates a FileProcessor object in order to read and write to the proper files.
*/
int main(int argc, char **argv){
  FileProcessor fp;
  string to_tut = "E2T";
  string to_eng = "T2E";

  if(argc != 4){
    cout << "Improper Input!" << endl;
    return -1;
  } else{
    cout << "Input File: " << argv[1] << endl;
    cout << "Output File: " << argv[2] << endl;
  }

  if(argv[3] == to_eng){
    cout << "Tutnese --> English" << endl;
    fp.processFile(argv[1],argv[2],argv[3]);
    return 0;
  } else if(argv[3] == to_tut){
    cout << "English --> Tutnese" << endl;
    fp.processFile(argv[1],argv[2],argv[3]);
    return 0;
  } else{
    cout << "Improper input, bye!" << endl;
    return -1;
  }
  return 0;
}
