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
    print(sortVec(vec));

    return 0;
}