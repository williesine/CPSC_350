#ifndef MIRRORMODE_H
#define MIRRORMODE_H

#include "Game.h"

class MirrorMode : public Game{
public:
  MirrorMode();
  MirrorMode(int rows, int columns, float density);
  MirrorMode(ifstream &inFS);
  ~MirrorMode();

  typedef Game super;

  void calcNextGen();

};

#endif
