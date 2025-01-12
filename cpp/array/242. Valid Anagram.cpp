#include <string>
#include <vector>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size())
            return false; 

        std::vector<int> ferq(26, 0); 
        int size = s.size(); 

        for (int i = 0; i < size; i++) {
            ferq[(int)s[i]-'a']++; 
            ferq[(int)t[i]-'a']--; 
        }
        
        for (int count : ferq){
            if (count != 0) 
                return false;
        }
        return true;
    }
};