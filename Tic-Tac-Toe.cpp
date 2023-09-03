#include <iostream>
using namespace std;
void structure(char game_board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << game_board[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "---------" << endl;
        }
    }
    cout << endl;
}

bool isWin(char Player, char game_board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (game_board[i][0] == Player && game_board[i][1] == Player && game_board[i][2] == Player) {
            return true;
        }
        if (game_board[0][i] == Player && game_board[1][i] == Player && game_board[2][i] == Player) {
            return true;
        }
    }
    if (game_board[0][0] == Player && game_board[1][1] == Player && game_board[2][2] == Player) {
        return true;
    } else if (game_board[0][2] == Player && game_board[1][1] == Player && game_board[2][0] == Player) {
        return true;
    }
    return false;
}

bool game_board_Full(char game_board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game_board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    //here i have created 3x3 Game Grid
    char game_board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    bool game_over = false;
    char Player = 'X'; //assigned player X 
    int rows, cols;

    while (!game_over) {
        structure(game_board);
        cout << "Player " << Player << ". Enter Row: ";
        cin >> rows;
        cout << "Player " << Player << ". Enter Columns: ";
        cin >> cols;
        
        if (rows >= 0 && rows < 3 && cols >= 0 && cols < 3 && game_board[rows][cols] == ' ') {
            game_board[rows][cols] = Player;
            if (isWin(Player, game_board)) {
                structure(game_board);
                cout << "Player " << Player << " Won!" << endl;
                game_over = true;
            } else if (game_board_Full(game_board)) {
                structure(game_board);
                cout << "It is a draw!" << endl;
                game_over = true;
            } else {
                if (Player == 'X') {
                    Player = 'O';
                } else {
                    Player = 'X';
                }
            }
        } else {
            cout << "Invalid Move, Try again!" << endl;
        }
    }

    return 0;
}
