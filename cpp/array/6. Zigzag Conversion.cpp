#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.length()) return s; 
        
        vector<string> rows(numRows, "");
        int rowIndex=0, d = 1;
        for (char c : s) {
            rows[rowIndex] += c;
            if (rowIndex == 0)d=1;
            if (rowIndex == numRows-1)d=-1;
            rowIndex+=d;
        }

        string res;
        for(const string& row : rows) {
            res += row;
        }

        return res; 
    }
};