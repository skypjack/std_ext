#pragma once


#include <type_traits>
#include <functional>
#include <utility>
#include <cstddef>
#include <tuple>


namespace stdext {

namespace details {

/** \internal */
template<
    typename R,
    typename... A,
    std::size_t... I
> constexpr auto
func(std::integer_sequence<std::size_t, I...>) {
    static_assert((sizeof...(I)<=sizeof...(A)), "!");
    return std::function<R(std::tuple_element_t<I, std::tuple<A...>>...)>{};
}

}

/** \brief Define a function type with limited arguments.
 *
 * Given a number of parameters \c N and a function type \c F, \c function_proxy
 * has a public member alias \c type equal to a function \c G that has the same
 * return type of \c F and \c N arguments having the same types of the first
 * \c N arguments of \c F.
 */
template<std::size_t, typename>
struct function_proxy;

/** \brief Define a function type with limited arguments.
 *
 * \sa function_proxy
 */
template<std::size_t N, typename R, typename... A>
struct function_proxy<N, R(A...)> {
    using type =
    decltype(details::func<R, A...>(std::make_index_sequence<N>{}));

    static constexpr std::size_t Size = N;
};

/** \brief Helper type template
 */
template<std::size_t N, typename F>
using function_proxy_t = typename function_proxy<N, F>::type;

}
