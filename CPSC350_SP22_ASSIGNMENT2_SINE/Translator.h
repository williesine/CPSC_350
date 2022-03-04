#include <string>
#include "Model.h"
#include <iostream>
using namespace std;

class Translator{
public:
  Translator();
  string translateEnglishWord(string w);
  string translateEnglishSentence(string s);
  string translateTutWord(string w);
  string translateTutSentence(string s);
  ~Translator();
};
