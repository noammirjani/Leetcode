#include <vector>
using namespace std;

class Solution {
public:
    /**
     * using counting sort 
     * @complexity
     * Time complexity: O(n), where n is the number of elements in the vector.
     * Space complexity: O(1), as it uses constant extra space.
     */
    void sortColors(vector<int>& nums) {
        vector<int> colors_freq (3, 0); 

        for (int color : nums) {
            colors_freq[color]++;
        }

        int index = 0;
        for (int color = 0; color < colors_freq.size(); color++) {
            while (colors_freq[color] > 0){
                nums[index] = color;
                colors_freq[color]--;
                index++;
            }
        }
    }
};
