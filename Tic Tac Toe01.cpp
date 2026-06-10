#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void displayBoard()
{
    cout << "\n";
    cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "--|---|--" << endl;
    cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "--|---|--" << endl;
    cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "\n";
}

bool checkWin()
{
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;

        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

int main()
{
    int choice, moves = 0;
    char player = 'X';

    while(moves < 9)
    {
        displayBoard();

        cout << "Player " << player << ", enter position (1-9): ";
        cin >> choice;

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if(board[row][col] != 'X' && board[row][col] != 'O')
        {
            board[row][col] = player;
            moves++;

            if(checkWin())
            {
                displayBoard();
                cout << "Player " << player << " Wins!" << endl;
                return 0;
            }

            player = (player == 'X') ? 'O' : 'X';
        }
        else
        {
            cout << "Position already taken! Try again.\n";
        }
    }

    displayBoard();
    cout << "Game Draw!" << endl;

    return 0;
}
