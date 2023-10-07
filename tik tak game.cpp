#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

int choice;
int row, column;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
bool draw = false;

void display_board()
{
	system("cls");
	cout << "                                      *_* Tik Tak Toe game *_*\n";
	cout << "How to play.\n";
	cout << "Press the corresponding number on the keyboard which you see on board\n";
	cout << "As soon as you will press the number, the board will replace the number with your sign\n";
	cout << "If you are player 1 your sign is X\n";
	cout << "Player 1 [X]\n";
	cout << "If you are player 2 your sign is O\n";
	cout << "Player 2 [O]\n";

	cout << "                          |     |     \n";
	cout << "                       " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
	cout << "                     _____|_____|_____\n";
	cout << "                          |     |     \n";
	cout << "                       " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
	cout << "                     _____|_____|_____\n";
	cout << "                          |     |     \n";
	cout << "                       " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
	cout << "                          |     |     \n";
}

void player_turn()
{
	if (turn == 'X')
		cout << "\n \tPlayer 1 [X] turn: ";
	if (turn == 'O')
		cout << "\n \tPlayer 2 [O] turn: ";

	cin >> choice;
	switch (choice)
	{
	case 1:
		row = 0, column = 0;
		break;
	case 2:
		row = 0, column = 1;
		break;
	case 3:
		row = 0, column = 2;
		break;
	case 4:
		row = 1, column = 0;
		break;
	case 5:
		row = 1, column = 1;
		break;
	case 6:
		row = 1, column = 2;
		break;
	case 7:
		row = 2, column = 0;
		break;
	case 8:
		row = 2, column = 1;
		break;
	case 9:
		row = 2, column = 2;
		break;

	default:
		cout << "invalid choice, please choose somthing else. Thankyou!";
		break;
	}
	if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
	{
		board[row][column] = 'X';
		turn = 'O';
	}
	else if (turn == 'O' && board[row][column] != 'O' && board[row][column] != 'X')
	{
		board[row][column] = 'O';
		turn = 'X';
	}
	else
	{
		cout << "!!box already filled!!\n";
		cout << "!!Please select another box!!\n";
		player_turn();
	}
	display_board();
}

bool gameover()
{
	// check for win
	for (int i = 0; i < 3; i++)
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
			return false;

	for (int i = 0; i < 3; i++)
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
			return false;

	if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
		return false;

	if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
		return false;

	// for game continuation
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i][j] != 'X' && board[i][j] != 'O')
				return true;

	// for draw
	draw = true;
	return false;
}

main()
{
	system("color 5F");
	while (gameover())
	{
		display_board();
		player_turn();
		gameover();
	}

	if (turn == 'X' && draw == false)
	{
		cout << "CONGRATULATIONS!!\n";
		cout << "Player 2[O] wins!!\n";
	}
	else if (turn == 'O' && draw == false)
	{
		cout << "CONGRATULATIONS!!\n";
		cout << "Player 1[X] wins!!\n";
	}
	else
	{
		cout << "Game Draw\n";
	}
	getch();

	cout << "Designed and developed by - Harsh"
}
