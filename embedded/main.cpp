#include <array>
#include <iostream>
#include <algorithm>
#include <bitset>

constexpr auto fxosc = 26000000;
constexpr size_t number_of_registers = 3;
std::array<uint8_t,number_of_registers> freq( uint64_t fcarrier) {
    auto calfreq = (fcarrier << 16)/fxosc;
    std::array <uint8_t,3> freqarr;
    freqarr[0] = (uint8_t)(calfreq & 0xff);
    freqarr[1] = (uint8_t)(calfreq >> 8) & 0xff;;
    freqarr[2] = (uint8_t)(calfreq >> 16) & 0xff;
    return freqarr;
}


int main() {
    auto array1 = freq(868000000);
    std::for_each(array1.begin(), array1.end(), [](const auto& el) {
        std::cout << "In binary:  " << std::bitset<8>{el} << '\n';
    });

return 0;
}