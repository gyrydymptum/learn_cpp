#include <array>
#include <iostream>
#include <algorithm>
#include <bitset>

constexpr auto fxosc = 26000000;

unsigned long long int calculateFreq(unsigned long long int fcarrier ) {
    return (fcarrier << 16)/fxosc;
}
std::array<uint8_t,3> freq( uint64_t calfreq) {
    std::array <uint8_t,3> freqarr;
    freqarr[0] = 1;
    freqarr[1] = 2;
    freqarr[2] = 3;
    return freqarr;
}

int main() {
    std::cout << calculateFreq(868000000) << '\n';
    auto array1 = freq(calculateFreq(868000000));
    std::for_each(array1.begin(), array1.end(), [](const auto& el) {
        std::cout << "In binary:  " << std::bitset<8>{el} << '\n';
    });

return 0;
}