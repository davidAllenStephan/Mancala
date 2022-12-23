#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

#include "displayBoard.hpp"
#include "determines/determineWinner.hpp"
#include "gets/getRandom.hpp"
#include "progressGame.hpp"
#include "determines/determineSideEmpty.hpp"
#include "gets/getArrayTotal.hpp"

using namespace std;

int playerBoard[2][6] = {{4,4,4,4,4,4}, {4,4,4,4,4,4}};
int playerStore[2] = {0, 0};

// PLAYER 1 VARIABLES
int player_1_board[6] = {4, 4, 4, 4, 4, 4};
int player_1_store = 0;

// PLAYER 2 VARIABLESd
int player_2_board[6] = {4, 4, 4, 4, 4, 4};
int player_2_store = 0;

int playerTurn = 0;
int isActive = 1;
int winner = 0;

int main()
{
	srand((unsigned)time(NULL));
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
	}

	playerStore[0] += getArrayTotal(playerBoard[0], 6);
	playerStore[1] += getArrayTotal(playerBoard[1], 6);
	displayBoard(playerBoard, playerStore);
	
	winner = determineWinner(playerStore[0], playerStore[1]);

	cout << winner << "\n";

	return 0;
}