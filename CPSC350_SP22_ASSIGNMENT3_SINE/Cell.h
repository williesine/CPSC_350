#ifndef CELL_H
#define CELL_H

#include <iostream>

using namespace std;

class Cell{
public:
  Cell();
  Cell(char c);
  void setState(char c);
  char getState();
  ~Cell();
  char nextGen(int neighbors);
  char m_state;
};

#endif
