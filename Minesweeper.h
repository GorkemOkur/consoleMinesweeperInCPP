#ifndef MINESWEEPER_H
#define MINESWEEPER_H

class Minesweeper{

    private:

    int row;
    int col;
    int totalMineCount;
    char** board;
    char** hiddenBoard;
    int opened;
    

    public:

    Minesweeper(int row, int col);

    int getRow();
    int getCol();
    int getTotalMineCount();

    void printBoard();
    void printHiddenBoard();

    void locateMines();

    void equalizeBoards();

    void calcMinesCountAround();

    int makeAMove(int r, int c);

    private:

    bool isExist(int r, int c);

    int calcMinesCountOfSquare(int r, int c);
    
};


#endif