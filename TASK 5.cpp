#include <iostream>
#include <vector>
#include <limits>

class TicTacToe {
public: // Make currentPlayer public
    std::vector<std::vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

    void printBoard() const {
        for (const auto& row : board) {
            for (char cell : row) {
                std::cout << cell << " | ";
            }
            std::cout << "\n---------\n";
        }
    }

    bool isMoveValid(int row, int col) const {
        return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
    }

    void makeMove(int row, int col) {
        board[row][col] = currentPlayer;
        togglePlayer();
    }

    bool checkWin() const {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
                return true;
            }
        }

        // Check diagonals
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            return true;
        }

        return false;
    }

    bool isBoardFull() const {
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void togglePlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
};

int main() {
    TicTacToe game;
    int row, col;

    std::cout << "Welcome to Tic Tac Toe!\n";

    do {
        // Print the current state of the board
        game.printBoard();

        // Get the current player's move
        std::cout << "Player " << game.currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        // Validate the move
        while (!game.isMoveValid(row, col)) {
            std::cout << "Invalid move! Try again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> row >> col;
        }

        // Make the move
        game.makeMove(row, col);

        // Check for a win
        if (game.checkWin()) {
            std::cout << "Player " << game.currentPlayer << " wins!\n";
            game.printBoard();
            break;
        }

        // Check for a draw
        if (game.isBoardFull()) {
            std::cout << "The game ends in a draw!\n";
            game.printBoard();
            break;
        }

    } while (true);

    return 0;
}
