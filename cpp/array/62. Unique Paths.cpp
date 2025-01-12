#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> options;
        
        for (int i = 0; i < m; i++){
            vector<int> temp (n, 1);
            options.push_back(temp);
        }

        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++) {
                options[i][j] = options[i-1][j] + options[i][j-1];
            }   
        }

        return options[m-1][n-1];
    }
};