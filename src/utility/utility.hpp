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


/** \brief Helper type template
 */
template<typename T, typename U>
struct types {
    using basic = T;
    using decorated = U;
};

namespace details {

/** \internal */
static constexpr std::size_t max_depth = 42;

/** \internal */
template<std::size_t N>
struct choice: choice<N-1> {};

/** \internal */
template<>
struct choice<0> {};

/** \internal */
template<typename T, typename U>
constexpr auto
inherit_from(choice<0>) { return types<T, U>{}; }

/** \internal */
template<typename T, typename U,
    typename = std::enable_if_t<std::is_pointer<T>::value>>
constexpr auto inherit_from(choice<1>) {
    auto t = inherit_from<std::remove_pointer_t<T>, U>(choice<max_depth>{});
    using B = typename decltype(t)::basic;
    using D = typename decltype(t)::decorated;
    return types<B, std::add_pointer_t<D>>{};
}

/** \internal */
template<typename T, typename U,
    typename = std::enable_if_t<std::is_lvalue_reference<T>::value>>
constexpr auto inherit_from(choice<2>) {
    auto t = inherit_from<std::remove_reference_t<T>, U>(choice<max_depth>{});
    using B = typename decltype(t)::basic;
    using D = typename decltype(t)::decorated;
    return types<B, std::add_lvalue_reference_t<D>>{};
}

/** \internal */
template<typename T, typename U,
    typename = std::enable_if_t<std::is_rvalue_reference<T>::value>>
constexpr auto inherit_from(choice<3>) {
    auto t = inherit_from<std::remove_reference_t<T>, U>(choice<max_depth>{});
    using B = typename decltype(t)::basic;
    using D = typename decltype(t)::decorated;
    return types<B, std::add_rvalue_reference_t<D>>{};
}

/** \internal */
template<typename T, typename U,
    typename = std::enable_if_t<std::is_array<T>::value>>
constexpr auto inherit_from(choice<4>) {
    auto t = inherit_from<std::remove_extent_t<T>, U>(choice<max_depth>{});
    using B = typename decltype(t)::basic;
    using D = typename decltype(t)::decorated;
    return types<B, std::conditional_t<(0==std::extent<T>::value), D[], D[std::extent<T>::value]>>{};
}

/** \internal */
template<typename T, typename U,
    typename = std::enable_if_t<std::is_const<T>::value>>
constexpr auto inherit_from(choice<5>) {
    auto t = inherit_from<std::remove_const_t<T>, U>(choice<max_depth>{});
    using B = typename decltype(t)::basic;
    using D = typename decltype(t)::decorated;
    return types<B, std::add_const_t<D>>{};
}

/** \internal */
template<typename T, typename U,
    typename = std::enable_if_t<std::is_volatile<T>::value>>
constexpr auto inherit_from(choice<6>) {
    auto t = inherit_from<std::remove_volatile_t<T>, U>(choice<max_depth>{});
    using B = typename decltype(t)::basic;
    using D = typename decltype(t)::decorated;
    return types<B, std::add_volatile_t<D>>{};
}

}

/** \brief Inherit all the inheritable from one type.
 *
 * In this case, an example is worth a thousand words:
 * `inherit_from_t<const int ** const &&, char>` will return
 * `types<int, const char ** const &&>`.<br/>
 * That's all, pretty much.
 */
template<typename T, typename U = char>
constexpr auto inherit_from() {
    return inherit_from<T, U>(details::choice<details::max_depth>{});
}

/** \brief Helper type template
 */
template<typename T, typename U = char>
using inherit_from_t = decltype(inherit_from<T, U>());

/** \brief Helper type template
 */
template<typename T, typename U = char>
using inherit_from_basic_t =
typename decltype(inherit_from<T, U>())::basic;

/** \brief Helper type template
 */
template<typename T, typename U = char>
using inherit_from_decorated_t =
typename decltype(inherit_from<T, U>())::decorated;

}
