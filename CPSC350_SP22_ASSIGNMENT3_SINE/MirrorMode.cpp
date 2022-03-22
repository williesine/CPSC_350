#include "MirrorMode.h"

// Default Constructor
MirrorMode::MirrorMode(){}

// Overloaded constructor, uses base class instantiation for random board configuration
MirrorMode::MirrorMode(int rows, int columns, float density) : super(rows,columns,density){}

// Overloaded Constructor, uses base class instantiation for mapped text file configuration
MirrorMode::MirrorMode(ifstream &inFS) : super(inFS){}

// default destructor
MirrorMode::~MirrorMode(){}

/*
calcNextGen(): is the method that is responsible for calculating succeeding generations
The first two nested for loops to iterate through the entire board, while the inner nested
loops iterate through all possible neighbor locations, because of special neighbor rules,
variable x and y are used to translate out of bound indecies into valid arguments if need be
*/
void MirrorMode::calcNextGen(){
  int neighbors;
  int rows = m_currBoard->getRows();
  int cols = m_currBoard->getColumns();

  for(int r = 0; r < rows; ++r){
    for(int c = 0; c < cols; ++c){

      for(int i = r-1; i <= r+1; ++r){
        for(int j = c-1; j <= c+1; ++c){
          int x,y;

          if(r==i && c == j){
            continue;
          }


          if(i < 0 || i >= rows){
            x = r;
          } else{
            x = i;
          }

          if(j < 0 || j >= cols){
            y = c;
          } else{
            y = j;
          }

          if(m_currBoard->getCell(x,y).getState() == 'X'){
            ++neighbors;
          }
        }
      }
      // Calculates the cell's next generation using appropriate methods and adds it to next board
      m_nextBoard->setCell(r,c,Cell(m_currBoard->getCell(r,c).nextGen(neighbors)));
    }
  }
}
