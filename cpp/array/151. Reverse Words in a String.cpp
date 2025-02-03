#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // trim string 
        int curr = 0; 
        for (int i = 0; i < s.size(); i++){
            if (s[i] != ' ' || (curr > 0 && s[curr-1] != ' ')) s[curr++] = s[i]; 
        }
        s.resize(curr > 0  && s[curr-1] == ' ' ? curr-1 : curr);

        //reverse string 
        reverse(s.begin(), s.end());

        // reverse words
        int begin = 0;
        for (int i = 0; i <= s.size(); i++){
            if(s[i] == ' ' || i == s.size()){
                reverse(s.begin()+begin, s.begin()+i); 
                begin = i+1; 
            }
        }
        return s; 
    }

    string reverseWords2(string s) {
        string reverse = "";
        int beg = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                if (beg < i) {
                    string word = s.substr(beg, i - beg);
                    if (!reverse.empty()) reverse = " " + reverse;
                    reverse = word + reverse;
                }
                beg = i + 1;
            }
        }
        return reverse;
    }
};