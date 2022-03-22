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
  Board(int rows, int columns);
  Board(int rows, int columns, float density);//user input
  Board(ifstream &inFS); //txt file
  ~Board();

  void printBoard(int gen, ofstream &outFS); // TO OUTPUT FILE, generation number
  void printBoard(int gen); // TO TERMINAL
  void copyBoard(Board* arr);
  bool isEmpty();
  bool isEqual(Board* arr);

  int getRows();
  int getColumns();
  Cell getCell(int r, int c); // returns cell at specified index
  void setCell(int r, int c, Cell cell); // sets cell at specified index

};

#endif
