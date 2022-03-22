#include "Cell.h"

// default constructor - default cell value is dead ('-')
Cell::Cell(){
  m_state = '-';
}

// overloaded constructor: sets attribute (m_state) equal to parameter c
Cell::Cell(char c){
  m_state = c;
}

// mutator for state attribute
void Cell::setState(char c){
  m_state = c;
}

// Accessor for state attribute
char Cell::getState(){
  return m_state;
}

Cell::~Cell(){
  //default destructor
}

/*
nextGen(): takes the number of neighbors as int param, and returns
the state of the cell's next generation based on the number of neighbors
=>1 || <=4 --> cell dies, == 2 --> cell remains stable, == 3 --> cell will contain cell
*/
char Cell::nextGen(int neighbors){
  if(neighbors == 2){
    return m_state;
  } else if(neighbors == 3){
    return 'X';
  } else if(neighbors <=1 || neighbors >= 4){
    return '-';
  }
}
