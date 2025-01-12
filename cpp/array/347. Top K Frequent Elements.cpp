#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    // bucket sort base
    vector<int> topKFrequent(vector<int>& nums, int k){
        // get frequency
        unordered_map<int, int> freq; 
        for (int num : nums)
            freq[num]++; 
        
        // for each number (key), enter it inside the frequent cell (reverse order)
        vector<vector<int>> buckets (nums.size()+1);
        for (auto& entry : freq)
            buckets[nums.size() - entry.second].push_back(entry.first); 

        // iterates over buckets matrix and empty k elements
        vector<int> res;
        for (auto bucket : buckets)
            for (auto num : bucket)
            {
                res.push_back(num); 
                if (res.size() == k) return res; 
            }
        return res;
    }
    // [7,3,6,2,7,2,2] k = 2
    // {7:2, 3:1, 6:1, 2:3}         first stage
    // [[],[],[],[2],[7],[3, 6],[]] second stage
    // return 2, 7                  third stage


    // struct Comb{
    //     int freq; 
    //     int val; 
    //     Comb(int v, int f) : val(v), freq(f) {}
    // };

    // struct Compare {
    //     bool operator()(Comb& a, Comb& b){
    //         return a.freq > b.freq; 
    //     }
    // };
    
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map <int, int> freq;
    //     for (int num : nums)
    //         freq[num]++;
        
    //     // Min-heap to keep the top k elements
    //     priority_queue<Comb, vector<Comb>, Compare> heap;
    //     for (auto& entry : freq) {
    //         heap.push(Comb(entry.first, entry.second));
    //         if (heap.size() > k) 
    //             heap.pop();
    //     }

    //     vector<int> res;
    //     while (!heap.empty()) {
    //         res.push_back(heap.top().val);
    //         heap.pop();
    //     }

    //     return  res;
    // }
};