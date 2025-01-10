#include <vector>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        std::sort(intervals.begin(), intervals.end(),
                 [](const std::vector<int>& a, const std::vector<int>& b){
                    return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        int count = 0, max_stop = -1;
        for (auto& inter : intervals){
            if (inter[1] > max_stop){
                max_stop = inter[1];
                count++;
            }
        }
        return count;
    }
};