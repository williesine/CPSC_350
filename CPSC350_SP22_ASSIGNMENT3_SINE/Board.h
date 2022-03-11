#ifndef BOARD_H
#define BOARD_H

#include <fstream>
#include "Cell.h"

class Board{
private:
  Cell **m_arr;
  int m_rows;
  int m_columns;

public:
  Board();//default
  Board(int rows, int columns);//txt file
  Board(int rows, int columns, float density);//user input
  Board(ifstream &inFS);

  ~Board();


};
