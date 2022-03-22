#include "ClassicMode.h"
#include "DonutMode.h"
#include "MirrorMode.h"

int main(int argc, char **argv){
  int mode, rows, cols, output, style;
  float density;
  string ifName, ofName;
  ifstream inFS;
  Game* game;

  // Gets the style of board implementation from user until user enters valid entry
  do{
    cout << "Please enter Board style: Type '1' for random configuration, or '2' for mapped out txt file: ";
    cin >> style;
  } while (style != 1 && style != 2);

  // Gets all necessary set up variables for game board based off of a random configuration
  if(style == 1){
    cout << "Please enter the number of rows: ";
    cin >> rows;
    cout << "Please enter the number of columns: ";
    cin >> cols;
    cout << "Please enter the population density (0-1): ";
    cin >> density;
  }else{

    // Sets up game board based on txt file
    // Ensures the file name exists and is valid
    while(true){
      cout << "Enter the name of file: ";
      cin >>ifName;

      inFS.open(ifName);
      if(inFS.is_open()){
        break;
      } else{
        cout << ifName << " is an invalid file name, please try again." << endl;
      }
    }
  }

  // Gets the chosen game mode from the user until the user enters a valid entry
  do{
    cout << "\nChoose a game mode: '1' for Classic, '2' for Mirror, '3' for Donut: ";
    cin >> mode;
  } while(mode != 1 && mode != 2 && mode != 3);

/*
if suite, sets up the game and board for random style of board implementation,
switches on mode variable, sets up board (although same for each) depending on game mode

Else suite: sets up game and board for a mapped out txt file style of board implementation
switches on mode variable, sets up board (although same across all game modes)
*/
  if(style == 1){
    switch(mode){
      case 1:
      game = new ClassicMode(rows, cols, density);
      break;
      case 2:
      game = new MirrorMode(rows,cols,density);
      break;
      case 3:
      game = new DonutMode(rows,cols,density);
      break;
    }
  }else{
    switch(mode){
      case 1:
      game = new ClassicMode(inFS);
      break;
      case 2:
      game = new MirrorMode(inFS);
      break;
      case 3:
      game = new DonutMode(inFS);
      break;
    }
  }

// Gets output choice from user, repeats until valid entry provided
  do{
    cout << "Choose output option: '1' Brief Pauses, '2' Press Enter, '3' Written to File: ";
    cin >> output;
  } while (output != 1 && output != 2 && output != 3);

  // handles the different game presentation styles based on input
  if(output == 3){
    cout << "Enter the output file name: ";
    cin >> ofName;

    game->playGame(ofName);
  } else {
    game->playGame(output);
  }

  delete game;
  return 0;
}
