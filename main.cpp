#include<iostream>
#include "Minesweeper.h"

using namespace std;

int main(){

    Minesweeper game1(5,5);

    cout<< game1.getRow() << endl;

    game1.printBoard();


    cout<<endl;

/*
    cout<<endl<<"\33[30m"<<"Some text and - - - -  0 1 2 3 4 5"<<"\033[0m";
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

    return 0;

}