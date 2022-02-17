#include "FileProcessor.h"
/*
This is the driver class for all of the other source files
main() ensures that there are at least two command line args for proper reading/writing
then instantiates a FileProcessor object in order to read and write to the proper files.
*/
int main(int argc, char **argv){
  FileProcessor fp;
  if(argc < 2){
    cout << "Invalid Parameters: need at least three parameters, bye!" << endl;
  } else{
    cout << "Input File: " << argv[1] << endl;
    cout << "Output File: " << argv[2] << endl;
    fp.processFile(argv[1],argv[2]);
  }
  return 0;
}
