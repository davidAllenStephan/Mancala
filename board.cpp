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

using namespace std;

int main()
{
	int playerOneWins = 0;
	int playerTwoWins = 0;
	int draws = 0;
	int randSeeds[10];

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
			int move = getRandom(5);
			// int move = 0;
			// cin >> move;
			// move--;
			playerTurn = progressGame(move, playerTurn, playerBoard, playerStore);
			isActive = determineSideEmpty(playerBoard[playerTurn]);
			displayBoard(playerBoard, playerStore);

			playerStore[0] += getArrayTotal(playerBoard[0], 6);
			playerStore[1] += getArrayTotal(playerBoard[1], 6);
			displayBoard(playerBoard, playerStore);
		}

		int winner = determineWinner(playerStore[0], playerStore[1]);

		if (winner == 0)
		{
			playerOneWins++;
		}
		else if (winner == 1)
		{
			playerTwoWins++;
		}
		else if (winner == 3)
		{
			draws++;
		}
	}

	cout << "\n"
		 << "Player one won: " << playerOneWins;
	cout << "\n"
		 << "Player two won: " << playerTwoWins;
	cout << "\n"
		 << "Draws: " << draws;
	cout << "\n";

	return 0;
}