#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <fstream>
using namespace std;

class FileProcessor{
public:
  FileProcessor();
  string reader(string file_name);
  // void processFile(string infile); //returns entire file separated by commas
  ~FileProcessor();
};

#endif
