#include <string>
#include <vector>

using namespace std;

// Complexity - time O(n), space O(1)(without the string result)
class Solution {
public:
    string smallestSubsequence(string s) {
       vector<int> freq (26, 0);
        vector<bool> existInStr(26, false); 
        string uniqueS; 

        for (char c: s) freq[c-'a']++;

        for(char c: s) {
            int cIndex = c-'a';
            freq[cIndex]--;
            if (existInStr[cIndex]) continue; 
            while (!uniqueS.empty() && uniqueS.back() > c && freq[uniqueS.back()-'a'] > 0){
                existInStr[uniqueS.back()-'a'] = false;
                uniqueS.pop_back(); 
            }
            uniqueS += c;
            existInStr[cIndex] = true; 
        }
        return uniqueS; 
    }
};