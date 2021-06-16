#include<iostream>
#include <vector>
#include <cassert>

typedef enum {
    EMPTY,
    P1,
    P2
} mark_t;


bool check(std::vector<std::vector<mark_t>>& board, const mark_t p)
{
    const int N = board.size();
    assert(board[0].size() == N);
    // check all rows, colums and 2 diagonals

    for (int i = 0; i < N; i++) { // check each of the i rows
        if (board[i][0] != p) continue;
        bool win(true);
        for (int j = 0; j < N; j++) {
            if (board[i][j] != p) {
                win = false;
                break;
            }
        }

        if (win) return true;
    }

    for (int j = 0; j < N; j++) { // check each of the i columns
        if (board[0][j] != p) continue;
        bool win(true);
        for (int i = 0; i < N; i++) {
            if (board[i][j] != p) {
                win = false;
                break;
            }
        }

        if (win) return true;
    }

    // check diag 1
    bool win(true);
    for (int i = 0; i < N; i++) {
        if (board[i][i] != p) {
            win = false;
            break;
        }
    }

    if (win) return true;


    // check diag 2
    for (int i = 0; i < N; i++) {
        if (board[N-i-1][i] != p) {
            win = false;
            break;
        }
    }

    if (win) return true;

    return false;
}

int main()
{
    const int N = 3;
    std::vector<std::vector<mark_t>> board(N, std::vector<mark_t>(N, EMPTY));

    board[0][0] = P1;
    board[1][0] = P1;
    std::cout << check(board, P1);
    board[2][0] = P1;

    std::cout << check(board, P1);
    board[2][0] = P2;
    std::cout << check(board, P1);
    board[1][1] = P1;
    board[2][2] = P1;
    std::cout << check(board, P1);

    return 0;
}
