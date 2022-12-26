#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <random>

#include "displayBoard.hpp"
#include "determines/determineWinner.hpp"
#include "gets/getRandom.hpp"
#include "progressGame.hpp"
#include "determines/determineSideEmpty.hpp"
#include "gets/getArrayTotal.hpp"
#include "gets/getArrayHighestIndex.hpp"
#include "gets/getArrayLowestIndex.hpp"
#include "gets/getClosestIndex.hpp"
#include "gets/getFarthestIndex.hpp"
#include "determines/determineWinnerStats.hpp"
#include "sets/addRandomness.hpp"

using namespace std;

int main()
{

	int winnerStats[3] = {0, 0, 0};

	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++)
	{
		int isActive = 1;
		int playerBoard[2][6] = {{4, 4, 4, 4, 4, 4}, {4, 4, 4, 4, 4, 4}};
		int playerStore[2] = {0, 0};
		int playerTurn = 0;
		displayBoard(playerBoard, playerStore);
		while (isActive > 0)
		{
			int move = 0;
			if (addRandomness(15) == 1)
			{
				move = getRandom(5);
			}
			else if (playerTurn == 0)
			{
				move = getFarthestIndex(playerBoard[0], 6);
			}
			else if (playerTurn == 1)
			{
				move = getClosestIndex(playerBoard[1], 6);
			}
			playerTurn = progressGame(move, playerTurn, playerBoard, playerStore);
			isActive = determineSideEmpty(playerBoard[playerTurn]);
			displayBoard(playerBoard, playerStore);
		}
		playerStore[0] += getArrayTotal(playerBoard[0], 6);
		playerStore[1] += getArrayTotal(playerBoard[1], 6);
		displayBoard(playerBoard, playerStore);
		int winner = determineWinner(playerStore[0], playerStore[1]);
		determineWinnerStats(winner, winnerStats);
	}

	cout << "\n"
		 << "Player one won: " << winnerStats[0];
	cout << "\n"
		 << "Player two won: " << winnerStats[1];
	cout << "\n"
		 << "Draws: " << winnerStats[2];
	cout << "\n";

	return 0;
}