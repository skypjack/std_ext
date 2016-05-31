#pragma once


#include <type_traits>


namespace stdext {

namespace details {

/** \brief Utility class.
 *
 * and1_
 */

template<template<typename...> class, class...>
struct and1_;

template<template<typename...> class F, class T, class... O>
struct and1_<F, T, O...>: std::conditional_t<F<T>::value, and1_<F, O...>, std::false_type> { };

template<template<typename...> class F>
struct and1_<F>: std::true_type { };

/** \brief Utility class.
 *
 * and2_
 */

template<template<typename...> class, class...>
struct and2_;

template<template<typename...> class F, class T, class U, class... O>
struct and2_<F, T, U, O...>: std::conditional_t<F<T, U>::value, and2_<F, T, O...>, std::false_type> { };

template<template<typename...> class F, class T>
struct and2_<F, T>: std::true_type { };

/** \brief Utility class.
 *
 * var_and2_
 */

template<template<typename...> class, class...>
struct var_and2_;

template<template<typename...> class F, class T, class... U, template<typename...> class C, typename... A>
struct var_and2_<F, C<T, U...>, A...>
        : std::conditional_t<F<T, A...>::value, var_and2_<F, C<U...>, A...>, std::false_type>
{ };

template<template<typename...> class F, template<typename...> class C, typename... A>
struct var_and2_<F, C<>, A...>: std::true_type
{ };

/** \brief Utility class.
 *
 * rev_and2_
 */

template<template<typename...> class, class...>
struct rev_and2_;

template<template<typename...> class F, class T, class U, class... O>
struct rev_and2_<F, T, U, O...>: std::conditional_t<F<U, T>::value, rev_and2_<F, T, O...>, std::false_type> { };

template<template<typename...> class F, class T>
struct rev_and2_<F, T>: std::true_type { };

/** \brief Utility class.
 *
 * or2_
 */

template<template<typename...> class, class...>
struct or2_;

template<template<typename...> class F, class T, class U, class... O>
struct or2_<F, T, U, O...>: std::conditional_t<F<T, U>::value, std::true_type, or2_<F, T, O...>> { };

template<template<typename...> class F, class T>
struct or2_<F, T>: std::false_type { };

}

}
