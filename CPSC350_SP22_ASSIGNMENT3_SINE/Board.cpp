#include "Board.h"

Board::Board(){
  //default
}

// for making copies of future and previous game boards
Board::Board(int rows, int columns){
  m_rows = rows;
  m_columns = columns;
  m_arr = new Cell*[m_rows];

  for(int i = 0; i < m_rows; ++i){
    m_arr[i] = new Cell[m_columns];
    fill(m_arr[i], m_arr[i] + m_columns, Cell()); //FIXME understand this line
  }
}

//initializing new gameboard from random density
Board::Board(int rows, int columns, float density){
  m_rows = rows;
  m_columns = columns;
  m_arr = new Cell*[m_rows];

  int total = (m_rows * m_columns * density);
  int tracker = 0;

  while(tracker < total){
    int x = ((int)(rand() % m_rows);
    int y = ((int)(rand() % m_columns);

    if(m_arr[x][y].getState() != 'X')
      m_arr[x][y].setState('X');
      tracker++;
  }
}

Board::Board(ifstream &inFS){
  string fCont
  string out;

  inFS >> m_rows >> m_columns; //reads rows/columns

  m_arr = new Cell*[m_rows];
  for(int i = 0; i < m_rows; ++i){
    m_arr[i] = new Cell[m_columns];
    fill(m_arr[i], m_arr[i] + m_columnns, Cell());
  }

  for(int i = 0; i < m_rows; ++i){
    inFS >> fCont;
    for(int j = 0; j < m_columns, ++j){
      m_arr[i][j].setState(fCont[j]);
    }
  }
  inFS.close();
}
//
void Board::printBoard(int gen, ifstream &outFS){


}

void Board::printBoard(int gen){
  cout << "GENERATION: " << gen << endl;
  for(int i = 0; i < m_rows ; ++i){
    for(int j = 0; j < m_columns; ++j){
      cout << m_arr[i][j].getState() << " ";
    }
    cout << endl;
  }
}


// accessors for rows/columns
int Board::getRows(){
  return m_rows;
}
int Board::getColumns(){
  return m_columns;
}

Board::~Board(){
  delete m_arr;
}

Cell Board::getCell(int r, int c){
  return m_arr[r][c];
}

void Board::setCell(int r, int c, Cell cell){
  m_arr[x][y].setState(cell.getState());
}

bool Board::isEmpty(){
  for(int i = 0; i < m_rows; i++){
      for(int j = 0; j < m_columns; j++){
          if(m_arr[i][j].getState() == "X"){
              return false;
          }
      }
  }
  return true;
}

bool isFull(){
    for(int i = 0; i < m_rows; i++){
        for(int j = 0; j < m_columns; j++){
            if(board[i][j] == '-'){
                return false;
            }
        }
    }
    return true;
}
