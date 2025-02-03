#include <vector>
using namespace std;

//better solution
class NumMatrix {
private:
     vector<vector<int>> m_sums;

public:
   NumMatrix(vector<vector<int>>& matrix) {
        // init matrix 
        int m = matrix.size()+1, n = matrix[0].size()+1;
        m_sums.resize(m, vector<int>(n, 0));

        //calc sum of each cell 
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                m_sums[i][j] = m_sums[i][j-1] + m_sums[i-1][j] - m_sums[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;
        return m_sums[row2][col2] - m_sums[row2][col1-1] - m_sums[row1-1][col2] + m_sums[row1-1][col1-1];
    }
};


class NumMatrix2 {
private:
     vector<vector<int>> sums;

public:
    NumMatrix2(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        sums.resize(m, vector<int>(n, 0));
        sums[0][0] = matrix[0][0];

        // first row
        for (int j = 1; j < n; j++)
            sums[0][j] = sums[0][j-1] + matrix[0][j];
        
        // first col
        for (int i = 1; i < m; i++)
            sums[i][0] = sums[i-1][0] + matrix[i][0];

        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                sums[i][j] = sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] + matrix[i][j];
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = sums[row2][col2];
        if (row1 > 0) total -= sums[row1 - 1][col2];
        if (col1 > 0) total -= sums[row2][col1 - 1];
        if (row1 > 0 && col1 > 0) total += sums[row1 - 1][col1 - 1];
        return total;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */