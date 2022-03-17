#ifndef CLASSICMODE_H
#define CLASSICMODE_H

#include "Game.h"

class ClassicMode : public Game{
public:
  ClassicMode();
  ClassicMode(int rows, int columns, float density);
  ClassicMode(ifstream &inFS);
  ~ClassicMode();

  typedef Game super;

  void calcNextGen();

};

#endif
