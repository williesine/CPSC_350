#ifndef DONUTMODE_H
#define DONUTMODE_H

#include "Game.h"

class DonutMode : public Game{
public:
  DonutMode();
  DonutMode(int rows, int columns, float density);
  DonutMode(ifstream &inFS);
  ~DonutMode();

  typedef Game super;

  void calcNextGen();

};

#endif
