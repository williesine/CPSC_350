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

void Cell::nextGen(){
  // change cell to the next generation (dead/alive)
  // based off conditions that are to be met later in program
}
