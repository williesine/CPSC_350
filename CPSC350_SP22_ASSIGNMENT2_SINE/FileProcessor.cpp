#include "FileProcessor.h"


FileProcessor::FileProcessor(){
  // default constructor
}

/* processFile() is a void type method that instantiates a translator so that
the method can use the private methods reader() and writer() and while translating the text
to Tutnese.
*/
void FileProcessor::processFile(string ifile, string ofile, string translation_type){
  Translator t;
  if(translation_type == "E2T"){
    string translated_text = "";
    string to_translate = reader(ifile);
    translated_text = t.translateEnglishSentence(to_translate);
    writer(ofile, translated_text);
  } else if(translation_type == "T2E"){
    string translated_text = "";
    string to_translate = reader(ifile);
    translated_text = t.translateTutSentence(to_translate);
    writer(ofile,translated_text);
  }
}

FileProcessor::~FileProcessor(){
  // Default Destructor
}

// reader() returns a string representing the all of the text from the input file, outputs "FNF" if file not found
string FileProcessor::reader(string file_name){
  ifstream in_file;
  string whole_string = "";
  string line;
  in_file.open(file_name);
  if(!in_file){
    cout << "FNF" << endl;
  } else{
    while(getline(in_file,line)){
      whole_string += line + "\n";
    }
  }
  in_file.close();
  return whole_string;
}

/* writer() is a void return type method that simply takes in a file name and string
(representing the Tutnese translation) and then writes to the output file line by line.
*/
void FileProcessor::writer(string file_name, string s){
  ofstream out_file;
  out_file.open(file_name,ios::out);
  out_file << s << endl;
  out_file.close();
}
