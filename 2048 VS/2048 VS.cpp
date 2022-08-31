#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

//Глобальні змінні
int arr[4][4];
int score;

// Головній єкран
void table() {
	cout << "\t\t     " << "Game 2048" << endl;
	cout << endl;
	cout << "Score: " << score << endl;
	for (int i = 0; i < 4; i++) {
		cout << "\t+-------+-------+-------+-------+" <<endl;
		cout << "\t|\t|\t|\t|\t|" << endl;
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 0) {
				cout << "\t|   " << "   ";
			}
			else {
				cout << "\t|   " << arr[i][j];
			}
		}
		cout << "\t|"<< endl;
	}
	cout << "\t+-------+-------+-------+-------+" << endl<<endl;
	cout << "W - UP" << "  |  " << "S - DOWN" << "  |  " << "A - LEFT" << "  |  " << "D - RIGHT"<< "  |  " << "Q - QITE" << "  |  " << "G - NEW GAME" << endl;
}
//Заповнення ігрового поле
void field() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = 0;
		}
	}
	for (int k = 0; k < 2; k++) {
		int i = rand() % 4;
		int j = rand() % 4;
		int n = rand() % 10;
		if (n < 9) {
			arr[i][j] = 2;
		}
		else {
			arr[i][j] = 4;
		}
	}
	table();
}
//Перевірка наявності вільних клітинок
int full() {
	int fdot = 1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 0) {
				fdot = 0;
				break;
			}
		}
	}
	return fdot;
}
//Випадкові 2 або 4 
void genNum() {
	srand(time(NULL));
	int dot = 1;
	if (full()==0) {
		while (dot == 1) {
			int i = rand() % 4;
			int j = rand() % 4;
			if (arr[i][j] == 0) {
				int n = rand() % 10;
				if (n < 9) {
					arr[i][j] = 2;
				}
				else {
					arr[i][j] = 4;
				}
				dot = 0;
			}
		}
	}
}
//Ходи
void step(char move) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[j][i]==0) {
				if (move == 'w') {
					for (int k = j + 1; k < 4; k++) {
						if (arr[k][i] != 0) {
							arr[j][i] = arr[k][i];
							arr[k][i] = 0;
							break;
						}
					}
				}
				if (move == 's') {
					for (int k = j - 1; k >= 0; k--) {
						if (arr[k][i] != 0) {
							arr[j][i] = arr[k][i];
							arr[k][i] = 0;
							break;
						}
					}
				}

			}
			if (arr[i][j] == 0) {
				if (move == 'a') {
					for (int k = j + 1; k < 4; k++) {
						if (arr[i][k] != 0) {
							arr[i][j] = arr[i][k];
							arr[i][k] = 0;
							break;
						}
					}
				}
				if (move == 'd') {
					for (int k = j - 1; k >= 0; k--) {
						if (arr[i][k] != 0) {
							arr[i][j] = arr[i][k];
							arr[i][k] = 0;
							break;
						}
					}
				}
			}

		}
	}
	for (int i = 0; i < 4; i++) {
		if (move == 'w') {
			for (int j = 0; j < 3; j++) {
				if (arr[j][i] != 0 && arr[j][i] == arr[j + 1][i]) {
					arr[j][i] = arr[j][i] + arr[j + 1][i];
					arr[j + 1][i] = 0;
					score += arr[j][i];
				}
			}
		}
		if (move == 's') {
			for (int j = 3; j > 0; j--) {
				if (arr[j][i] != 0 && arr[j][i] == arr[j - 1][i]) {
					arr[j][i] = arr[j][i] + arr[j - 1][i];
					arr[j - 1][i] = 0;
					score += arr[j][i];
				}
			}
		}
		if (move == 'a') {
			for (int j = 0; j < 3; j++) {
				if (arr[i][j] != 0 && arr[i][j] == arr[i][j + 1]) {
					arr[i][j] = arr[i][j] + arr[i][j + 1];
					arr[i][j + 1] = 0;
					score += arr[i][j];
				}
			}
		}
		if (move == 'd') {
			for (int j = 3; j > 0; j--) {
				if (arr[i][j] != 0 && arr[i][j] == arr[i][j - 1]) {
					arr[i][j] = arr[i][j] + arr[i][j - 1];
					arr[i][j - 1] = 0;
					score += arr[i][j];
				}
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[j][i] == 0) {
				if (move == 'w') {
					for (int k = j + 1; k < 4; k++) {
						if (arr[k][i] != 0) {
							arr[j][i] = arr[k][i];
							arr[k][i] = 0;
							break;
						}
					}
				}
				if (move == 's') {
					for (int k = j - 1; k >= 0; k--) {
						if (arr[k][i] != 0) {
							arr[j][i] = arr[k][i];
							arr[k][i] = 0;
							break;
						}
					}
				}
			}
			if (arr[i][j] == 0) {
				if (move == 'a') {
					for (int k = j + 1; k < 4; k++) {
						if (arr[i][k] != 0) {
							arr[i][j] = arr[i][k];
							arr[i][k] = 0;
							break;
						}
					}
				}
				if (move == 'd') {
					for (int k = j - 1; k >= 0; k--) {
						if (arr[i][k] != 0) {
							arr[i][j] = arr[i][k];
							arr[i][k] = 0;
							break;
						}
					}
				}
			}
		}
	}
}

//Умови програшу
int end() {
	int dot = 1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++){
			if (arr[i][j] == arr[i][j + 1]) {
				dot = 0;
				break;
			}
        }
		if (dot == 0) {
			break;
		}
    }
	if (dot == 1) {
		for (int i = 0; i<3; i++) {
			for (int j = 0; j < 4; j++) {
				if (arr[i][j] == arr[i + 1][j]) {
					dot = 0;
					break;
				}
			}
			if (dot == 0) {
				break;
			}
		}
	}
	return dot;
}
void gameOver() {
	//system("cls");
	char answer;
	cout << endl << "\t Game over!!!";
	cout << "\t\t Score: " << score << endl << endl;
	cout << "Do you wont to play a new game? (y/n) ";
	cin >> answer;
	answer = tolower(answer);
	if (answer == 'y') {
		system("cls");
		score = 0;
		field();
	}
	else {
		exit(0);
	}

}
//Умови виграшу
int win() {
	int wDot = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 2048) {
				wDot = 1;
			}
		}
	}
	return wDot;
}
void winGame() {
	char answer;
	cout << "\t\t You win!!!" << endl << endl;
	cout << "Do you wont to continue? (y/n) ";
	cin >> answer;
	answer = tolower(answer);
	if (answer == 'y') {
		table();
	}
	else {
		exit(0);
	}
}
//Вихід з гри
void endGame() {
	char answer;
	cout << "Do you want to end the game? (y/n) ";
	cin >> answer;
	answer = tolower(answer);
	if (answer == 'y') {
		exit(0);
	}
	else
		system("cls");
		table();
}
//Нова гра
void newGame() {
	char answer;
	cout << "Do you wont to play a new game? (y/n)  ";
	cin >> answer;
	answer = tolower(answer);
	if (answer == 'y') {
		system("cls");
		score = 0;
		field();
	}
	else {
		system("cls");
		table();
	}
}

int main() {
	//Гра
	char move;
	field();
	cout << endl << "Make a choice:  ";
	cin >> move;
	move = tolower(move);
	while (move != 'w' && move != 's' && move != 'a' && move != 'd' && move != 'q' && move != 'g') {
		cout << endl << "Something wrong, make another choice!" << endl;
		cin >> move;
		move = tolower(move);
	}
	while (move == 'w' || move == 's' || move == 'a' || move == 'd' || move == 'q' || move == 'g') {
		switch (move) {
		case 'w':
		case 's':
		case 'a':
		case 'd':
			step(move);
			genNum();
			system("cls");
			table();
			break;
		case'q':
			endGame();
		case'g':
			newGame();
		}
		if (full() == 1) {
			if (end() == 1) {
				gameOver();
			}
		}
		if (win() == 1) {
			winGame();
		}
		cout << endl << "Make a choice:  ";
		cin >> move;
		move = tolower(move);
		while (move != 'w' && move != 's' && move != 'a' && move != 'd' && move != 'q' && move != 'g') {
			cout << endl << "Something wrong, make another choice!" << endl;
			cin >> move;
			move = tolower(move);
		}
	}
}