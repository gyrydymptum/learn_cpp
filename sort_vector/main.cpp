#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>

template <typename T>
void print(T toprint) {
    for (auto el : toprint){
        std::cout << el << " ";
    }
    std::cout << '\n';
}




// void sortVec(std::vector<int> vec) {
//     sort(vec)
// }

int main() {

std::vector<int> vec {1,2,21,34,21,33,22,6,35,66,8,4,23,44};



print(vec);

    return 0;
}