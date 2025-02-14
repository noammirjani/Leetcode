#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Solution {
public:

    //not good enough - O(n^2) in worst case
    vector<int> quickSort(vector<int>& nums, int low = 0, int high = -1) {
        if (high == -1)high = nums.size() - 1;

        if (low < high) {
            int pivot = low + rand() % (high - low + 1);
            swap(nums[pivot], nums[high]);
            pivot = partition(nums, low, high); // new location
            quickSort(nums, low, pivot - 1);
            quickSort(nums, pivot + 1, high);
        }
        return nums;
    }

    int partition(vector<int>& nums, int low, int high) {
        int i = low - 1;
        int pivot = nums[high];
        for (int j = low; j < high; j++) {
            if (nums[j] <= pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        // return pivot to its place
        swap(nums[i + 1], nums[high]);
        return i + 1;
    }
};