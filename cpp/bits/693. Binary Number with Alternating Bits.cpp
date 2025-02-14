class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool prev = n&1; 
        n >>= 1;
        
        while (n > 0) {
            if (prev == (n&1)) return false; 
            
            prev = (n&1);
            n >>= 1; 
        }
        return true;
    }
};