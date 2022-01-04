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

std::cout << "test:  " <<'\n';
std::array<uint8_t, number_of_registers> test1{0x62, 0xA7, 0x10};
std::array<uint8_t, number_of_registers> test2{0x76, 0x62, 0x21};
std::array<uint8_t, number_of_registers> test3{0x3B, 0xB1, 0x22};
std::array<uint8_t, number_of_registers> test4{0xC4, 0x4E, 0x23};

if(freq(433000000) ==  test1){std::cout << "ok " << '\n';};
if(freq(868000000) ==  test2){std::cout << "ok " << '\n';};
if(freq(902000000) ==  test3){std::cout << "ok " << '\n';};
if(freq(918000000) ==  test4){std::cout << "ok " << '\n';};
if(freq(918000000) ==  test1){std::cout << "no " << '\n';};

return 0;
}