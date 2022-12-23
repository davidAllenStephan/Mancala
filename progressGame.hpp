
#include "sets/setArrayMove.hpp"
#include <iostream>

using namespace std;

int progressGame(int selectedSpace, int playerTurn, int playerBoard[2][6], int playerStore[2])
{
    int moveCount = playerBoard[playerTurn][selectedSpace];
    if (moveCount == 0) {
        return playerTurn;
    }
    playerBoard[playerTurn][selectedSpace] = 0;
    playerTurn = setArrayMove(selectedSpace, moveCount, playerBoard, playerStore, playerTurn, playerTurn);

    return playerTurn;
}
