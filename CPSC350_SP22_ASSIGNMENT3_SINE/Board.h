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

  void printBoard(int gen, outstream &outFS); // TO OUTPUT FILE, generation number
  void printBoard(int gen); // TO TERMINAL
  void copyBoard(Board* arr);
  bool isEmpty();
  bool isFull();

  int getRows();
  int getColumns();
  Cell getCell(int r, int c);
  void setCell(int r, int c, Cell cell);

};

#endif
