#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        int n = path.size();

        for (int i = 0, begin = 0; i <= n; i++) {
            if (i == n || path[i] == '/') {
                string temp = path.substr(begin, i - begin);
                if (temp == "..") {
                    if (!stack.empty())
                        stack.pop_back();
                }
                else if (temp != "." && !temp.empty())
                    stack.push_back(temp);
                begin = i+1;
            }
        }

        string res; 
        for (const auto &s : stack) res += "/" + s;
        return res.empty() ? "/" : res; 
    }
};