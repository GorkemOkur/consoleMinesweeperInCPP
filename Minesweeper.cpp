#include "Minesweeper.h"

Minesweeper::Minesweeper(int row, int col){
    this->board = Board(row, col);
}

int Minesweeper::getRow(){
    return this->board.getRow();
}

void Minesweeper::printBoard(){
    this->board.printGameBoard();
}