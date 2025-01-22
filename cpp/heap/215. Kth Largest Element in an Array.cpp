#include <queue>
#include <vector>
#include <functional>

using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop() ;
            }
        }

        return minHeap.top();  
    }
};

//sort and return k place                           nlogn
//min heap of k elements and return the top in heap    nlogk
//selection