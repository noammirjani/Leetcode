#include <string>
using namespace std;

class Solution {
public:
    void check(int left, int right, const string& s, int& startLongest, int& maxLength) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            if (right - left + 1 > maxLength) {
                startLongest = left;
                maxLength = right - left + 1;
            }
            left--;
            right++;
        }
    }
    string longestPalindrome(string s) {
        int startLongest = 0;
        int maxLength = 1;

        for (int i = 0; i < s.size(); i++) {
            check(i, i, s, startLongest, maxLength);       // Odd-length palindrome
            check(i, i + 1, s, startLongest, maxLength);   // Even-length palindrome
        }
        return s.substr(startLongest, maxLength);
    }
};