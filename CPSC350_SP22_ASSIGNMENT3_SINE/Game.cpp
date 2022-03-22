#include "Game.h"

Game::Game(){}

/*
Overloaded constructor, takes in rows and columns as int, and pop
density as a float value, and instantiates two Boards, m_currBoard, or the current Game
board, and m_nextBoard which is the next board which will be used for calculating successive
generations
*/
Game::Game(int rows, int columns, float density){
  m_currBoard = new Board(rows, columns, density);
  m_nextBoard = new Board(rows, columns); // uses basic board constructor
}

/*
Overloaded constructor, takes a reference to an ifstream calls the proper Board constructor, reads
in the number of rows and columns, and also instantiates nextboard
*/
Game::Game(ifstream &inFS){
  m_currBoard = new Board(inFS);
  int rows = m_currBoard->getRows();
  int columns = m_currBoard->getColumns();

  m_nextBoard = new Board(rows,columns); //uses basic Board constructor
}

// Default destructor - deletes current and next boards
Game::~Game(){
  delete m_currBoard;
  delete m_nextBoard;
}

/*
playGame() - takes in an integer as input, which determines if the game will be delayed on a time basis
or by hitting enter in between generations, and also is responsible for enforcing the rules of the Simulation
uses while true loop & break to itreate through generations (and keeps track of gen number) until ending
conditions are met/satisfied
*/
void Game::playGame(int result){
  int genNumber = 0;

  cin.get(); // makes sure cin buffer is blank

  while(true){
    m_currBoard->printBoard(genNumber);
    if(result == 1){
      usleep(2000000); // Pauses 2 seconds between generations
    } else{
      cin.get(); // USER presses enter
    }

    calcNextGen();

    //Exits simulation if board is repeated concurrently or the current board becomes empty
    if(m_currBoard->isEqual(m_nextBoard) || m_currBoard->isEmpty()){
      break;
    }

    m_currBoard->copyBoard(m_nextBoard);
    ++genNumber;
  }
  cout << "Game of Life Over! Press Enter to exit the program." << endl;
  cin.get();
}

/*
playGame() - takes in a string representing a file name as parameter, and plays the game
and outputs the game to a specified file destination to be provided by the user
Uses the same logic as above method to execute the game until ending conditions have been met
*/
void Game::playGame(string fileName){
  int genNumber = 0;

  ofstream outFS;
  outFS.open(fileName);

  while(true){
    m_currBoard->printBoard(genNumber, outFS);
    calcNextGen();

    if(m_currBoard->isEqual(m_nextBoard) || m_currBoard->isEmpty()){
      break;
    }
    m_currBoard->copyBoard(m_nextBoard);
    ++genNumber;
  }
  outFS.close();

  cout << "Game of Life Over! Press Enter to exit the program." << endl;
  cin.get();
  cin.get();
}

// method to be overridden in the derived game mode classes
void Game::calcNextGen(){}
