#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char turn;
    bool draw;

public:
    TicTacToe() {
        char num = '1';
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                board[i][j] = num++;
        turn = 'X';
        draw = false;
    }

    void display_board() {
        cout << "\n";
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                cout << " " << board[i][j] << " ";
                if(j<2) cout << "|";
            }
            cout << "\n";
            if(i<2) cout << "-----------\n";
        }
        cout << "\n";
    }

    void player_turn() {
        int choice, row, col;
        cout << "Player " << (turn == 'X' ? "1 [X]" : "2 [O]") << " turn: ";
        cin >> choice;

        switch(choice) {
            case 1: row=0; col=0; break;
            case 2: row=0; col=1; break;
            case 3: row=0; col=2; break;
            case 4: row=1; col=0; break;
            case 5: row=1; col=1; break;
            case 6: row=1; col=2; break;
            case 7: row=2; col=0; break;
            case 8: row=2; col=1; break;
            case 9: row=2; col=2; break;
            default: cout << "Invalid Move!\n"; return;
        }

        if(board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = turn;
            turn = (turn == 'X') ? 'O' : 'X';
        } else {
            cout << "Box already filled! Choose another!!\n";
            player_turn();
        }
    }

    bool gameover() {
        for(int i=0; i<3; i++) {
            if(board[i][0] == board[i][1] && board[i][0] == board[i][2]) return false;
            if(board[0][i] == board[1][i] && board[0][i] == board[2][i]) return false;
        }
        if(board[0][0] == board[1][1] && board[0][0] == board[2][2]) return false;
        if(board[0][2] == board[1][1] && board[0][2] == board[2][0]) return false;

        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(board[i][j] != 'X' && board[i][j] != 'O')
                    return true;
            }
        }

        draw = true;
        return false;
    }

    void play() {
        while(gameover()) {
            display_board();
            player_turn();
        }
        display_board();
        cout << "Congratulations!!!!!!!!!!!!!!!!!!!!!!!!\n";
        if(turn == 'X' && !draw) cout << "Player 2 [O] Wins!\n";
        else if(turn == 'O' && !draw) cout << "Player 1 [X] Wins!\n";
        else cout << "Game Draw!\n";
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}
