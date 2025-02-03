#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> payments(days.back()+1, 0); 
        payments[1] = costs[1];
        int day = 0;
        
       for (int i = 1; i < payments.size(); i++) {
            if (i == days[day]) {
                payments[i] = min({payments[i - 1] + costs[0],
                                payments[max(0, i - 7)] + costs[1],
                                payments[max(0, i - 30)] + costs[2]});
                day++;
            } else {
                payments[i] = payments[i - 1];
            }
        }
        return payments.back(); 
    }
};
