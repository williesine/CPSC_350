#include "Translator.h"

// Default Constructor
Translator::Translator(){
  // Nothing Needed
}

/*
translateEnglishWord() takes in a string (word) as param
returns a string (representing the tutnese translation of an english word),
Also instantiates a Model object so that the translation may occur
*/
string Translator::translateEnglishWord(string w){
  string word = "";
  Model m;
  for(int i = 0; i < w.size(); ++i){
    if(w[i] == w[i+1]){
      word += m.translateDoubleCharacter(w[i]);
      ++i; //iterates past second consecutive char to avoid double translation
    } else{
      word += m.translateSingleCharacter(w[i]);
    }
  }
  return word;
}

/*
translateEnglishSentence() takes in a string representing a sentence
found isalpha() from STL, returns 0 if non-alphabetical, returns 1 if char is alphabetical
add a newline char at the end of the sentence to maintain the spacing from original ifile
*/
string Translator::translateEnglishSentence(string s){ //work ON THIS
  string sent = "";
  string temp = "";
  for(int i = 0; i < s.size(); ++i){
    if(isalpha(s[i])){
      temp += s[i];
    } else{
      sent += translateEnglishWord(temp);
      temp = s[i];
    }
  }
  sent += "\n";
  return sent;
}

// Default Destructor
Translator::~Translator(){
  // Nothing Needed
}
