#include "Cell.h"

Cell::Cell(){
  m_state = "-";
}

Cell::Cell(char c){
  m_state = c;
}

void Cell::setState(char c){
  m_state = c;
}

char Cell::getState(){
  return m_state;
}

Cell::~Cell(){
  //default destructor
}

char Cell::nextGen(int neighbors){
  if(neighbors == 2){
    return m_state;
  } else if(neighbors == 3){
    return 'X';
  } else if(neighbors <=1 || neighbors >= 4){
    return '-';
  }
}
