#include "Minesweeper.h"
//#include <stdlib.h>     /* srand, rand */
//#include <time.h>       /* time */
#include <cstring>

Minesweeper::Minesweeper(int row, int col){
    
    this->row = row;
    this->col = col;
    this->opened = 0;
    
    // calculate Total number of Mines.
        row * col < 7   ?    totalMineCount = 2
                        :    row * col < 10         ?   totalMineCount = 3
                                                    :   totalMineCount = (int)(round( sqrt(row * col)+0.5 ) );

    board = new char*[row];
    for (int i = 0; i < row; i++)
        board[i] = new char[col];

    hiddenBoard = new char*[row];
    for (int i = 0; i < row; i++)
        hiddenBoard[i] = new char[col];
    
    for (int i = 0; i < row ; i++)
        for (int j = 0; j < col; j++)
            board[i][j] = '-';
    
    equalizeBoards();
}

int Minesweeper::getRow(){return row;}
int Minesweeper::getCol(){return col;}
int Minesweeper::getTotalMineCount(){return totalMineCount;}


void Minesweeper::printBoard(){
    
    cout<<"\033[31m"<<endl;

        for(int i = 0; i < row ;i++){
            for(int j = 0; j < col ; j++){
                cout<<"\33[40m";
                if( board[i][j] == '-' )
                    cout<<"\33[37m"<< ( j && j != col ? " " : "" ) <<"- ";

                else if( board[i][j] == '*' )
                    cout<<"\33[101m\e[01m"<< ( j && j != col ? " " : "" ) <<board[i][j]<<" "<<"\e[0m";

                else if( board[i][j] == '1' )
                    cout<<"\33[34m\e[01m"<< ( j && j != col ? " " : "" ) <<board[i][j]<<" "<<"\e[0m";

                else if( board[i][j] == '2' )
                    cout<<"\33[32m\e[01m"<< ( j && j != col ? " " : "" ) <<board[i][j]<<" "<<"\e[0m";

                else if( board[i][j] == '3' )
                    cout<<"\33[31m\e[01m"<< ( j && j != col ? " " : "" ) <<board[i][j]<<" "<<"\e[0m";

                else
                    cout<<"\33[35m\e[01m"<< ( j && j != col ? " " : "" ) <<board[i][j]<<" "<<"\e[0m";
            }
            cout<<"\n";
        }
    cout<<endl<<"\033[0m";

}


bool Minesweeper::isExist(int r, int c){
    return board[r][c] == '*';
}

void Minesweeper::locateMines(){

    srand(time(0));

    int r,c;

    for(int i = 0 ; i < this->totalMineCount ;){
        r = rand() % row;
        c = rand() % col;

        if(!isExist(r,c)){
            hiddenBoard[r][c] = '*';
            i++;
        }
    }
}


void Minesweeper::equalizeBoards(){
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            hiddenBoard[i][j] = board[i][j];
}

void Minesweeper::printHiddenBoard(){

    cout<<"\033[31m"<<endl;

        for(int i = 0; i < row ;i++){
            for(int j = 0; j < col ; j++){
                cout<<"\33[40m";
                if( hiddenBoard[i][j] == '-' )
                    cout<<"\33[37m"<< ( j && j != col ? " " : "" ) <<"- ";

                else if( hiddenBoard[i][j] == '*' )
                    cout<<"\33[101m\e[01m"<< ( j && j != col ? " " : "" ) <<hiddenBoard[i][j]<<" "<<"\e[0m";

                else if( hiddenBoard[i][j] == '1' )
                    cout<<"\33[34m\e[01m"<< ( j && j != col ? " " : "" ) <<hiddenBoard[i][j]<<" "<<"\e[0m";

                else if( hiddenBoard[i][j] == '2' )
                    cout<<"\33[32m\e[01m"<< ( j && j != col ? " " : "" ) <<hiddenBoard[i][j]<<" "<<"\e[0m";

                else if( hiddenBoard[i][j] == '3' )
                    cout<<"\33[31m\e[01m"<< ( j && j != col ? " " : "" ) <<hiddenBoard[i][j]<<" "<<"\e[0m";

                else
                    cout<<"\33[35m\e[01m"<< ( j && j != col ? " " : "" ) <<hiddenBoard[i][j]<<" "<<"\e[0m";
            }
            cout<<"\n";
        }
    cout<<endl<<"\033[0m";
}


int Minesweeper::calcMinesCountOfSquare(int r, int c){
    int count = 0;

    //top
    count += r-1 >= 0   && hiddenBoard[r-1][c] == '*' ? 1 : 0;

    //right
    count += c+1 < col  && hiddenBoard[r][c+1] == '*' ? 1 : 0;

    //bottom
    count += r+1 < row  && hiddenBoard[r+1][c] == '*' ? 1 : 0;

    //left
    count += c-1 >= 0   && hiddenBoard[r][c-1] == '*' ? 1 : 0;

    //top - left
    count += r-1 >= 0   && c-1 >= 0     && hiddenBoard[r-1][c-1] == '*' ? 1 : 0;

    //top - right
    count += r-1 >= 0   && c+1 < col    && hiddenBoard[r-1][c+1] == '*' ? 1 : 0;

    //bottom - left
    count += r+1 < row  && c-1 >= 0     && hiddenBoard[r+1][c-1] == '*' ? 1 : 0;

    //bottom - right
    count += r+1 < row  && c+1 < col    && hiddenBoard[r+1][c+1] == '*' ? 1 : 0;

    return count;
}

void Minesweeper::calcMinesCountAround(){
    for(int i = 0; i < row ;i++)
        for(int j = 0; j < col ;j++){
            if(hiddenBoard[i][j] != '*')
                hiddenBoard[i][j] = '0' + calcMinesCountOfSquare(i,j);
        }
}


int Minesweeper::makeAMove(int r, int c){

    if ( r > row || r < 0 || c > col || c < 0 )
        return 0;

    if(hiddenBoard[r][c] == '*'){
        cout<<"\t\33[31m------------------------:::\33[33mYou LOSE\033[0m\33[31m:::------------------------\033[0m";
        printHiddenBoard();
        return -1;

    }else{

        if(board[r][c] == '-'){
            opened++;
        }

        if(opened + totalMineCount == row * col ){
            cout<<"\t\33[31m------------------------:::\33[33mYou Win\033[0m\33[31m:::------------------------\033[0m";
            printHiddenBoard();
            return -1;
        }

        cout<<"Opened: "<<opened;
        strncpy ( &board[r][c], &hiddenBoard[r][c], sizeof(hiddenBoard[r][c]) );
        printBoard();

    }
}