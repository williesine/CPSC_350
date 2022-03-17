

#include <iostream>
using namespace std;

bool isEmpty(char** board, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(board[i][j] == 'X'){
                return false;
            }
        }
    }
    return true;
}

bool isFull(char** board, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(board[i][j] == '-'){
                return false;
            }
        }
    }
    return true;
}

char** initialize(char** board, int rows, int cols, double population){
    board = new char*[rows];
    for(int i = 0; i < rows; i++){
        board[i] = new char[cols];
    }

    int populationThreshold = population * 100; //truncate any decimal places

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            int life = rand() % 100 + 1;
            if(life <= populationThreshold){
                board[i][j] = 'X';
            }
            else{
                board[i][j] = '-';
            }

        }
    }
    return board;
}

void printBoard(char** board, int rowSize, int colSize){
    for(int i = 0; i < rowSize; i++){
        for(int j = 0; j < colSize; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int countClassic(char** board, int row, int col, int rowSize, int colSize){

    int neighbors = 0;
    int left = row - 1;
    int right = row + 1;
    int top = col - 1;
    int bottom = col + 1;

    //left
    if(left > 0){
        if(board[left][col] == 'X'){
            neighbors++;
        }
    }

    //top
    if(top > 0){
        if(board[row][top] == 'X'){
            neighbors++;
        }
    }

    //right
    if(right < rowSize){
        if(board[right][col] == 'X'){
            neighbors++;
        }
    }

    //bottom
    if(bottom < colSize){
        if(board[row][bottom] == 'X'){
            neighbors++;
        }
    }

    //upper left
    if(left > 0 && top > 0){
        if(board[left][top] == 'X'){
            neighbors++;
        }
    }

    //upper right
    if(right < rowSize && top > 0){
        if(board[right][top] == 'X'){
            neighbors++;
        }
    }

    //bottom left
    if(left > 0 && bottom < colSize){
        if(board[left][bottom] == 'X'){
            neighbors++;
        }
    }

    //bottom right
    if(right < rowSize && bottom < colSize){
        if(board[right][bottom] == 'X'){
            neighbors++;
        }
    }

    return neighbors;
}
int countDoughnut(char** board,int row, int col, int rowSize, int colSize){

    int neighbors = 0;

    int left = row - 1;
    int right = row + 1;
    int top = col - 1;
    int bottom = col + 1;

    //do wrap calculation
    if(left < 0){
        left = rowSize - 1;
    }
    if(right >= rowSize){
        right = 0;
    }
    if(top < 0){
        top = colSize - 1;
    }
    if(bottom >= colSize){
        bottom = 0;
    }


    //left
    if(board[left][col] == 'X'){
        neighbors++;
    }

    //top
    if(board[row][top] == 'X'){
        neighbors++;
    }


    //right
    if(board[right][col] == 'X'){
        neighbors++;
    }


    //bottom
    if(board[row][bottom] == 'X'){
        neighbors++;
    }

    //upper left
    if(board[left][top] == 'X'){
        neighbors++;
    }


    //upper right
    if(board[right][top] == 'X'){
        neighbors++;
    }


    //bottom left
    if(board[left][bottom] == 'X'){
        neighbors++;
    }


    //bottom right
    if(board[right][bottom] == 'X'){
        neighbors++;
    }


    return neighbors;

}
int countMirror(char** board,int row, int col, int rowSize, int colSize){
    int neighbors = 0;

    int left = row - 1;
    int right = row + 1;
    int top = col - 1;
    int bottom = col + 1;

    //do wrap calculation
    if(left < 0){
        left = row;
    }
    if(right >= rowSize){
        right = row;
    }
    if(top < 0){
        top = col;
    }
    if(bottom >= colSize){
        bottom = col;
    }


    //left
    if(board[left][col] == 'X'){
        neighbors++;
    }

    //top
    if(board[row][top] == 'X'){
        neighbors++;
    }


    //right
    if(board[right][col] == 'X'){
        neighbors++;
    }


    //bottom
    if(board[row][bottom] == 'X'){
        neighbors++;
    }

    //upper left
    if(board[left][top] == 'X'){
        neighbors++;
    }


    //upper right
    if(board[right][top] == 'X'){
        neighbors++;
    }


    //bottom left
    if(board[left][bottom] == 'X'){
        neighbors++;
    }


    //bottom right
    if(board[right][bottom] == 'X'){
        neighbors++;
    }


    return neighbors;

}


int countNeighbors(char** board,int row, int col, int gameMode, int rowSize, int colSize){
    if(gameMode == 0){ //classic
        return countClassic(board,row,col, rowSize, colSize);
    }
    else if(gameMode == 1){
        //doghnut
        return countDoughnut(board,row,col, rowSize, colSize);
    }
    else if(gameMode == 2){
        //doghnut
        return countMirror(board,row,col, rowSize, colSize);
    }
    else {
        cout << "Invalid game mode" << endl;
        return -1;
    }
}


int main() {
    //srand(10); //change 10 to time(NULL) for real random testing
    time(NULL);
    char yesBoard;

    cout << "Would you like to use a file for the board initialization? Y/y for yes any other key no" << endl;
    cin >>yesBoard;

    char** board;
    int rows = 4;
    int cols = 4;

    cout << "Please enter the population density as a decimal" << endl;
    double population;
    cin >> population;

    if(yesBoard == 'Y' || yesBoard == 'y'){
        //get file name
        //read in board and dynamically initialize board
        //make sure to set rows & cols
    }
    else{
        //make sure to set rows & cols
        board = initialize(board, rows, cols, population);
        printBoard(board, rows, cols);
    }



    //TODO ADD question for mirror and doughnut mode here
        //setting to classic for now

    int input = 0; //classic hardcoded




    //TODO enter vs system pause question

    int generationCount = 1;
    while(!isEmpty(board,rows,cols) && !isFull(board,rows,cols)){
        //initialize updated board to not have partially processed board interfering with processin rest of board for round
        char** updatedBoard = new char*[rows];
        for(int i = 0; i < rows; i++){
            updatedBoard[i] = new char[cols];
        }


        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                int neighbors = countNeighbors(board, i, j, input, rows, cols);
                //if is X and neghbors < 2 it dies, save - to updated
                // if(i==)

                if(board[i][j] == 'X' && neighbors < 2)
                {
                    updatedBoard[i][j] = '-';
                }

                //if has 2 neighbors, continue
                else if(neighbors == 2)
                {
                    updatedBoard[i][j] = board[i][j];
                }

                //if has 3 neighbors and is -, save x to updated
                else if(board[i][j] == '-' && neighbors == 3)
                {
                    updatedBoard[i][j] = 'X';
                }

                //if has 4+ neighbors save - to updated (if already dash doesnt matter)
                else if(neighbors >= 4)
                {
                    updatedBoard[i][j] = '-';
                }
                else if(neighbors >= 4 && neighbors <= 8){
                    updatedBoard[i][j] = '-';
                }
                else {
                    updatedBoard[i][j] = board[i][j];
                }


            }
        }
        board = updatedBoard; //put updated board layout into board for next go around
        cout << "----- GENERATION # " << generationCount << " -----" << endl;
        printBoard(board, rows, cols);
        cout << endl << endl;
        generationCount++;
        break;
    }


}
