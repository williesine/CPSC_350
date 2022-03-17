#include "Game.h"

Game::Game(){
  //default constructor
}

Game::Game(int rows, int columns, int density){
  m_gameBoard = new Board(rows, columns, density);
  m_nextBoard = new Board(rows, columns); // uses basic board constructor

}
