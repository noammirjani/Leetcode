#include <vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        
        // Transpose the matrix
        for (int row = 0; row < n; row++) {
            for (int col = row + 1; col < n; col++) {
                std::swap(matrix[row][col], matrix[col][row]); 
            }
        }

        // Reverse each row
        for (int row = 0; row < n; row++) {
            std::reverse(matrix[row].begin(), matrix[row].end());
        }
    }
};