#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

template <typename T>
void print(T toprint) {
    for (auto el : toprint) {
        std::cout << el << " ";
    }
    std::cout << '\n';
}

std::vector<int> sortVec(std::vector<int> & vec) {
    std::sort(begin(vec), end(vec), [](int lhs, int rhs) {
        if (lhs % 2 == 0 && rhs % 2 != 0) {
            return true;
        } else if (lhs % 2 != 0 && rhs % 2 == 0) {
            return false;
        } else {
            return lhs < rhs;
        }
    });
    return vec;
}

int main() {
    std::vector<int> vec{1, 2, 21, 34, 21, 33, 22, 6, 35, 66, 8, 4, 23, 44};
    print(vec);
    sortVec(vec);
    print(vec);
    std::vector<int> v2{3, 7, 8, 2, 19, 15, 11, 4};
    print(v2);
    std::sort(v2.begin(), v2.end());
    print(v2);
    std::stable_partition(v2.begin(), v2.end(), [](int x) { return x % 2 == 0; });
    print(v2);
    return 0;
}