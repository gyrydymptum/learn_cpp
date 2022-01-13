#include "gtest/gtest.h"
# include "unique.hpp"

template <typename T>
class UniqueTest {
    public:
    UniqueTest(T value) : value(value){}
   
    auto& value() & { return value_; }
    const auto& value() const & { return value_; }
    auto value() && { return std::move(value_); }
    const auto&& value() const && { return std::move(value_); }

}



class UniqueTest : public ::testing::TestWithParam<TestParameters> {

};