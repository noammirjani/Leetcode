class Solution {
public:
    bool isPowerOfTwo(int n) {
        int amount = 0;
        while(n > 0) {
            amount += (n&1);
            n >>= 1;
        }
        return amount == 1; 
    }
};

// 1 10 100 1000 