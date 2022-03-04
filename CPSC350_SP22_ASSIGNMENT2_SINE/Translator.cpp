#include "Translator.h"


Translator::Translator(){
  // Default Constructor
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
translateTutWord() takes in a string representing a tutnese word
because tutnese letters are all different lengths, I made substrings of all
possible tutnese letter lengths and checked them against the substrings
ret_str is the return string from m.translateTutCharacter(), if it's equal to the
substring (tmp), it will continue until it finds its' Tut translation
However, I'm pretty sure this is where the error arises.
*/
string Translator::translateTutWord(string w){
  int i = 0;
  string ret = "";
  Model m;
  while(i < w.size()){
    string ret_str = "";
    string tmp = w.substr(i,2);
    ret_str = m.translateTutCharacter(tmp);
    if(ret_str == tmp){
      ret_str = "";
    } else{
      ret += ret_str;
      i+=2;
      continue;
    }

    // looks for substrings w length 3
    tmp = w.substr(i,3);
    ret_str = m.translateTutCharacter(tmp);
    if(ret_str == tmp){
      ret_str = "";
    } else{
      ret+=ret_str;
      i+=3;
      continue;
    }

    // looks for substrings w length 4
    tmp = w.substr(i,4);
    ret_str = m.translateTutCharacter(tmp);
    if(ret_str == tmp){
      ret_str = "";
    } else{
      ret += ret_str;
      i+=4;
      continue;
    }

    // looks for substrings w length 5
    tmp = w.substr(i,5);
    ret_str = m.translateTutCharacter(tmp);
    if(ret_str == tmp){
      ret_str = "";
    } else{
      ret += ret_str;
      i+=5;
      continue;
    }

    // looks for substrings w length 6
    tmp = w.substr(i,6);
    ret_str = m.translateTutCharacter(tmp);
    if(ret_str == tmp){
      ret_str = "";
    } else{
      ret += ret_str;
      i+=6;
      continue;
    }

    // looks for substrings w length 7
    tmp = "";
    tmp = w.substr(i,7);
    ret_str = m.translateTutCharacter(tmp);
    if(ret_str == tmp){
      ret_str = "";
    } else{
      ret += ret_str;
      i+=7;
      continue;
    }

    // looks for substrings w length 8
    tmp = "";
    tmp = w.substr(i,8);
    ret_str = m.translateTutCharacter(tmp);
    if(ret_str == tmp){
      ret_str = "";
    } else{
      ret += ret_str;
      i+=8;
      continue;
    }

    // looks for substrings w length 9
    tmp = "";
    tmp = w.substr(i,9);
    ret_str = m.translateTutCharacter(tmp);
    if(ret_str == tmp){
      ret_str = "";
    } else{
      ret += ret_str;
      i+=9;
      continue;
    }

  }
  return ret;
}

/*
translateEnglishSentence() takes in a string representing a sentence
found isalpha() from STL, returns 0 if non-alphabetical, returns 1 if char is alphabetical
add a newline char at the end of the sentence to maintain the spacing from original ifile
*/
string Translator::translateEnglishSentence(string s){
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

/*
translateTutSentence() takes in a string representing a tut sentence
iterates through the string, adds to tmp string while the characters
in the string are alphabetical (space, punctuation, etc...), if not,
the else suite translates the word using translateTutWord() and continues
translating.
*/
string Translator::translateTutSentence(string s){
  string sent = "";
  string tmp = "";
  for(int i = 0; i < s.size(); ++i){
    if(isalpha(s[i])){
      tmp += s[i];
    } else{
      sent += translateTutWord(tmp);
      tmp = s[i];
    }
  }
  sent += "\n";
  return sent;
}

// Default Destructor
Translator::~Translator(){
  // Nothing Needed
}
