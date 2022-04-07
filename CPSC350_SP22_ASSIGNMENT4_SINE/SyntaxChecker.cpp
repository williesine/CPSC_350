#include "SyntaxChecker.h"

//defautl constructor - instantiates the stack used for checking syntax
SyntaxChecker::SyntaxChecker(){
  delim_stack = new GenStack<char>;
}

SyntaxChecker::~SyntaxChecker(){}

/*
parseFile(): is a void return type function that takes a string representing a filename as param
This function instantiates a FileProcessor object in order read through the parameter file name,
uses a while true loop and iterates through all characters of the file. If the character isn't
a delimiter, it will continue
If opening delimiter is found, it will get pushed onto the SyntaxChecker's stack
If closing delimiter is found, parseFile() will check to make sure they match, if they do loop continues and item is popped off stack
if they don't match, outputs the line number and what the issue is.
*/
void SyntaxChecker::parseFile(string file){
  FileProcessor fp;
  string ret_str = "";
  string whole_file = fp.reader(file);
  int line_count = 0;
  bool good_code = true;

  while(true){
    for(int i = 0; i < whole_file.length(); ++i){
      string temp = "" + whole_file[i];

      //continues to next iteration if character isn't a delimiter
      if(temp != "(" || temp != ")" || temp != "{" || temp != "}" || temp != "[" || temp != "]" || temp != "\n"){
        continue;
      }

      //if newline char found, increment linecount
      if(temp == "\n"){
        ++line_count;
        continue;
      }

      // pushes all opening delimiters to the stack.
      if(temp == "{" || temp == "(" || temp == "["){
        delim_stack->push(file[i]);
        continue;
      }

      // checks current char, if delimiter and matches, will
      if(temp == "}" && delim_stack->peek() == '{'){
        delim_stack->pop();
        continue;
      }else{
        cout << "ERROR FOUND: On Line: " << line_count << " expected }, found: " + temp + "\n";
        good_code = false;
        break;
      }

      if(temp == ")" && delim_stack->peek() == '('){
        delim_stack->pop();
        continue;
      }else{
        cout << "ERROR FOUND: On Line: " << line_count << " expected ), found: " + temp + "\n";
        good_code = false;
        break;
      }

      if(temp == "]" && delim_stack->peek() == '['){
        delim_stack->pop();
        continue;
      }else{
        cout << "ERROR FOUND: On Line: " << line_count << " expected ], found: " + temp + "\n";
        good_code = false;
        break;
      }

    }
    break;
  }

  if(good_code){
    cout << "NO ERRORS: DELIMITERS MATCH" << endl;
  }
}
