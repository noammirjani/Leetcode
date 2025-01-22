#include <queue>
#include <vector>
#include <functional>

using namespace std;

class KthLargest {
private:
    int m_size; 
    std::priority_queue<int, std::vector<int>, std::greater<int>> m_heap;
public:
    KthLargest(int k, vector<int>& nums) {
        m_size = k; 
        for (auto num : nums) add(num);
    }
    
    int add(int val) {
        m_heap.push(val); 
        if (m_heap.size() > m_size)
            m_heap.pop(); 
        return m_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */