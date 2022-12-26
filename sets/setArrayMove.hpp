#include "../determines/determineAddToPlayerStore.hpp"
#include "../determines/determinePlayerTurn.hpp"
#include <iostream>

using namespace std;

int setArrayMove(int selectedSpace, int moveCount, int playerBoard[2][6], int playerStore[2], int playerTurn, int originalPlayerTurn)
{
    int extra = 0;
    for (int i = selectedSpace + 1; i < (moveCount + selectedSpace) + 1; i++)
    {
        if (i < 6)
        {
            playerBoard[playerTurn][i]++;
        }
        if (i == 6)
        {
            extra = determineAddToPlayerStore(playerStore, playerTurn, originalPlayerTurn, extra);
            if (playerTurn == originalPlayerTurn)
            {
                if (extra == 0 && i == (moveCount + selectedSpace))
                {
                    return originalPlayerTurn;
                }
            }
        }
        if (i > 6)
        {
            extra++;
        }

        if (selectedSpace == -1)
        {   
            if (playerTurn == originalPlayerTurn)
            {
                if (extra == 0 && i == (moveCount + selectedSpace))
                {
                    if (playerBoard[playerTurn][i] == 1) {
                        playerStore[playerTurn] += playerBoard[determinePlayerTurn(playerTurn)][6-(i+1)];
                        playerStore[playerTurn] += 1;
                        playerBoard[playerTurn][i] = 0;
                        playerBoard[determinePlayerTurn(playerTurn)][6-(i+1)] = 0;
                    }
                }
            }
        }
    }
    if (extra != 0)
    {
        playerTurn = determinePlayerTurn(playerTurn);
        setArrayMove(-1, extra, playerBoard, playerStore, playerTurn, originalPlayerTurn);
    }

    return determinePlayerTurn(originalPlayerTurn);
}