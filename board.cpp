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

int randomnumber = 100;

void runTest(int (*player1Func)(int[], int), int (*player2Func)(int[], int))
{
	double winnerStats[3] = {0.0, 0.0, 0.0};
	double randomMoveCount = 0.0;
	double totalMoves = 0.0;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 1000000; i++)
	{
		int isActive = 1;
		int playerBoard[2][6] = {{4, 4, 4, 4, 4, 4}, {4, 4, 4, 4, 4, 4}};
		int playerStore[2] = {0, 0};
		int playerTurn = 0;
		// displayBoard(playerBoard, playerStore);
		while (isActive > 0)
		{
			int move = 0;
			totalMoves++;
			if (addRandomness(randomnumber) == 1)
			{
				randomMoveCount++;
				move = getRandom(5);
			}
			else
			{
				if (playerTurn == 0)
				{
					move = player1Func(playerBoard[0], 6);
				}
				else if (playerTurn == 1)
				{
					move = player2Func(playerBoard[1], 6);
					// move = getRandom(5);
				}
			}
			playerTurn = progressGame(move, playerTurn, playerBoard, playerStore);
			isActive = determineSideEmpty(playerBoard[playerTurn]);
			// displayBoard(playerBoard, playerStore);
		}
		playerStore[0] += getArrayTotal(playerBoard[0], 6);
		playerStore[1] += getArrayTotal(playerBoard[1], 6);
		// displayBoard(playerBoard, playerStore);
		int winner = determineWinner(playerStore[0], playerStore[1]);
		determineWinnerStats(winner, winnerStats);
	}
	cout << "\n"
		 << "Player one wonff: " << winnerStats[0];
	cout << "\n"
		 << "Player two won: " << winnerStats[1];
	cout << "\n"
		 << "Draws: " << winnerStats[2];
	cout << "\n"
		 << "Win percentage: " << (winnerStats[0] / (winnerStats[0] + winnerStats[1] + winnerStats[2]));
	cout << "\n"
		 << "Total moves: " << totalMoves;
	cout << "\n"
		 << "Random moves: " << randomMoveCount;
	cout << "\n"
		 << "Random move percentage: " << (randomMoveCount / totalMoves);
}

void runTestRandom(int (*player1Func)(int[], int))
{
	double winnerStats[3] = {0.0, 0.0, 0.0};
	double randomMoveCount = 0.0;
	double totalMoves = 0.0;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 1000000; i++)
	{
		int isActive = 1;
		int playerBoard[2][6] = {{4, 4, 4, 4, 4, 4}, {4, 4, 4, 4, 4, 4}};
		int playerStore[2] = {0, 0};
		int playerTurn = 0;
		// displayBoard(playerBoard, playerStore);
		while (isActive > 0)
		{
			int move = 0;
			totalMoves++;
			if (addRandomness(randomnumber) == 1)
			{
				randomMoveCount++;
				move = getRandom(5);
			}
			else
			{
				if (playerTurn == 0)
				{
					move = player1Func(playerBoard[0], 6);
				}
				else if (playerTurn == 1)
				{
					// move = player2Func(playerBoard[1], 6);
					move = getRandom(5);
				}
			}
			playerTurn = progressGame(move, playerTurn, playerBoard, playerStore);
			isActive = determineSideEmpty(playerBoard[playerTurn]);
			// displayBoard(playerBoard, playerStore);
		}
		playerStore[0] += getArrayTotal(playerBoard[0], 6);
		playerStore[1] += getArrayTotal(playerBoard[1], 6);
		// displayBoard(playerBoard, playerStore);
		int winner = determineWinner(playerStore[0], playerStore[1]);
		determineWinnerStats(winner, winnerStats);
	}
	cout << "\n"
		 << "Player one wonff: " << winnerStats[0];
	cout << "\n"
		 << "Player two won: " << winnerStats[1];
	cout << "\n"
		 << "Draws: " << winnerStats[2];
	cout << "\n"
		 << "Win percentage: " << (winnerStats[0] / (winnerStats[0] + winnerStats[1] + winnerStats[2]));
	cout << "\n"
		 << "Total moves: " << totalMoves;
	cout << "\n"
		 << "Random moves: " << randomMoveCount;
	cout << "\n"
		 << "Random move percentage: " << (randomMoveCount / totalMoves);
}

int main()
{

	cout << "highest vs lowest\n";
	runTest(&getArrayHighestIndex, &getArrayLowestIndex);
	cout << "\n";
	cout << "highest vs closest\n";
	runTest(&getArrayHighestIndex, &getClosestIndex);
	cout << "\n";
	cout << "highest vs farthest\n";
	runTest(&getArrayHighestIndex, &getFarthestIndex);
	cout << "\n";
	cout << "highest vs random\n";
	runTestRandom(&getArrayHighestIndex);
	cout << "\n";
	cout << "lowest vs closest\n";
	runTest(&getArrayLowestIndex, &getClosestIndex);
	cout << "\n";
	cout << "lowest vs farthest\n";
	runTest(&getArrayLowestIndex, &getFarthestIndex);
	cout << "\n";
	cout << "lowest vs random\n";
	runTestRandom(&getArrayLowestIndex);
	cout << "\n";
	cout << "closest vs farthest\n";
	runTest(&getClosestIndex, &getFarthestIndex);
	cout << "\n";
	cout << "closest vs random\n";
	runTestRandom(&getClosestIndex);
	cout << "\n";
	cout << "farthest vs random\n";
	runTestRandom(&getFarthestIndex);
	cout << "\n";

	return 0;
}