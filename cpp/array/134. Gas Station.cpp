#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, total = 0, curr = 0; 

        for (int i = 0; i  < gas.size(); i++) {
            total += (gas[i] - cost[i]); 
            curr += (gas[i] - cost[i]);

            if (curr < 0){
                curr = 0;
                start = i+1; 
            }
        }

        return total < 0 ? -1 : start;
    }
};
int main() {
    Solution solution;
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    int result = solution.canCompleteCircuit(gas, cost);
    cout << "Starting gas station index: " << result << endl;
    return 0;
}