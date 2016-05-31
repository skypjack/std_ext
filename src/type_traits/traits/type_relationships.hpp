#pragma once


#include "../details/details.hpp"
#include <type_traits>


namespace stdext {

/** \brief is_same_of_any
 *
 * \code{.cpp}
 * template<class T, class... O>
 * struct is_same_of_any;
 * \endcode
 *
 * If \c T and any of the \c O types are the same type, provides the member
 * constant \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using is_same_of_any = details::or2_<std::is_same, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool is_same_of_any_v = is_same_of_any<Args...>::value;

/** \brief is_same_of_all
 *
 * \code{.cpp}
 * template<class T, class... O>
 * struct is_same_of_all;
 * \endcode
 *
 * If \c T and all the \c O types are the same type, provides the member
 * constant \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using is_same_of_all = details::and2_<std::is_same, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool is_same_of_all_v = is_same_of_all<Args...>::value;

/** \brief are_all_same_of
 *
 * \code{.cpp}
 * template<class... O>
 * struct are_all_same_of;
 * \endcode
 *
 * If all the \c O types are the same type, provides the member constant
 * \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_all_same_of = is_same_of_all<Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_all_same_of_v = are_all_same_of<Args...>::value;

/** \brief is_base_of_any
 *
 * \code{.cpp}
 * template<class B, class... O>
 * struct is_base_of_any;
 * \endcode
 *
 * If any of the \c O types is derived from \c B, provides the member constant
 * \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using is_base_of_any = details::or2_<std::is_base_of, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool is_base_of_any_v = is_base_of_any<Args...>::value;

/** \brief is_base_of_all
 *
 * \code{.cpp}
 * template<class B, class... O>
 * struct is_base_of_all;
 * \endcode
 *
 * If all the \c O types are derived from \c B, provides the member constant
 * \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using is_base_of_all = details::and2_<std::is_base_of, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool is_base_of_all_v = is_base_of_all<Args...>::value;

/** \brief are_all_base_of
 *
 * \code{.cpp}
 * template<class D, class... O>
 * struct are_all_base_of;
 * \endcode
 *
 * If \c B is derived from all the \c O types, provides the member constant
 * \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_all_base_of = details::rev_and2_<std::is_base_of, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_all_base_of_v = are_all_base_of<Args...>::value;

/** \brief is_convertible_to_any
 *
 * \code{.cpp}
 * template<class F, class... O>
 * struct is_convertible_to_any;
 * \endcode
 *
 * If \c F is convertible to any of the \c O types, provides the member constant
 * \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using is_convertible_to_any = details::or2_<std::is_convertible, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool is_convertible_to_any_v = is_convertible_to_any<Args...>::value;

/** \brief is_convertible_to_all
 *
 * \code{.cpp}
 * template<class F, class... O>
 * struct is_convertible_to_all;
 * \endcode
 *
 * If \c F is convertible to all of the \c O types, provides the member constant
 * \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using is_convertible_to_all = details::and2_<std::is_convertible, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool is_convertible_to_all_v = is_convertible_to_all<Args...>::value;

/** \brief are_all_convertible_to
 *
 * \code{.cpp}
 * template<class T, class... O>
 * struct are_all_convertible_to;
 * \endcode
 *
 * If all the \c O types are convertible to \c T, provides the member constant
 * \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_all_convertible_to = details::rev_and2_<std::is_convertible, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_all_convertible_to_v =
        are_all_convertible_to<Args...>::value;

}
