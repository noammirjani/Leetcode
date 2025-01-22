#include <unordered_map>
#include <list>
#include <utility>

using namespace std;

class LRUCache {
private:
    unordered_map<int, pair<int, list<int>::iterator>> m_cache;
    list<int> m_priority; 
    int m_capacity;
public:
    LRUCache(int capacity) : m_capacity(capacity) {}
    
    int get(int key) {
        if (m_cache.find(key) == m_cache.end()) return -1; 

        m_priority.erase(m_cache[key].second);          // delete node
        m_priority.push_front(key);                     // add as a head
        m_cache[key].second = m_priority.begin();       // update the iterator
        return m_cache[key].first; 
    }
    
    void put(int key, int value) {
        if (m_cache.find(key) != m_cache.end()) {
            m_priority.erase(m_cache[key].second);
        } else if (m_priority.size() >= m_capacity) {
            int keyToRemove = m_priority.back();
            m_priority.pop_back();
            m_cache.erase(keyToRemove);
        }
        m_priority.push_front(key);
    }
};

// proiiotiry queue <pair<key, proirity>> - min proirity 

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */