#include "Game.h"

Game::Game(){
  //default constructor
}

Game::Game(int rows, int columns, int density){
  m_currBoard = new Board(rows, columns, density);
  m_nextBoard = new Board(rows, columns); // uses basic board constructor
  m_prevBoard = new Board(rows, columns);
}

Game::Game(ifstream &inFS){
  
}
