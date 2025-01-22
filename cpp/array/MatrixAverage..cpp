/*
You are given:
    A matrix of size m×n.
    Starting indices i, j.
    Dimensions width and length.
You need to calculate the average of elements in a sub-matrix of size width×length, starting at (i, j).
*/



#include <iostream>
#include <vector>
using namespace std;

class MatrixAverage {
private:
    vector<vector<int>> prefixSums;

public:
    // Build the prefix sum matrix
    MatrixAverage(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        prefixSums.resize(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                prefixSums[i][j] = matrix[i - 1][j - 1]
                                 + prefixSums[i - 1][j]
                                 + prefixSums[i][j - 1]
                                 - prefixSums[i - 1][j - 1];
            }
        }
    }

    // Calculate the average of the sub-matrix
    double average(int row1, int col1, int width, int length) {
        int row2 = row1 + width - 1;
        int col2 = col1 + length - 1;

        int totalSum = prefixSums[row2 + 1][col2 + 1]
                     - prefixSums[row2 + 1][col1]
                     - prefixSums[row1][col2 + 1]
                     + prefixSums[row1][col1];

        int numElements = width * length;
        return (double)(totalSum) / numElements;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    MatrixAverage ma(matrix);

    cout << ma.average(0, 0, 2, 2) << endl; // Average of top-left 2x2 sub-matrix: (1+2+4+5)/4 = 3
    cout << ma.average(1, 1, 2, 2) << endl; // Average of center 2x2 sub-matrix: (5+6+8+9)/4 = 7
    cout << ma.average(0, 1, 3, 2) << endl; // Average of sub-matrix starting (0,1) of size 3x2

    return 0;
}
