#pragma once


#include "../details/details.hpp"
#include <type_traits>


namespace stdext {

/** \brief are_constructible
 *
 * \code{.cpp}
 * template<template<typename...> typename T, class... A>
 * struct are_constructible;
 * \endcode
 *
 * If all the \c T types are constructible from the \c A types, provides the
 * member constant \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_constructible = details::var_and2_<std::is_constructible, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_constructible_v = are_constructible<Args...>::value;

/** \brief are_trivially_constructible
 *
 * \code{.cpp}
 * template<template<typename...> typename T, class... A>
 * struct are_trivially_constructible;
 * \endcode
 *
 * If all the \c T types are trivially constructible from the \c A types,
 * provides the member constant \c value equal to true. Otherwise \c value is
 * false.
 */
template<class... Args>
using are_trivially_constructible =
details::var_and2_<std::is_trivially_constructible, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_trivially_constructible_v =
        are_trivially_constructible<Args...>::value;

/** \brief are_nothrow_constructible
 *
 * \code{.cpp}
 * template<template<typename...> typename T, class... A>
 * struct are_nothrow_constructible;
 * \endcode
 *
 * If all the \c T types are no throw constructible from the \c A types,
 * provides the member constant \c value equal to true. Otherwise \c value is
 * false.
 */
template<class... Args>
using are_nothrow_constructible =
details::var_and2_<std::is_nothrow_constructible, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_nothrow_constructible_v =
        are_nothrow_constructible<Args...>::value;

/** \brief are_default_constructible
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_default_constructible;
 * \endcode
 *
 * If all the \c T types are default constructible, provides the member constant
 * \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_default_constructible =
details::and1_<std::is_default_constructible, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_default_constructible_v =
        are_default_constructible<Args...>::value;

/** \brief are_trivially_default_constructible
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_trivially_default_constructible;
 * \endcode
 *
 * If all the \c T types are trivially default constructible, provides the
 * member constant \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_trivially_default_constructible =
details::and1_<std::is_trivially_default_constructible, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_trivially_default_constructible_v =
        are_trivially_default_constructible<Args...>::value;

/** \brief are_nothrow_default_constructible
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_nothrow_default_constructible;
 * \endcode
 *
 * If all the \c T types are no throw default constructible, provides the member
 * constant \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_nothrow_default_constructible =
details::and1_<std::is_nothrow_default_constructible, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_nothrow_default_constructible_v =
        are_nothrow_default_constructible<Args...>::value;

/** \brief are_copy_constructible
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_copy_constructible;
 * \endcode
 *
 * If all the \c T types are copy constructible, provides the member constant
 * \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_copy_constructible =
details::and1_<std::is_copy_constructible, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_copy_constructible_v =
        are_copy_constructible<Args...>::value;

/** \brief are_trivially_copy_constructible
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_trivially_copy_constructible;
 * \endcode
 *
 * If all the \c T types are trivially copy constructible, provides the member
 * constant \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_trivially_copy_constructible =
details::and1_<std::is_trivially_copy_constructible, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_trivially_copy_constructible_v =
        are_trivially_copy_constructible<Args...>::value;

/** \brief are_nothrow_copy_constructible
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_nothrow_copy_constructible;
 * \endcode
 *
 * If all the \c T types are no throw copy constructible, provides the member
 * constant \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_nothrow_copy_constructible =
details::and1_<std::is_nothrow_copy_constructible, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_nothrow_copy_constructible_v =
        are_nothrow_copy_constructible<Args...>::value;

/** \brief are_move_constructible
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_move_constructible;
 * \endcode
 *
 * If all the \c T types are move constructible, provides the member constant
 * \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_move_constructible =
details::and1_<std::is_move_constructible, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_move_constructible_v =
        are_move_constructible<Args...>::value;

/** \brief are_trivially_move_constructible
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_trivially_move_constructible;
 * \endcode
 *
 * If all the \c T types are trivially move constructible, provides the member
 * constant \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_trivially_move_constructible =
details::and1_<std::is_trivially_move_constructible, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_trivially_move_constructible_v =
        are_trivially_move_constructible<Args...>::value;

/** \brief are_nothrow_move_constructible
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_nothrow_move_constructible;
 * \endcode
 *
 * If all the \c T types are no throw move constructible, provides the member
 * constant \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_nothrow_move_constructible =
details::and1_<std::is_nothrow_move_constructible, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_nothrow_move_constructible_v =
        are_nothrow_move_constructible<Args...>::value;

}
