#include <tuple.hpp>
#include <gtest/gtest.h>

using namespace stdext;

struct U { };

struct T {
    T() = default;
    T(const T &) = delete;
    T(T &&) = default;
    T& operator=(const T &) = delete;
    T& operator=(T &&) = default;
};

int func(int a, int b) { return a+b; }

struct O {
    double operator()(double a, double b) { return a*b; }
};

TEST(TUPLE_TAIL, lvalue) {
    std::tuple<U, U, U> tup{};
    auto t = tail(tup);
    assert((std::is_same<decltype(t), std::tuple<U, U>>::value));
}

TEST(TUPLE_TAIL, rvalue) {
    std::tuple<T, T, T> tup{};
    auto t = tail(std::move(tup));
    assert((std::is_same<decltype(t), std::tuple<T, T>>::value));
}

TEST(TUPLE_INVOKE, function) {
    std::tuple<int, int> tup{ 40, 2 };
    auto ret = invoke(func, tup);
    assert(ret == 42);
}

TEST(TUPLE_INVOKE, functor) {
    std::tuple<double, double> tup{ 21, 2 };
    auto ret = invoke(O{}, tup);
    assert(ret == 42);
}

TEST(TUPLE_INVOKE, lambda) {
    std::tuple<int, int> tup{ 40, 2 };
    auto ret = invoke([](int a, int b){ return a+b; }, tup);
    assert(ret == 42);
}
