#include "ClassicMode.h"

// Default Constructor
ClassicMode::ClassicMode(){}

// // Overloaded constructor, uses base class instantiation for random board configuration
ClassicMode::ClassicMode(int rows, int columns, float density) : super(rows, columns, density){}

// Overloaded constructor, uses base class instantiation for mapped text file configuration
ClassicMode::ClassicMode(ifstream &inFS) : super(inFS){}

// default destructor
ClassicMode::~ClassicMode(){}

/*
calcNextGen(): is the method that is responsible for calculating succeeding generations
The first two nested for loops to iterate through the entire board, while the inner nested
loops iterate through all possible neighbor locations and increment neighbors if a neighbor has been
found, last line calls appropriate methods from other classes to set the cells next gen
*/
void ClassicMode::calcNextGen(){
  int neighbors;
  int rows = m_currBoard->getRows();
  int cols = m_currBoard->getColumns();

  //iterates through each cell
  for(int r = 0; r < rows; ++r){
    for(int c = 0; c < cols; ++c){
      neighbors = 0;

      //iterates through neighbors @ cell
      for(int i = r - 1; i <= r + 1; ++i){
        for(int j = c - 1; j <= c + 1; ++j){

          //makes sure doesn't count self
          if(r==i && c == j){
            continue;
          }

          //checks to make sure neighbors are within array bounds
          if(i >= 0 && r < rows && j >= 0 && c < cols){
            if(m_currBoard->getCell(i,j).getState() == 'X'){
              ++neighbors;
            }
          }
        }
      }
      // Calculates the cell's next generation using appropriate methods and adds it to next board
      m_nextBoard->setCell(r,c,Cell(m_currBoard->getCell(r,c).nextGen(neighbors)));
    }
  }
}
