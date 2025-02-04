#include <vector>
#include <queue>
using namespace std;


// that is not the optimal solution, but it is the most simple one
// Time:  O(m * n) (due to the dfs)
// Space: O(m * n) the number of pixels in the image, due to the recursion stack in the depth-first search (DFS).
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int target) {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != target) {
            return;
        }
        dfs(image, sr+1, sc, color, target);
        dfs(image, sr-1, sc, color, target);
        dfs(image, sr, sc+1, color, target);
        dfs(image, sr, sc-1, color, target);
    }
};

//optimized solution using bfs
// Time:  O(m * n)
// Space: O(m * n)
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        int originalColor = image[sr][sc];
        std::queue<std::pair<int, int>> q;
        q.push({sr, sc});
        while (!q.empty()) {
            auto [r, c] = q.front(); 
            q.pop();
            if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != originalColor) {
                continue;
            }
            image[r][c] = color; // Mark visited before pushing into queue
            q.push({r+1, c});
            q.push({r-1, c});
            q.push({r, c+1});
            q.push({r, c-1});
        }
        return image;
    }

    // vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    //     vector<pair<int,int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    //     queue<pair<int,int>> q;
    //     int originalColor = image[sr][sc];
    //     if (originalColor == color) return image;
    //     //bfs
    //     image[sr][sc] = color; 
    //     q.push({sr, sc});
    //     while(!q.empty()) {
    //         auto [x, y] = q.front();
    //         q.pop();
    //         image[x][y] = color;
    //         for (auto[dx,dy] : directions) {
    //             int newX=x+dx, newY=y+dy;
    //             if (newX >= 0 && newX < image.size() && newY >= 0 && newY < image[0].size() && image[newX][newY] == originalColor) {
    //                 image[newX][newY] = color; // Mark visited before pushing into queue
    //                 q.push({newX, newY});
    //             }
    //         } 
    //     }
    //     return image;
    // }
};