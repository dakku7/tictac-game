#include <iostream>
#include <memory>
#include <ctime>
#include <cctype>

void computerCharacter(std::shared_ptr<char> playerChoose, std::shared_ptr<char>& computerChoose);
void playerMover(int* playerMove, char* board, std::shared_ptr<char>& playerChoose);
void computerMover(int *computerMove, char* board, std::shared_ptr<char>& computerChoose);
bool checkWinner(char* board, bool* winner, std::shared_ptr <char>& computerChoose, std::shared_ptr<char>& playerChoose);
void drawBoard(char* board);


int main() {
	srand(time(0));
	char playerChar, playerChoice;
	std::cout << "\tIts a Tic Tac Toe game!\n" << std::endl;

	do {
		std::cout << "Choose your side(x/o)!: ";


		std::cin >> playerChar;

		while (playerChar != 'x' && playerChar != 'X' && playerChar != 'o' && playerChar != 'O') {
			std::cout << "Wrong character, please choose X or O: ";
			std::cin >> playerChar;
		}

		playerChar = toupper(playerChar);

		std::shared_ptr<char> playerChoose = std::make_shared<char>(playerChar);
		std::shared_ptr<char> computerChoose;


		computerCharacter(playerChoose, computerChoose);



		std::cout << "Okay, you are playing " << *playerChoose << " now!" << std::endl;
		char board[9] = { ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', };
		int playerMove = 0, computerMove = 0;

		bool winner = false;

		do {

			drawBoard(board);
			playerMover(&playerMove, board, playerChoose); computerMover(&computerMove, board, computerChoose);
			checkWinner(board, &winner, computerChoose, playerChoose);

		} while (winner == false);

		std::cout << "\t\n\tDo you wanna try one more time(Y/N): "; std::cin >> playerChoice;
		while (playerChoice != 'Y' && playerChoice != 'y' && playerChoice != 'N' && playerChoice != 'n') {
			std::cout << "\nPlease type Y or N to conitnue: ";
				std::cin >> playerChoice;
		}

		if (playerChoice == 'n' || playerChoice == 'N') {
			std::cout << "\n\n\tSee you next time!";
		}
	} while (playerChoice == 'Y' || playerChoice == 'y');

	return 0;
}


void computerCharacter(std::shared_ptr<char> playerChoose, std::shared_ptr<char>& computerChoose) {
	computerChoose = std::make_shared<char>(*playerChoose == 'X' ? 'O' : 'X');
}

void playerMover(int* playerMove, char* board, std::shared_ptr<char>& playerChoose) {
	std::cout << "\nInput your choice(1-9): "; std::cin >> *playerMove;
	*playerMove = *playerMove - 1;

	if (board[*playerMove] == ' ') {
		board[*playerMove] = *playerChoose;
	}
	



}
void computerMover(int *computerMove, char* board, std::shared_ptr<char>& computerChoose) {

	do {
		*computerMove = rand() % 9;
	} while (board[*computerMove] != ' '); 

	board[*computerMove] = *computerChoose;


}
bool checkWinner(char* board, bool* winner, std::shared_ptr<char>& computerChoose, std::shared_ptr<char>& playerChoose) {
	// horizontal
	for (int i = 0; i < 9; i += 3) {
		if (board[i] != ' ' && board[i] == board[i + 1] && board[i + 1] == board[i + 2]) {
			*winner = true;
			std::cout << "\n\t" << board[i] << " wins!\n";
			return true;
		}
	}

	// vertical
	for (int i = 0; i < 3; i++) {
		if (board[i] != ' ' && board[i] == board[i + 3] && board[i + 3] == board[i + 6]) {
			*winner = true;
			std::cout << "\n\t" << board[i] << " wins!\n";
			return true;
		}
	}

	// diagonali
	if (board[0] != ' ' && board[0] == board[4] && board[4] == board[8]) {
		*winner = true;
		std::cout << "\n\t" << board[0] << " wins!\n";
		return true;
	}

	if (board[2] != ' ' && board[2] == board[4] && board[4] == board[6]) {
		*winner = true;
		std::cout << "\n\t" << board[2] << " wins!\n";
		return true;
	}

//draw
	bool draw = true;
	for (int i = 0; i < 9; i++) {
		if (board[i] == ' ') {
			draw = false;
			break;
		}
	}

	if (draw) {
		*winner = true;
		std::cout << "\n\tIt's a draw!\n";
		return true;
	}

	return false;
}

void drawBoard(char *board) {
	
	std::cout << "\n     |     |     " << std::endl;
	std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << std::endl;
	std::cout << "_____|_____|_____" << std::endl;
	std::cout << "     |     |     " << std::endl;
	std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << std::endl;
	std::cout << "_____|_____|_____" << std::endl;
	std::cout << "     |     |     " << std::endl;
	std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << std::endl;
	std::cout << "     |     |     " << std::endl;

}