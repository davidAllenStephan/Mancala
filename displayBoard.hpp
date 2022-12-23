#include <iostream>
#include <stdlib.h>
#include "formats/formatIntegerToString.hpp"
using namespace std;
int displayBoard(int playerBoard[2][6], int playerStore[2])
{
    system("clear");
    cout << "███████████████████████████████████████████████████\n";
    cout << "██████████6█████5█████4█████3█████2█████1██████████\n";
    cout << "███████████████████████████████████████████████████\n";
    cout << "███   ███   ███   ███   ███   ███   ███   ███   ███\n";
    cout << "███   ███";
    getString(playerBoard[0][5]);
    cout << "███";
    getString(playerBoard[0][4]);
    cout << "███";
    getString(playerBoard[0][3]);
    cout << "███";
    getString(playerBoard[0][2]);
    cout << "███";
    getString(playerBoard[0][1]);
    cout << "███";
    getString(playerBoard[0][0]);
    cout << "███   ███\n";
    cout << "███   ███   ███   ███   ███   ███   ███   ███   ███\n";
    cout << "███";
    getString(playerStore[0]);
    cout << "███████████████████████████████████████";
    getString(playerStore[1]);
    cout << "███\n";
    cout << "███   ███   ███   ███   ███   ███   ███   ███   ███\n";
    cout << "███   ███";
    getString(playerBoard[1][0]);
    cout << "███";
    getString(playerBoard[1][1]);
    cout << "███";
    getString(playerBoard[1][2]);
    cout << "███";
    getString(playerBoard[1][3]);
    cout << "███";
    getString(playerBoard[1][4]);
    cout << "███";
    getString(playerBoard[1][5]);
    cout << "███   ███\n";
    cout << "███   ███   ███   ███   ███   ███   ███   ███   ███\n";
    cout << "███████████████████████████████████████████████████\n";
    cout << "██████████1█████2█████3█████4█████5█████6██████████\n";
    cout << "███████████████████████████████████████████████████\n";

    return 0;
}