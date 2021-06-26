#include "example.h"

Dummy::Dummy() {

}

bool Dummy::doSomething() {
  
    constexpr int digits[2] = {0, 1};
    auto [zero, one] = digits;
    return zero + one;
}


#ifdef ENABLE_DOCTEST_IN_LIBRARY
#include "../tests/doctest/doctest.h"
TEST_CASE("we can have tests written here, to test impl. details")
{
    CHECK(true);
}
#endif
