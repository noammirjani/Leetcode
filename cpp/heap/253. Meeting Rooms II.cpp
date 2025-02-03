
#include <vector>
#include <algorithm>
#include <queue>

// noam did :)

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
         if (intervals.empty()) return 0;
        
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> minHeap;
        minHeap.push(intervals[0][1]); 
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= minHeap.top()) {
                minHeap.pop(); 
            }
            minHeap.push(intervals[i][1]);
                
        }
        return minHeap.size(); 
    }
};