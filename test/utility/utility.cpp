#include <type_traits>
#include <functional>
#include <utility.hpp>
#include <gtest/gtest.h>

using namespace stdext;

TEST(FUNCTION_PROXY, typename_alias) {
    using Func = void();

    ASSERT_TRUE((std::is_same<
                    std::function<Func>,
                    function_proxy_t<0, Func>
                 >::value));
}

TEST(FUNCTION_PROXY, type) {
    using FuncA = int(int, char, double);
    using FuncA0 = int();
    using FuncA1 = int(int);
    using FuncA2 = int(int, char);
    using FuncA3 = int(int, char, double);

    ASSERT_TRUE((std::is_same<
                    function_proxy_t<0, FuncA>,
                    std::function<FuncA0>
                 >::value));

    ASSERT_TRUE((std::is_same<
                    function_proxy_t<1, FuncA>,
                    std::function<FuncA1>
                 >::value));

    ASSERT_TRUE((std::is_same<
                    function_proxy_t<2, FuncA>,
                    std::function<FuncA2>
                 >::value));

    ASSERT_TRUE((std::is_same<
                    function_proxy_t<3, FuncA>,
                    std::function<FuncA3>
                 >::value));

    ASSERT_FALSE((std::is_same<
                    function_proxy_t<0, FuncA>,
                    function_proxy_t<2, FuncA>
                 >::value));
}
