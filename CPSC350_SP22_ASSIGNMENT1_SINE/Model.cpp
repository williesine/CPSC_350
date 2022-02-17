#include "Model.h"

// Default Constructor
Model::Model(){
  // Nothing Needed
}

/*
translateSingleCharacter() takes in a single char is param and returns a string representing
the tutnese translation of a single character
default case adds the char to an empty string and returns it to handle any non alphabetical chars
* I used a switch statment instead of if because of slight run-time benefits
*/
string Model::translateSingleCharacter(char c){
  //switch statement handles both upper and lower case
  // handles vowels/punctuation by adding it to empty string and returns the string
  string s = "";

  switch (c){
    case 'b':
    return "bub";

    case 'c':
    return "cash";

    case 'd':
    return "dud";

    case 'f':
    return "fuf";

    case 'g':
    return "gug";

    case 'h':
    return "hash";

    case 'j':
    return "jay";

    case 'k':
    return "kuck";

    case 'l':
    return "lul";

    case 'm':
    return "mum";

    case 'n':
    return "nun";

    case 'p':
    return "pub";

    case 'q':
    return "quack";

    case 'r':
    return "rug";

    case 's':
    return "sus";

    case 't':
    return "tut";

    case 'v':
    return "vuv";

    case 'w':
    return "wack";

    case 'x':
    return "ex";

    case 'y':
    return "yub";

    case 'z':
    return "zub";

    case 'B':
    return "Bub";

    case 'C':
    return "Cash";

    case 'D':
    return "Dud";

    case 'F':
    return "Fuf";

    case 'G':
    return "Gug";

    case 'H':
    return "Hash";

    case 'J':
    return "Jay";

    case 'K':
    return "Kuck";

    case 'L':
    return "Lul";

    case 'M':
    return "Mum";

    case 'N':
    return "Nun";

    case 'P':
    return "Pub";

    case 'Q':
    return "Quack";

    case 'R':
    return "Rug";

    case 'S':
    return "Sus";

    case 'T':
    return "Tut";

    case 'V':
    return "Vuv";

    case 'W':
    return "Wack";

    case 'X':
    return "Ex";

    case 'Y':
    return "Yub";

    case 'Z':
    return "Zub";

    default:
    s += c;
    return s;
  }
}


/*
translateDoubleCharacter() takes in a single char is param and returns a string representing
the tutnese translation of a double character
default case adds the char to an empty string and returns it to handle any non alphabetical chars
* I used a switch statment instead of if because of slight run-time benefits
*/
string Model::translateDoubleCharacter(char c){
  // still need to add the vowels
  string s = "";

  switch(c){
    case 'a':
    return "squata";

    case 'b':
    return "squabub";

    case 'c':
    return "squacash";

    case 'd':
    return "squadud";

    case 'e':
    return "squate";

    case 'f':
    return "squafuf";

    case 'g':
    return "squagug";

    case 'h':
    return "squahash";

    case 'i':
    return "squati";

    case 'j':
    return "squajay";

    case 'k':
    return "squakuck";

    case 'l':
    return "squalul";

    case 'm':
    return "squamum";

    case 'n':
    return "squanun";

    case 'o':
    return "squato";

    case 'p':
    return "squapub";

    case 'q':
    return "squaquack";

    case 'r':
    return "squarug";

    case 's':
    return "squasus";

    case 't':
    return "squatut";

    case 'u':
    return "squatu";

    case 'v':
    return "squavuv";

    case 'w':
    return "squawack";

    case 'x':
    return "squaex";

    case 'y':
    return "squayub";

    case 'z':
    return "squazub";

    case 'A':
    return "Squata";

    case 'B':
    return "Squabub";

    case 'C':
    return "Squacash";

    case 'D':
    return "Squadud";

    case 'E':
    return "Squate";

    case 'F':
    return "Squafuf";

    case 'G':
    return "Squagug";

    case 'H':
    return "Squahash";

    case 'I':
    return "Squati";

    case 'J':
    return "Squajay";

    case 'K':
    return "Squakuck";

    case 'L':
    return "Squalul";

    case 'M':
    return "Squamum";

    case 'N':
    return "Squanun";

    case 'O':
    return "Squato";

    case 'P':
    return "Squapub";

    case 'Q':
    return "Squaquack";

    case 'R':
    return "Squarug";

    case 'S':
    return "Squasus";

    case 'T':
    return "Squatut";

    case 'U':
    return "Squatu";

    case 'V':
    return "Squavuv";

    case 'W':
    return "Squawack";

    case 'X':
    return "Squaex";

    case 'Y':
    return "Squazub";

    case 'Z':
    return "Squazub";

    default:
    s += c;
    return s;
  }
}

// Default Destructor
Model::~Model(){
  // Nothing Needed
}
