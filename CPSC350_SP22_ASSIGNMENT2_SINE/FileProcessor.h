#include "Translator.h"
#include <iostream>
#include <fstream>
using namespace std;

class FileProcessor{
private:
  string reader(string file_name);
  void writer(string file_name, string s);
public:
  FileProcessor();
  void processFile(string infile, string outfile, string translation_type);
  ~FileProcessor();
};
