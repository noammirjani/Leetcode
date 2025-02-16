#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        // min heap 
        priority_queue<int, vector<int>, greater<int>> heap(sticks.begin(), sticks.end());

        int total = 0;
        while (heap.size() > 1) {
            int first = heap.top();
            heap.pop();
            int second = heap.top();
            heap.pop();
            heap.push(first + second); 
            total += (first + second); 
        }
        
        return total; 
    }
};

int main() {
    Solution solution;
    vector<int> sticks = {2, 4, 3};
    cout << "Minimum cost to connect sticks: " << solution.connectSticks(sticks) << endl;
    return 0;
}