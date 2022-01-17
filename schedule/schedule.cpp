#include "schedule.hpp"
#include <chrono>
#include <thread>

template<typename function, typename duration, typename... argument>
auto schedule(function Func , duration durat, argument ...arg){
    std::this_thread::sleep_for(durat);
    Func(arg...);
}
