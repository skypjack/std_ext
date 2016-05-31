#pragma once


#include <type_traits>
#include <utility>
#include <tuple>


namespace stdext {

namespace details {

/** \internal */
template<typename H, typename... T, typename U, std::size_t... I>
constexpr std::enable_if_t<
    std::is_same<
        std::remove_reference_t<std::remove_cv_t<U>>,
        std::tuple<H, T...>
    >::value,
    std::tuple<T...>
> tail(U &&tup, std::index_sequence<I...>) {
    return std::make_tuple(std::get<I+1>(std::forward<U>(tup))...);
}

/** \internal */
template<typename F, typename... T, std::size_t... I>
decltype(auto) invoke(F &&f, std::tuple<T...> &tup, std::index_sequence<I...>)
-> decltype(std::forward<F>(f)(std::get<I>(tup)...)) {
    return std::forward<F>(f)(std::get<I>(tup)...);
}

}

/** \brief Return the tail of a tuple.
 *
 * This function returns the tail of a tuple.
 * The elements are constructed by copy.
 *
 * \param tup An lvalue reference to the original tuple.
 * \return The tail of the given tuple.
 */
template<typename H, typename... T>
constexpr std::tuple<T...> tail(std::tuple<H, T...> &tup) {
    return details::tail<H, T...>(tup,
                                  std::make_index_sequence<sizeof...(T)>{});
}

/** \brief Return the tail of a tuple.
 *
 * This function returns the tail of a tuple.
 * The elements are constructed by move.
 *
 * \param tup An rvalue reference to the original tuple.
 * \return The tail of the given tuple.
 */
template<typename H, typename... T>
constexpr std::tuple<T...> tail(std::tuple<H, T...> &&tup) {
    return details::tail<H, T...>(std::move(tup),
                                  std::make_index_sequence<sizeof...(T)>{});
}

/** \brief Invoke a callable with the unpacked tuple.
 *
 * This function invokes a callable object and uses the unpacked tuple as a list
 * of arguments.
 *
 * \param f A callable object.
 * \param tup The packed list of arguments.
 * \return The resulting value from the invokation.
 */
template<typename F, typename... T>
constexpr decltype(auto) invoke(F &&f, std::tuple<T...> &tup) {
    return details::invoke(std::forward<F>(f), tup,
                           std::make_index_sequence<sizeof...(T)>{});
}

}
