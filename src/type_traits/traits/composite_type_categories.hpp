#pragma once


#include "../details/details.hpp"
#include <type_traits>


namespace stdext {

/** \brief are_fundamental
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_fundamental;
 * \endcode
 *
 * If all the \c T types are fundamental types (that is, arithmetic type, void,
 * or nullptr_t), provides the member constant \c value equal to true. Otherwise
 * \c value is false.
 */
template<class... Args>
using are_fundamental = details::and1_<std::is_fundamental, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_fundamental_v = are_fundamental<Args...>::value;

/** \brief are_arithmetic
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_arithmetic;
 * \endcode
 *
 * If all the \c T types are arithmetic types (that is, an integral type or a
 * floating-point type), provides the member constant \c value equal to true.
 * Otherwise \c value is false.
 */
template<class... Args>
using are_arithmetic = details::and1_<std::is_arithmetic, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_arithmetic_v = are_arithmetic<Args...>::value;

/** \brief are_scalar
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_scalar;
 * \endcode
 *
 * If all the \c T types are scalar types (that is a possibly cv-qualified
 * arithmetic, pointer, pointer to member, enumeration, or std::nullptr_t
 * type), provides the member constant \c value equal to true. Otherwise
 * \c value is false.
 */
template<class... Args>
using are_scalar = details::and1_<std::is_scalar, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_scalar_v = are_scalar<Args...>::value;

/** \brief are_object
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_object;
 * \endcode
 *
 * If all the \c T types are object types (that is any possibly cv-qualified
 * type other than function, reference, or void types), provides the member
 * constant \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_object = details::and1_<std::is_object, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_object_v = are_object<Args...>::value;

/** \brief are_compound
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_compound;
 * \endcode
 *
 * If all the \c T types are compound types (that is, array, function, object
 * pointer, function pointer, member object pointer, member function pointer,
 * reference, class, union, or enumeration, including any cv-qualified
 * variants), provides the member constant \c value equal to true. Otherwise
 * \c value is false.
 */
template<class... Args>
using are_compound = details::and1_<std::is_compound, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_compound_v = are_compound<Args...>::value;

/** \brief are_reference
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_reference;
 * \endcode
 *
 * If all the \c T types are reference types (lvalue reference or rvalue
 * reference), provides the member constant \c value equal to true. Otherwise
 * \c value is false.
 */
template<class... Args>
using are_reference = details::and1_<std::is_reference, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_reference_v = are_reference<Args...>::value;

/** \brief are_member_pointer
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_member_pointer;
 * \endcode
 *
 * If all the \c T types are pointers to non-static member objects or pointers
 * to non-static member functions, provides the member constant \c value equal
 * to true. Otherwise \c value is false.
 */
template<class... Args>
using are_member_pointer = details::and1_<std::is_member_pointer, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_member_pointer_v = are_member_pointer<Args...>::value;

}
