#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(n)
    int longestPalindrome(string s) {
        unordered_set<char> charSet;
        int longest = 0;
        for (char c : s) {
            if (charSet.find(c) != charSet.end()) {
                charSet.erase(c);
                longest += 2;
            }
            else charSet.insert(c);
        }
        return charSet.size() > 0 ? longest+1 : longest;
    }

    // Time complexity: O(n)
    // Space complexity: O(1)
    int longestPalindrome(string s) {
       vector<int> freq(52, 0);

        for (char c : s) {
            freq[islower(c) ? c-'a' : c-'A'+26]++;
        }

        int longest = 0;
        bool even = true;
        for(int count : freq) {       
            if(count % 2 == 0)
                longest += count;
            else {
                longest += (count-1);
                even = false;
            }
        }
        return even ? longest : longest + 1; 
    }
};