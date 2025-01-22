#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class RandomizedSet {
private:
    std::unordered_map<int, int> m_map;
    std::vector<int> m_arr; 

public:
       RandomizedSet() {
        srand(time(NULL)); // Seed the random number generator
    }

    bool insert(int val) {
        if (m_map.find(val) != m_map.end()) return false;
        m_arr.push_back(val);
        m_map[val] = m_arr.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (m_map.find(val) == m_map.end()) return false;
        int idx = m_map[val], lastIdx = m_arr.size() - 1;

        std::swap(m_arr[idx], m_arr[lastIdx]);
        m_map[m_arr[idx]] = idx;
        m_map.erase(val);
        m_arr.pop_back();
        return true;
    }

    int getRandom() {
        return m_arr[rand() % m_arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */