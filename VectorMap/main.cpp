#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>

template <typename Key, typename Value>
class VectorMap {
    static_assert(std::is_default_constructible<Value>::value, "No a default C-tor ");
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

    bool isIntKey() const {
        if (std::is_same<Key, int>::value) {
            return true;
        }
        return false;
    }
};

class WithoutDefaultCtor {
    WithoutDefaultCtor() = default;
};

int main() {
    // VectorMap<int, WithoutDefaultCtor> mapWithAssert;
    VectorMap<int, char> map1;
    std::cout << std::boolalpha << map1.isIntKey() << '\n';
     VectorMap<unsigned, char> map2;
    std::cout << std::boolalpha << map2.isIntKey() << '\n';
    map1.insert(1, 'e');
    map1[1] = 'e';        
    std::cout << map1[1];
    map1[2] = 'd';         
    std::cout << map1[1];
    // map.at(2);
    // map.at(3);
    std::cout << '\n';
    return 0;
}