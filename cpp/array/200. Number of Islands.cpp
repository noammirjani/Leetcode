#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return; 

        if (grid[i][j] == '0' || grid[i][j] == '#') return;
        grid[i][j] = '#';

        dfs(grid, i, j+1); 
        dfs(grid, i-1, j); 
        dfs(grid, i, j-1); 
        dfs(grid, i+1, j);
    }
    int numIslands(vector<vector<char>>& grid) {
        int amount = 0; 
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    amount ++;
                    dfs(grid, i, j);
                }
            }
        }
        return amount; 
    }
};