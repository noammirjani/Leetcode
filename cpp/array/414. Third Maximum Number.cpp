#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        long first = nums[0], second=LONG_MIN, third=LONG_MIN;

        for (int num : nums){
            if (num > first){
                third = second; 
                second = first; 
                first = num;
            }
            else if (num > second && num != first) {
                third = second;
                second = num; 
            }
            else if (num > third && num != first && num != second){
                third = num; 
            }
        }
        return third != LONG_MIN ? third : first;
    }
};