#include <cstdlib>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

template <typename T>
class DataStructure {
    std::unordered_map<T, int> data_map;
    std::vector<T> data_vector;
public:
    DataStructure() {
        std::srand(std::time(0));
    }

    bool add(const T& num) {
        if (data_map.find(num) == data_map.end()) {
            data_vector.push_back(num);
            data_map[num] = data_vector.size() - 1;
            return true;
        }
        return false;
    }

    bool remove(const T& num) {
        if (data_map.find(num) != data_map.end()) {
            int last_element = data_vector.back();
            T last_element = data_vector.back();
            data_vector[idx] = last_element; // no need to swap, just update the current cell
            data_map[last_element] = idx;
            data_vector.pop_back();
            data_map.erase(num);
            return true; 
        }
        return false;
    }

    bool search(const T& num) const {
        return data_map.find(num) != data_map.end();
    }

    const T& getRandom() const {
        if (data_vector.empty()) throw std::runtime_error("Data structure is empty");
        int random_index = std::rand() % data_vector.size();
        return data_vector[random_index];
    }
};


int main() {
    DataStructure<int> ds;
    std::cout << "Random: " << ds.getRandom() << std::endl;
    std::cout << "Search 2: " << ds.search(2) << std::endl; // Output: Search 2: 0
    ds.add(2);
    ds.add(3);
    std::cout << "Random: " << ds.getRandom() << std::endl;
    ds.remove(2);
    std::cout << "Search 2: " << ds.search(2) << std::endl; // Output: Search 2: 0
    return 0;
}