#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include <cstdlib> // for system.pause()
#include <unistd.h>

class Game{
  protected:
    Board *m_currBoard;
    Board *m_nextBoard;

  public:
    Game();
    Game(int rows, int columns, float density);
    Game(ifstream &inFS);
    ~Game();

    void playGame(int result);
    void playGame(string fileName);

    virtual void calcNextGen(); // to be implemented within each sub other mode of the game.

};

#endif
