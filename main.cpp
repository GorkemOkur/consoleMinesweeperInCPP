#include<iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>


#include "Minesweeper.h"

using namespace std;

int main(){


    Minesweeper game1(5,5);

    cout<<"\t\33[31m------------------------:::\33[33mEmpty BOARDS\033[0m\33[31m:::------------------------\033[0m";
    game1.printBoard();
    game1.printHiddenBoard();

    game1.locateMines();

    cout<<"\t\33[31m------------------------:::\033[0m\33[33mAFTER MİNES LOCATED AND CALCULATED BOARDS\033[0m\33[31m:::------------------------\033[0m";
    game1.calcMinesCountAround();
    game1.printBoard();
    game1.printHiddenBoard();

    int con = 0;
    int r, c;

    while (con != -1){    

        cout<<"Please, enter the row: ";cin>>r;
        cout<<"Please, enter the col: ";cin>>c;

        con = game1.makeAMove(r,c);

        cout<<endl;

    }
    



    return 0;

}



/*  cout<<endl<<"\33[30m"<<"Some text and - - - -  0 1 2 3 4 5"<<"\033[0m";
    cout<<endl<<"\33[30m"<<"Some text and - - - -  0 1 2 3 4 5"<<"\033[0m";

    cout<<endl<<"\33[31m"<<"Some text and - - - -  0 1 2 3 4 5"<<"\033[0m";
    cout<<endl<<"\33[31m"<<"Some text and - - - -  0 1 2 3 4 5"<<"\033[0m";

    cout<<endl<<"\33[32m"<<"Some text and - - - -  0 1 2 3 4 5"<<"\033[0m";
    cout<<endl<<"\33[32m"<<"Some text and - - - -  0 1 2 3 4 5"<<"\033[0m";

    cout<<endl<<"\33[33m"<<"Some text and - - - -  0 1 2 3 4 5"<<"\033[0m";
    cout<<endl<<"\33[33m"<<"Some text and - - - -  0 1 2 3 4 5"<<"\033[0m";

    cout<<endl<<"\33[34m"<<"Some text and - - - -  0 1 2 3 4 5"<<"\033[0m";
    cout<<endl<<"\33[34m"<<"Some text and - - - -  0 1 2 3 4 5"<<"\033[0m";

    cout<<endl<<"\33[35m"<<"Some text and - - - -  0 1 2 3 4 5"<<"\033[0m";
    cout<<endl<<"\33[35m"<<"Some text and - - - -  0 1 2 3 4 5"<<"\033[0m";

    cout<<endl<<"\33[36m"<<"Some text and - - - -  0 1 2 3 4 5"<<"\033[0m";
    cout<<endl<<"\33[36m"<<"Some text and - - - -  0 1 2 3 4 5"<<"\033[0m";

    cout<<endl<<"\33[37m"<<"Some text and - - - -  0 1 2 3 4 5"<<"\033[0m";
    cout<<endl<<"\33[37m"<<"Some text and - - - -  0 1 2 3 4 5"<<"\033[0m";

    cout<<endl<<"\33[38m"<<"Some text and - - - -  0 1 2 3 4 5"<<"\033[0m";
    cout<<endl<<"\33[38m"<<"Some text and - - - -  0 1 2 3 4 5"<<"\033[0m";

    cout<<endl<<"\33[39m"<<"Some text and - - - -  0 1 2 3 4 5"<<"\033[0m";
    cout<<endl<<"\33[39m"<<"Some text and - - - -  0 1 2 3 4 5"<<"\033[0m";*/