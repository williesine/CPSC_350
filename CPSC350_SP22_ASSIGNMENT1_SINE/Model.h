#include <string>
#include <iostream>
using namespace std;

class Model{
public:
  Model();
  string translateSingleCharacter(char);
  string translateDoubleCharacter(char); // must check for back to back letters
  ~Model();
};
