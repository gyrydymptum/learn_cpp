#include <algorithm>
#include <iostream>
#include <vector>

template <typename Key, typename Value>
class VectorMap {
    std::vector<Key> keys{};
    std::vector<Value> values{};

public:
    void insert(const Key& k, const Value& v) {
        keys.emplace_back(k);
        values.emplace_back(v);
    }

    Value& operator[](const Key& k) {
        for (size_t i = 0; i < keys.size(); ++i) {
            if (keys[i] == k) {
                return values[i];
            }
        }
        keys.emplace_back(k);
        values.emplace_back();
        return values.back();
    }

    Value& at(const Key& k) {
        for (size_t i = 0; i < keys.size(); ++i) {
            if (keys[i] == k) {
                return values[i];
            }
        }
        throw std::out_of_range{"not in map"};
    }
};

int main() {
    VectorMap<int, char> map;
    map.insert(1, 'e');
    map[1] = 'e';         // replaces value under 1
    std::cout << map[1];  // prints 'e'
                          // map.at(2);              // throw std::out_of_range
    map[2] = 'd';         // replaces value under 1
    std::cout << map[1];
    map.at(2);
    map.at(3);
    return 0;
}