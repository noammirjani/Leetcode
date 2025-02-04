/*
Check Winner in "Four in a Row"
Given an matrix, determine if there’s a row, column, or diagonal with four consecutive identical values.
Return:
0 if Player 1 wins.
1 if Player 2 wins.
-1 for a tie.
Optimizations: Consider how to handle extremely large matrices (e.g., 10,000x10,000).

*/

//complexity: time O(N × M) where N = number of rows and M = number of columns.
//            space O(1)

#include <iostream>
#include <vector>

class FourInRow {
public:
    FourInRow(std::vector<std::vector<char>> matrix) : m_matrix(matrix) {}

    // 0: Player 1 wins, 1: Player 2 wins, -1: tie
    int isWinner() const {
        for (int i = 0; i < m_matrix.size(); i++) {
            for (int j = 0; j < m_matrix[0].size(); j++) {
                char player = m_matrix[i][j];

                if (player == '.') continue;

                for (auto [dx,dy] : m_directions) {
                    if (isPossiblePath(i, j, dx, dy) && checkPath(i, j, dx, dy, player))  {
                        return (player == 'X') ? 0 : 1; 
                    }
                }
            }
        }

        return -1;
    }

private:
    int m_max = 4;
    std::vector<std::vector<char>> m_matrix; // 'X' for player 1, 'O' for player 2, '.' for empty
    std::vector<std::pair<int, int>> m_directions =  {{0, 1}, {1, 0}, {1, 1}, {1, -1}};

    bool isPossiblePath(const int x, const int y, const int dx, const int dy) const {
        return (x + (m_max - 1) * dx >= 0 && x + (m_max - 1) * dx < m_matrix.size() &&
                y + (m_max - 1) * dy >= 0 && y + (m_max - 1) * dy < m_matrix[0].size());
    }

    bool checkPath(const int x, const int y, const int dx, const int dy, char player) const {
        for (int k = 0; k < 4; k++) {
            if (m_matrix[x+dx*k][y+dy*k] != player)
                return false;
        }
        return true;
    }
};


int main() {
    std::vector<std::vector<char>> board = {
        {'.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'O', '.', '.', '.'},
        {'.', '.', 'O', '.', '.', '.', '.'},
        {'.', 'O', '.', '.', '.', '.', '.'},
        {'O', '.', '.', '.', '.', '.', '.'},
    };

    FourInRow game(board);
    int result = game.isWinner();

    if (result == 0) std::cout << "Player 1 wins!" << std::endl;
    else if (result == 1) std::cout << "Player 2 wins!" << std::endl;
    else std::cout << "It's a tie!" << std::endl;

    return 0;
}