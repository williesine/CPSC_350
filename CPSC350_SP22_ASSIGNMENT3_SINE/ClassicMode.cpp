#include "ClassicMode.h"

ClassicMode::ClassicMode(){}

ClassicMode::ClassicMode(int rows, int columns, float density) : super(rows, columns, density){}

ClassicMode::ClassicMode(ifstream &inFS) : super(inFS){}

ClassicMode::~ClassicMode(){}

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
      m_nextBoard->setCell(r,c,Cell(m_currBoard->getCell(r,c).calcNextGen(neighbors)));
    }
  }
}

int main(){
  return 0;
}
