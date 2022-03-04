#include "Model.h"


Model::Model(){
  // Default Constructor
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


/*
translateTutCharacter() takes in a string representing a letter, but in tut,
if statement checks all possible chars (vowels, doubles, etc...) and return the english translation
checks for every type of alphabetical outcome, so the else suite will only return
spaces, punctuation, etc...
*/
string Model::translateTutCharacter(string s){
  if(s == "a"){
    return "a";
  } else if(s == "bub"){
    return "b";
  } else if(s == "cash"){
    return "c";
  } else if(s == "dud"){
    return "d";
  } else if(s == "e"){
    return "e";
  }  else if(s == "fuf"){
    return "f";
  } else if(s == "gug"){
    return "g";
  } else if(s == "hash"){
    return "h";
  } else if(s == "i"){
    return "i";
  } else if(s == "jay"){
    return "j";
  } else if(s == "kuck"){
    return "k";
  } else if(s == "lul"){
    return "l";
  } else if(s == "mum"){
    return "m";
  } else if(s == "nun"){
    return "n";
  } else if(s == "o"){
    return "o";
  } else if(s == "pub"){
    return "p";
  } else if(s == "quack"){
    return "q";
  } else if(s == "rug"){
    return "r";
  } else if(s == "sus"){
    return "s";
  } else if(s == "tut"){
    return "t";
  } else if(s == "u"){
    return "u";
  } else if(s == "vuv"){
    return "v";
  } else if(s == "wack"){
    return "w";
  } else if(s == "ex"){
    return "x";
  } else if(s == "yub"){
    return "y";
  } else if(s == "zub"){
    return "z";
  } else if(s == "A"){
    return "A";
  } else if(s == "Bub"){
    return "B";
  } else if(s == "Cash"){
    return "C";
  } else if(s == "Dud"){
    return "D";
  } else if(s == "E"){
    return "E";
  } else if(s == "Fuf"){
    return "F";
  } else if(s == "Gug"){
    return "G";
  } else if(s == "Hash"){
    return "H";
  } else if(s == "I"){
    return "I";
  }else if(s == "Jay"){
    return "J";
  } else if(s == "Kuck"){
    return "K";
  } else if(s == "Lul"){
    return "L";
  } else if(s == "Mum"){
    return "M";
  } else if(s == "Nun"){
    return "N";
  } else if(s == "O"){
    return "O";
  } else if(s == "Pub"){
    return "P";
  } else if(s == "Quack"){
    return "Q";
  } else if(s == "Rug"){
    return "R";
  } else if(s == "Sus"){
    return "S";
  } else if(s == "Tut"){
    return "T";
  } else if(s == "U"){
    return "U";
  } else if(s == "Vuv"){
    return "V";
  } else if(s == "Ex"){
    return "X";
  } else if(s == "Yub"){
    return "Y";
  } else if(s == "Zub"){
    return "Z";
  } else if(s == "squata"){
    return "aa";
  } else if(s == "squabub"){
    return "bb";
  } else if(s == "squacash"){
    return "cc";
  } else if(s == "squadud"){
    return "dd";
  } else if(s == "squate"){
    return "ee";
  } else if(s == "squafuf"){
    return "ff";
  } else if(s == "squagug"){
    return "gg";
  } else if(s == "squahash"){
    return "hh";
  } else if(s == "squati"){
    return "ii";
  } else if(s == "squajay"){
    return "jj";
  } else if(s == "squakuck"){
    return "kk";
  } else if(s == "squalul"){
    return "ll";
  } else if(s == "squamum"){
    return "mm";
  } else if(s == "squanun"){
    return "nn";
  } else if(s == "squato"){
    return "oo";
  } else if(s == "squapub"){
    return "pp";
  } else if(s == "squaquack"){
    return "qq";
  } else if(s == "squarug"){
    return "rr";
  } else if(s == "squasus"){
    return "ss";
  } else if(s == "squatut"){
    return "tt";
  } else if(s == "squatu"){
    return "uu";
  } else if(s == "squavuv"){
    return "vv";
  } else if(s == "squawack"){
    return "ww";
  } else if(s == "squaex"){
    return "xx";
  } else if(s == "squayub"){
    return "yy";
  } else if(s == "squazub"){
    return "zz";
  } else if(s == "Squata"){
    return "Aa";
  } else if(s == "Squabub"){
    return "Bb";
  } else if(s == "Squacash"){
    return "Cc";
  } else if(s == "Squadud"){
    return "Dd";
  } else if(s == "Squate"){
    return "Ee";
  } else if(s == "Squafuf"){
    return "Ff";
  } else if(s == "Squagug"){
    return "Gg";
  } else if(s == "Squahash"){
    return "Hh";
  } else if(s == "Squati"){
    return "Ii";
  }else if(s == "Squajay"){
    return "Jj";
  } else if(s == "Squakuck"){
    return "Kk";
  } else if(s == "Squalul"){
    return "Ll";
  } else if(s == "Squamum"){
    return "Mm";
  } else if(s == "Squanun"){
    return "Nn";
  } else if(s == "Squato"){
    return "Oo";
  } else if(s == "Squapub"){
    return "Pp";
  } else if(s == "Squaquack"){
    return "Qq";
  } else if(s == "Squarug"){
    return "Rr";
  } else if(s == "Squasus"){
    return "Ss";
  } else if(s == "Squatut"){
    return "Tt";
  } else if(s == "Squatu"){
    return "Uu";
  } else if(s == "Squavuv"){
    return "Vv";
  } else if(s == "Squaex"){
    return "Xx";
  } else if(s == "Squayub"){
    return "Yy";
  } else if(s == "Squazub"){
    return "Zz";
  }
}



Model::~Model(){
  // Default Destructor
}
