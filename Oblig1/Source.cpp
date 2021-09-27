#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>

void startGame();
void printBoard();
void playerOneTurn();
void playerTwoTurn();
void gameStatus();
void occupied();
void checkSpace();
void results();
void clearBoard();
void nextRound();
void gameType();
void startAiGame();
void aiTurn();
void playAgain();

bool gameComplete(false);
char board[3][3]{ '*','*','*','*','*','*','*','*','*' };
int playerTurn{};
char playerMark{};

int security{};
int m{};
bool aiGame(false);
char aiChoice{};
char choice{};

bool occupiedOne(false);
bool occupiedTwo(false);
bool occupiedThree(false);
bool occupiedFour(false);
bool occupiedFive(false);
bool occupiedSix(false);
bool occupiedSeven(false);
bool occupiedEight(false);
bool occupiedNine(false);

// Launches the menu and shows the results after the game has finished
int main() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::rand();
	std::cout << "******** Choose Game Mode ********" << std::endl << std::endl << std::endl;
	std::cout << "Play against AI: '1'" << std::endl << std::endl;
	std::cout << "2-Player: '2'" << std::endl << std::endl << std::endl;
	gameType();
	results();

	return 0;
}

// Allows the player to choose who they play against
void gameType() {
	char playStyle = _getch();
	std::cout << playStyle << std::endl;
	while (playStyle != '1' && playStyle != '2')
	{
		gameType();
	}
	if (playStyle == '1')
	{
		system("cls");
		startAiGame();
	}
	else if (playStyle == '2')
	{
		system("cls");
		startGame();
	}
}

// Starts a new game
void startGame() {
	std::cout << "******** Welcome to Tic Tac Toe! ********" << std::endl << std::endl;
	while (gameComplete == false)
	{
		printBoard();
		gameStatus();
		if (gameComplete == false)
		{
			playerOneTurn();
		}
		printBoard();
		gameStatus();
		if (gameComplete == false)
		{
			playerTwoTurn();
		}
	}
}

// Starts a new game against an AI
void startAiGame() {
	std::cout << "******** Welcome to Tic Tac Toe! ********" << std::endl << std::endl;
	aiGame = true;
	while (gameComplete == false)
	{
		printBoard();
		gameStatus();
		if (gameComplete == false)
		{
			playerOneTurn();
		}
		printBoard();
		gameStatus();
		if (gameComplete == false)
		{
			aiTurn();
		}
	}
}

// Prints the board using a nested for-loop
void printBoard() {
	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "             | ";
		for (int j = 0; j < 3; j++)
		{
			std::cout << board[i][j] << " | ";
		}
		std::cout << std::endl;

	}
	std::cout << std::endl;
}

// Player One's turn to select a space
void playerOneTurn() {
	playerTurn = 1;
	playerMark = 'X';
	nextRound();
	std::cout << "Player 1 - Write a number from 1 to 9: ";
	checkSpace();
}

// Player Two's turn to select a space
void playerTwoTurn() {
	playerTurn = 2;
	playerMark = 'O';
	nextRound();
	std::cout << "Player 2 - Write a number from 1 to 9: ";
	checkSpace();
}

// The AI generates a random nuber between 1 and 9 until it finds an unoccupied space
void aiTurn() {
	playerTurn = 2;
	playerMark = 'O';
	nextRound();
	std::cout << "AI's turn: ";
	checkSpace();
}

// Repeats until the user has chosen an empty space on the board
void occupied() {
	while (security == 1)
	{
		checkSpace();
	}
}

// Checks if the game has ended by going through every combination that leads to a draw or victory
void gameStatus() {
	// Horizontal X
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
	{
		gameComplete = true;
	}
	else if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
	{
		gameComplete = true;
	}
	else if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
	{
		gameComplete = true;
	}
	// Vertical X
	else if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
	{
		gameComplete = true;
	}
	else if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
	{
		gameComplete = true;
	}
	else if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
	{
		gameComplete = true;
	}
	// Diagonal X
	else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
	{
		gameComplete = true;
	}
	else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
	{
		gameComplete = true;
	}

	// Horizontal O
	if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
	{
		gameComplete = true;
	}
	else if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
	{
		gameComplete = true;
	}
	else if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
	{
		gameComplete = true;
	}
	// Vertical O
	else if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
	{
		gameComplete = true;
	}
	else if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
	{
		gameComplete = true;
	}
	else if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
	{
		gameComplete = true;
	}
	// Diagonal O
	else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
	{
		gameComplete = true;
	}
	else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
	{
		gameComplete = true;
	}

	// Draw
	else if (m >= 9)
	{
		gameComplete = true;
	}
}

// Counts how many turns has been used
void nextRound() {
	m++;
}

// Displays the winner and asks if the player wants to play again
void results() {
	if (m < 9 && aiGame == false)
	{
		std::cout << "Player " << playerTurn << " won!!!!" << std::endl << std::endl << std::endl;
	}
	else if (m < 9 && aiGame == true)
	{
		if (playerTurn == 1)
		{
			std::cout << "Player 1 won!!!!" << std::endl << std::endl << std::endl;
		}
		else if (playerTurn == 2)
		{
			std::cout << "The AI won!!!!" << std::endl << std::endl << std::endl;
		}
	}
	else if (m >= 9) {
		std::cout << "The game ended in a draw!!!!" << std::endl << std::endl << std::endl;
	}
	std::cout << "Will you play again? (y for yes, n for no): ";
	playAgain();
}

void playAgain() {
	char replay = _getch();
	std::cout << replay << std::endl;
	switch (replay)
	{
	case 'y': case 'Y':
		system("cls");
		gameComplete = false;
		clearBoard();
		if (aiGame == true)
		{
			startAiGame();
			results();
		}
		else {
			startGame();
			results();
		}
		break;
	case 'n': case 'N':
		exit(0);
		break;
	default:
		playAgain();
		break;
	}
}

// resets the values in the board array and makes them unoccupied as well as reseting the number of rounds
void clearBoard() {
	board[0][0] = '*';
	board[0][1] = '*';
	board[0][2] = '*';
	board[1][0] = '*';
	board[1][1] = '*';
	board[1][2] = '*';
	board[2][0] = '*';
	board[2][1] = '*';
	board[2][2] = '*';

	occupiedOne = false;
	occupiedTwo = false;
	occupiedThree = false;
	occupiedFour = false;
	occupiedFive = false;
	occupiedSix = false;
	occupiedSeven = false;
	occupiedEight = false;
	occupiedNine = false;

	m = 0;
}

// Lets the user or an AI select a space and checks if the spaces are occupied
void checkSpace() {
	if (playerTurn == 2 && aiGame == true)
	{
		std::rand() % 9 + 1;
		if (std::rand() % 9 + 1 == 1)
		{
			aiChoice = '1';
		}
		else if (std::rand() % 9 + 1 == 2)
		{
			aiChoice = '2';
		}
		else if (std::rand() % 9 + 1 == 3)
		{
			aiChoice = '3';
		}
		else if (std::rand() % 9 + 1 == 4)
		{
			aiChoice = '4';
		}
		else if (std::rand() % 9 + 1 == 5)
		{
			aiChoice = '5';
		}
		else if (std::rand() % 9 + 1 == 6)
		{
			aiChoice = '6';
		}
		else if (std::rand() % 9 + 1 == 7)
		{
			aiChoice = '7';
		}
		else if (std::rand() % 9 + 1 == 8)
		{
			aiChoice = '8';
		}
		else if (std::rand() % 9 + 1 == 9)
		{
			aiChoice = '9';
		}

		choice = aiChoice;

		switch (choice)
		{
		case '1':
			if (occupiedOne == true)
			{
				security = 1;
				occupied();
			}
			else
			{
				security = 0;
				board[0][0] = playerMark;
				occupiedOne = true;
			}
			break;
		case '2':
			if (occupiedTwo == true)
			{
				security = 1;
				occupied();
			}
			else
			{
				security = 0;
				board[0][1] = playerMark;
				occupiedTwo = true;
			}
			break;
		case '3':
			if (occupiedThree == true)
			{
				security = 1;
				occupied();
			}
			else
			{
				security = 0;
				board[0][2] = playerMark;
				occupiedThree = true;
			}
			break;
		case '4':
			if (occupiedFour == true)
			{
				security = 1;
				occupied();
			}
			else
			{
				security = 0;
				board[1][0] = playerMark;
				occupiedFour = true;
			}
			break;
		case '5':
			if (occupiedFive == true)
			{
				security = 1;
				occupied();
			}
			else
			{
				security = 0;
				board[1][1] = playerMark;
				occupiedFive = true;
			}
			break;
		case '6':
			if (occupiedSix == true)
			{
				security = 1;
				occupied();
			}
			else
			{
				security = 0;
				board[1][2] = playerMark;
				occupiedSix = true;
			}
			break;
		case '7':
			if (occupiedSeven == true)
			{
				security = 1;
				occupied();
			}
			else
			{
				security = 0;
				board[2][0] = playerMark;
				occupiedSeven = true;
			}
			break;
		case '8':
			if (occupiedEight == true)
			{
				security = 1;
				occupied();
			}
			else
			{
				security = 0;
				board[2][1] = playerMark;
				occupiedEight = true;
			}
			break;
		case '9':
			if (occupiedNine == true)
			{
				security = 1;
				occupied();
			}
			else
			{
				security = 0;
				board[2][2] = playerMark;
				occupiedNine = true;
			}
			break;
		default:
			checkSpace();
			break;


		}
	}

	else {
		char choose = _getch();
		std::cout << choose << std::endl;
		choice = choose;

		switch (choice)
		{
		case '1':
			if (occupiedOne == true)
			{
				security = 1;
				occupied();
			}
			else
			{
				security = 0;
				board[0][0] = playerMark;
				occupiedOne = true;
			}
			break;
		case '2':
			if (occupiedTwo == true)
			{
				security = 1;
				occupied();
			}
			else
			{
				security = 0;
				board[0][1] = playerMark;
				occupiedTwo = true;
			}
			break;
		case '3':
			if (occupiedThree == true)
			{
				security = 1;
				occupied();
			}
			else
			{
				security = 0;
				board[0][2] = playerMark;
				occupiedThree = true;
			}
			break;
		case '4':
			if (occupiedFour == true)
			{
				security = 1;
				occupied();
			}
			else
			{
				security = 0;
				board[1][0] = playerMark;
				occupiedFour = true;
			}
			break;
		case '5':
			if (occupiedFive == true)
			{
				security = 1;
				occupied();
			}
			else
			{
				security = 0;
				board[1][1] = playerMark;
				occupiedFive = true;
			}
			break;
		case '6':
			if (occupiedSix == true)
			{
				security = 1;
				occupied();
			}
			else
			{
				security = 0;
				board[1][2] = playerMark;
				occupiedSix = true;
			}
			break;
		case '7':
			if (occupiedSeven == true)
			{
				security = 1;
				occupied();
			}
			else
			{
				security = 0;
				board[2][0] = playerMark;
				occupiedSeven = true;
			}
			break;
		case '8':
			if (occupiedEight == true)
			{
				security = 1;
				occupied();
			}
			else
			{
				security = 0;
				board[2][1] = playerMark;
				occupiedEight = true;
			}
			break;
		case '9':
			if (occupiedNine == true)
			{
				security = 1;
				occupied();
			}
			else
			{
				security = 0;
				board[2][2] = playerMark;
				occupiedNine = true;
			}
			break;
		default:
			checkSpace();
			break;


		}
	}


	
}
