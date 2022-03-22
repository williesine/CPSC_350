#include "Board.h"

Board::Board(){
  //default
}

/*
Board Template Constructor: takes in rows and columns as parameters
this constructor is only used in order to make copies/outlines of boards
for keeping track of the current board and nextboard
*/
Board::Board(int rows, int columns){
  m_rows = rows;
  m_columns = columns;
  m_arr = new Cell*[m_rows];

  // creates 2D array
  for(int i = 0; i < m_rows; ++i){
    m_arr[i] = new Cell[m_columns];
    fill(m_arr[i], m_arr[i] + m_columns, Cell()); // fills array w/ default (dead) cells
  }
}

/*
Overloaded constructor takes in two ints (rows & cols) and a float
(population density) as parameters and sets the specified amount of alive cells
and fills the board appropriately
*/
Board::Board(int rows, int columns, float density){
  m_rows = rows;
  m_columns = columns;
  m_arr = new Cell*[m_rows];

  for(int i = 0; i < m_rows; ++i){
    m_arr[i] = new Cell[m_columns];
    fill(m_arr[i], m_arr[i] + m_columns, Cell()); //fills array w/ default (dead) cells
  }

  int total = (int) (m_rows * m_columns * density);
  int tracker = 0;

  while(tracker < total){
    // creates a random number between 0 and row/column length
    int x = ((int)(rand() % m_rows));
    int y = ((int)(rand() % m_columns));

    // sets randomized index to alive if not yet already
    if(m_arr[x][y].getState() != 'X')
      m_arr[x][y].setState('X');
      ++tracker;
  }
}

/*
Overloaded Constructor, takes in a ifstream reference as parameter
and instantiates a board based out of a mapped out txt file
*/
Board::Board(ifstream &inFS){
  string fCont;
  string out;

  inFS >> m_rows >> m_columns; //reads rows/columns

  m_arr = new Cell*[m_rows];
  for(int i = 0; i < m_rows; ++i){
    m_arr[i] = new Cell[m_columns];
    fill(m_arr[i], m_arr[i] + m_columns, Cell());
  }

  //sets all indecies to mapped out txt file
  for(int i = 0; i < m_rows; ++i){
    inFS >> fCont;
    for(int j = 0; j < m_columns; ++j){
      m_arr[i][j].setState(fCont[j]);
    }
  }
  inFS.close();
}


// Prints board to a specified file with a given generation number
void Board::printBoard(int gen, ofstream &outFS){
  outFS << "Generation #" << gen << endl;
  for(int r = 0; r < m_rows; ++r){
    for(int c = 0; c < m_columns; ++c){
      outFS << m_arr[r][c].getState();
    }
    outFS << endl;
  }
  outFS << endl;

}

// Prints board to standard console with a given generation number
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

//destructor
Board::~Board(){
  delete m_arr;
}

// getCell(): Accesses a Cell object given its row and column index from the board
Cell Board::getCell(int r, int c){
  return m_arr[r][c];
}

/*
setCell(): sets a cell at given row and column index to the same state as
the parameterized Cell using appropriate accessors/settors from other classes
*/
void Board::setCell(int r, int c, Cell cell){
  m_arr[r][c].setState(cell.getState());
}

// Copies/sets board --> used for copying next board to current game board
void Board::copyBoard(Board* arr){
  for(int r = 0; r < m_rows; ++r){
    for(int c = 0; c < m_columns; ++c){
      m_arr[r][c].setState(arr->getCell(r,c).getState());
    }
  }
}

/*
isEqual() takes a board pointing to an array as parameter and returns
true if the boards are equal (will exit program) or false if board are not equal
*/
bool Board::isEqual(Board* arr){
  for(int r = 0; r < m_rows; ++r){
    for(int c = 0; c < m_columns; ++c){
      if(m_arr[r][c].getState() != arr->getCell(r,c).getState()){
        return false;
      }
    }
  }
  return true;
}

/*
isEmpty() takes no params and returns a boolean true if board is empty, and false
if the board contains at least one cell
*/
bool Board::isEmpty(){
  for(int r = 0; r < m_rows; r++){
      for(int c = 0; c < m_columns; c++){
          if(m_arr[r][c].getState() == 'X'){
              return false;
          }
      }
  }
  return true;
}
