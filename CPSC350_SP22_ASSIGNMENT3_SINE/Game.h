#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include <cstdlib> // for system.pause()

class Simulation{
  protected:
    Board *m_gameBoard;
    Board *m_nextBoard;
    Board *m_prevBoard;

  public:
    Game();
    Game(int rows, int columns, float density);
    Game(ifstream &inFS);
    ~Game();

    void playGame(int result);
    void playGame(ifstream &inFS);

    virtual void calcNextGen(); // to be implemented within each sub other mode of the game.

};

#endif
