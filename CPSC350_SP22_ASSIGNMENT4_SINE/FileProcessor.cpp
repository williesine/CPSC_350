#include "FileProcessor.h"

FileProcessor::FileProcessor(){
  // default constructor
}

FileProcessor::~FileProcessor(){
  // Default Destructor
}

// reader() returns a string representing the all of the text from the input file, outputs "FNF" if file not found
string FileProcessor::reader(string file_name){
  ifstream in_file;
  string whole_file = "";
  string line;
  in_file.open(file_name);
  if(!in_file){
    cout << "FNF, please try again." << endl;
  } else{
    while(getline(in_file,line)){
      whole_file += line + "\n";
    }
  }
  in_file.close();
  return whole_file;
}
