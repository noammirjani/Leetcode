class Solution {
public:
    string reverseWords(string s) {
        // trim string - clean string [0 : slow]
        int slow = 0;
        for (int fast = 0; fast <s.size(); ++fast){
            if (s[fast] == ' '){
                if (slow > 0 && s[slow-1] != ' ') s[slow++] = ' ';
            }
            else {
                s[slow++] = s[fast];
            }
        }
        if (slow > 0 && s[slow - 1] == ' ') --slow;
        s.resize(slow);

        // reverse string
        reverse(s.begin(), s.begin()+slow);

        //reverse word
        int start = 0;
        for (int i = 0; i <= s.size(); ++i){
            if (s[i] == ' ' || i == s.size()){
                reverse(s.begin()+start, s.begin()+i);
                start = i+1;
            }
        }

        return s;
    }

     string reverseWords2(string s) {
         string reverse = "";
         int beg = 0;
         for (int i = 0; i <= s.size(); ++i){
             if (i == s.size() || s[i] == ' '){
                 if (beg < i) {
                     string word = s.substr(beg, i-beg);
                     if (!reverse.empty()) reverse = " " + reverse;
                     reverse = word + reverse;
                 }
                 beg = i+1;
             }
         }
         return reverse;
     }
};