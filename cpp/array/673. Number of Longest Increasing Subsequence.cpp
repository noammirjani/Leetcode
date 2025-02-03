#include <vector>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
       vector<int> lengthOfLongestSeq(nums.size(), 1); 
       vector<int> countOfLongestSeq(nums.size(), 1);

       int maxLen = 1, maxSeq = 0;

       for (int i = 0; i < nums.size();  i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (lengthOfLongestSeq[j]+1 > lengthOfLongestSeq[i]){
                        lengthOfLongestSeq[i] = lengthOfLongestSeq[j]+1;
                        countOfLongestSeq[i] = countOfLongestSeq[j];
                    }
                    else if (lengthOfLongestSeq[j]+1 == lengthOfLongestSeq[i]){
                        countOfLongestSeq[i] += countOfLongestSeq[j];
                    }
                }
            }

            maxLen = max(maxLen, lengthOfLongestSeq[i]);
       }
        // count seq in the same length
        for (int i = 0; i < nums.size();  i++){
            if (lengthOfLongestSeq[i] == maxLen){
                maxSeq += countOfLongestSeq[i];
            }
        } 

       return maxSeq;
    }
};

//input -1 3 5 4 7

//len -  1 2 3 3 4
//count- 1 1 1 1 2