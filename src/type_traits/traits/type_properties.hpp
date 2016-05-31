#pragma once


#include "../details/details.hpp"
#include <type_traits>


namespace stdext {

/** \brief are_const
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_const;
 * \endcode
 *
 * If all the \c T types are const-qualified types (that is, const, or const
 * volatile), provides the member constant \c value equal to true. Otherwise
 * \c value is false.
 */
template<class... Args>
using are_const = details::and1_<std::is_const, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_const_v = are_const<Args...>::value;

/** \brief are_volatile
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_volatile;
 * \endcode
 *
 * If all the \c T types are volatile-qualified types (that is, volatile, or
 * const volatile), provides the member constant \c value equal to true.
 * Otherwise \c value is false.
 */
template<class... Args>
using are_volatile = details::and1_<std::is_volatile, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_volatile_v = are_volatile<Args...>::value;

/** \brief are_trivial
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_trivial;
 * \endcode
 *
 * If all the \c T types are trivial types (that is, a scalar type, a trivially
 * copyable class with a trivial default constructor, or array of such
 * type/class, possibly cv-qualified), provides the member constant \c value
 * equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_trivial = details::and1_<std::is_trivial, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_trivial_v = are_trivial<Args...>::value;

/** \brief are_trivially_copyable
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_trivially_copyable;
 * \endcode
 *
 * If all the \c T types are trivially copyable types, provides the member
 * constant \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_trivially_copyable =
details::and1_<std::is_trivially_copyable, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_trivially_copyable_v =
        are_trivially_copyable<Args...>::value;

/** \brief are_standard_layout
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_standard_layout;
 * \endcode
 *
 * If all the \c T types are standard layout types (that is, a scalar type, a
 * standard-layout class, or an array of such type/class, possibly
 * cv-qualified), provides the member constant \c value equal to true. Otherwise
 * \c value is false.
 */
template<class... Args>
using are_standard_layout = details::and1_<std::is_standard_layout, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_standard_layout_v = are_standard_layout<Args...>::value;

/** \brief are_pod
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_pod;
 * \endcode
 *
 * If all the \c T types are POD types (plain old data types, that is, both
 * trivial and standard-layout), provides the member constant \c value equal to
 * true. Otherwise \c value is false.
 */
template<class... Args>
using are_pod = details::and1_<std::is_pod, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_pod_v = are_pod<Args...>::value;

/** \brief are_literal_type
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_literal_type;
 * \endcode
 *
 * If all the \c T types are literal types, provides the member constant
 * \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_literal_type = details::and1_<std::is_literal_type, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_literal_type_v = are_literal_type<Args...>::value;

/** \brief are_empty
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_empty;
 * \endcode
 *
 * If all the \c T types are empty types (that is, a non-union class type with
 * no non-static data members other than bit-fields of size 0, no virtual
 * functions, no virtual base classes, and no non-empty base classes), provides
 * the member constant \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_empty = details::and1_<std::is_empty, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_empty_v = are_empty<Args...>::value;

/** \brief are_polymorphic
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_polymorphic;
 * \endcode
 *
 * If all the \c T types are polymorphic classes (that is, a non-union class
 * that declares or inherits at least one virtual function), provides the member
 * constant \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_polymorphic = details::and1_<std::is_polymorphic, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_polymorphic_v = are_polymorphic<Args...>::value;

/** \brief are_abstract
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_abstract;
 * \endcode
 *
 * If all the \c T types are abstract classes (that is, a non-union class that
 * declares or inherits at least one pure virtual function), provides the member
 * constant \c value equal to true. Otherwise \c value is false.
 */
template<class... Args>
using are_abstract = details::and1_<std::is_abstract, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_abstract_v = are_abstract<Args...>::value;

/** \brief are_signed
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_signed;
 * \endcode
 *
 * If all the \c T types are arithmetic types and \c U(-1) \c < \c U(0) for each
 * \c U type in \c T, provides the member constant \c value equal to true.
 * Otherwise \c value is false.
 */
template<class... Args>
using are_signed = details::and1_<std::is_signed, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_signed_v = are_signed<Args...>::value;

/** \brief are_unsigned
 *
 * \code{.cpp}
 * template<typename... T>
 * struct are_unsigned;
 * \endcode
 *
 * If all the \c T types are arithmetic types and \c U(0) \c < \c U(-1) for each
 * \c U type in \c T, provides the member constant \c value equal to true.
 * Otherwise \c value is false.
 */
template<class... Args>
using are_unsigned = details::and1_<std::is_unsigned, Args...>;

/** \brief Helper variable template
 */
template<class... Args>
constexpr bool are_unsigned_v = are_unsigned<Args...>::value;

}
