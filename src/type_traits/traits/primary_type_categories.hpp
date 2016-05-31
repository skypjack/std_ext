#pragma once


#include "../details/details.hpp"
#include <type_traits>


namespace stdext {

/** \brief are_void
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_void;
 * \endcode
 *
 * If all the \c T types are \c void, provides the member constant \c value
 * equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_void = details::and1_<std::is_void, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_void_v = are_void<Args...>::value;

/** \brief are_null_pointer
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_null_pointer;
 * \endcode
 *
 * If all the \c T types are \c std::nullptr_t, provides the member constant
 * \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_null_pointer = details::and1_<std::is_null_pointer, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_null_pointer_v = are_null_pointer<Args...>::value;

/** \brief are_integral
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_integral;
 * \endcode
 *
 * If all the \c T types are integral types, provides the member constant
 * \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_integral = details::and1_<std::is_integral, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_integral_v = are_integral<Args...>::value;

/** \brief are_floating_point
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_floating_point;
 * \endcode
 *
 * If all the \c T types are floating-point types, provides the member constant
 * \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_floating_point = details::and1_<std::is_floating_point, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_floating_point_v = are_floating_point<Args...>::value;

/** \brief are_array
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_array;
 * \endcode
 *
 * If all the \c T types are array types, provides the member constant \c value
 * equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_array = details::and1_<std::is_array, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_array_v = are_array<Args...>::value;

/** \brief are_enum
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_enum;
 * \endcode
 *
 * If all the \c T types are enumeration types, provides the member constant
 * \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_enum = details::and1_<std::is_enum, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_enum_v = are_enum<Args...>::value;

/** \brief are_union
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_union;
 * \endcode
 *
 * If all the \c T types are union types, provides the member constant \c value
 * equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_union = details::and1_<std::is_union, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_union_v = are_union<Args...>::value;

/** \brief are_class
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_class;
 * \endcode
 *
 * If all the \c T types are class or struct types, provides the member constant
 * \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_class = details::and1_<std::is_class, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_class_v = are_class<Args...>::value;

/** \brief are_function
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_function;
 * \endcode
 *
 * If all the \c T types are function types, provides the member constant
 * \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_function = details::and1_<std::is_function, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_function_v = are_function<Args...>::value;

/** \brief are_pointer
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_pointer;
 * \endcode
 *
 * If all the \c T types are pointers to objects or pointers to functions (but
 * not pointers to member/member functions), provides the member constant
 * \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_pointer = details::and1_<std::is_pointer, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_pointer_v = are_pointer<Args...>::value;

/** \brief are_lvalue_reference
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_lvalue_reference;
 * \endcode
 *
 * If all the \c T types are lvalue reference types, provides the member
 * constant \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_lvalue_reference = details::and1_<std::is_lvalue_reference, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_lvalue_reference_v = are_lvalue_reference<Args...>::value;

/** \brief are_rvalue_reference
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_rvalue_reference;
 * \endcode
 *
 * If all the \c T types are rvalue reference types, provides the member
 * constant \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_rvalue_reference = details::and1_<std::is_rvalue_reference, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_rvalue_reference_v = are_rvalue_reference<Args...>::value;

/** \brief are_member_object_pointer
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_member_object_pointer;
 * \endcode
 *
 * If all the \c T types are non-static member objects, provides the member
 * constant \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_member_object_pointer =
details::and1_<std::is_member_object_pointer, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_member_object_pointer_v =
        are_member_object_pointer<Args...>::value;

/** \brief are_member_function_pointer
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_member_function_pointer;
 * \endcode
 *
 * If all the \c T types are non-static member function pointers, provides the
 * member constant \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_member_function_pointer =
details::and1_<std::is_member_function_pointer, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_member_function_pointer_v =
        are_member_function_pointer<Args...>::value;

}
