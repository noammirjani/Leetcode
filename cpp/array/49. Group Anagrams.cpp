#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string getFreqKey(const string& s) {
        vector<int> letters(26, 0);
        string key;
        for (char c : s)
            letters[c - 'a']++;
        for (int count : letters) {
            key += to_string(count) + '#';
        }
        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;

        for (string& s : strs) {
            vector<int> letters(26, 0);
            string key;
            for (char c : s)
                letters[c - 'a']++;
            for (int count : letters) {
                key += to_string(count) + '#';
            }
            anagrams[key].push_back(s);
        }

        vector<vector<string>> ret;
        for (const auto& [key, val] : anagrams) {
            ret.push_back(val);
        }
        return ret;
    }
};