#include<iostream>
#include <stdio.h>


class Board{

    private:

    int row;
    int col;
    char** board;


    public:

    Board(int row=0, int col=0){
        this->row = row;
        this->col = col;
        std::cout<<"Board Constructor\n";
        initBoard();
    }

    void init(int row, int col){
        this->row = row;
        this->col = col;
        std::cout<<"Board Constructor\n";
        initBoard();
    }

    void initBoard(){
        board = new char*[row];
        for(int i=0; i < row ;i++)
            board[i] = new char[col];

        for(int i = 0; i < row ; i++)
            for(int j = 0; j < col ; j++)
                board[i][j] = '-';
    }

    void setRow(int row){
        this->row = row;
    }

    int getRow(){
        return this->row;
    }

    void setCol(int col){
        this->col = col;
    }

    int getCol(){
        return this->col;
    }

    char** getBoard(){
        return this->board;
    }

    void printGameBoard(){

        board[1][3] = '1';
        board[3][2] = '1';
        board[0][4] = '2';
        board[3][1] = '3';

        board[1][1] = '5';

        std::cout<<"\033[31m";
        for(int i = 0; i < row ;i++){
            for(int j = 0; j < col ; j++){
                std::cout<<"\33[40m";
                if( board[i][j] == '-' )
                    std::cout<<"\33[37m"<< ( j && j != col ? " " : "" ) <<board[i][j];

                else if( board[i][j] == '1' )
                    std::cout<<"\33[34m\e[01m"<< ( j && j != col ? " " : "" ) <<board[i][j]<<"\e[0m";

                else if( board[i][j] == '2' )
                    std::cout<<"\33[32m\e[01m"<< ( j && j != col ? " " : "" ) <<board[i][j]<<"\e[0m";

                else if( board[i][j] == '3' )
                    std::cout<<"\33[31m\e[01m"<< ( j && j != col ? " " : "" ) <<board[i][j]<<"\e[0m";

                else
                    std::cout<<"\33[35m\e[01m"<< ( j && j != col ? " " : "" ) <<board[i][j]<<"\e[0m";
            }

                
            std::cout<<"\n";
        }
        std::cout<<"\033[0m";
    }

};


//Basic Print
//std::cout<< (board[i][j] == '-' && j != 0 ? " " : "") << board[i][j] << (board[i][j] == '-' ? " " : "");
//std::cout<< (board[i][j] == '-' && j ? " " : "") << board[i][j] << (board[i][j] == '-' ? " " : "");