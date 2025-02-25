#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int current = 0, subarray = 0;
        std::unordered_map<int,int> prefix; 
        prefix[0] = 1;

        for (int num : nums) {
            current += num; 

            if (prefix.find(current-k) != prefix.end()){
                subarray += prefix[current-k];
            }
            prefix[current]++;
        }
        return subarray;

        // 1 2 3 4 5  k = 6 subarray=1,1,
        // 1: 1 3: 1 6: 1 10: 1 15: 1

        // brute force - time complexity On^2
        // int current = 0, subarray = 0;
        // for (int i = 0; i < nums.size(); ++i){
        //     current = nums[i];
        //     if (current == k) {
        //         subarray++;
        //     }
        //     for (int j = i+1; j < nums.size(); ++j){
        //         current += nums[j];
        //         if (current == k) {
        //             subarray++;
        //         }
        //     }
        // }
        // return subarray;
    }
};