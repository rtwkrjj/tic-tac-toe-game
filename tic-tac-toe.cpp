
#include <iostream>
using namespace std ;

// function to displaye the current gameboard : 
void showBoard(char board[3][3])
{
    cout<<"\nCurrent board :\n";
    for(int i=0; i<3 ;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<board[i][j];
            if(j<2) cout<<" | ";
        }
        cout<<endl;if(i<2) cout<<"--+--+--"<<endl;
    }
}

// check if player has won the match or not : 
bool checkWin(char board[3][3], char player){
    for(int i=0;i<3;i++)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
    }
}
// checking the diagonal : 
 if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
        }
        return false;
}

// Function to check if the board is full (draw)
bool isDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; // Empty spot found, not a draw
            }
        }
    }
    return true; // No empty spots, it's a draw
}

// Main game function
void playGame() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';
    bool gameOver = false;

    while (!gameOver) {
        showBoard(board);

        // Ask player for their move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column 1-3): ";
        cin >> row >> col;

        // Check if move is valid
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            cout << "Invalid position! Please enter numbers between 1 and 3." << endl;
            continue;
        }

        // Adjust for 0-based indexing
        row--; col--;

        if (board[row][col] != ' ') {
            cout << "That spot is already taken! Try again." << endl;
            continue;
        }

        // Place player's mark
        board[row][col] = currentPlayer;

        // Check for win
        if (checkWin(board, currentPlayer)) {
            showBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        }
        // Check for draw
        else if (isDraw(board)) {
            showBoard(board);
            cout << "It's a draw!" << endl;
            gameOver = true;
        }
        // Switch player
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}






int main()
{
    char playAgain;

    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl;
    return 0;
}