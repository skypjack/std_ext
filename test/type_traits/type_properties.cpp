#include "./common.h"

#define TEST_CASE_LABEL TYPE_PROPERTIES

TEST(TEST_LABEL, are_const) {
    ASSERT_EQ((are_const<A * const>::value), (are_const_v<A * const>));
    ASSERT_TRUE((are_const_v<const A>));
    ASSERT_FALSE((are_const_v<A * const, const B *, const D>));
    ASSERT_TRUE((are_const_v<A * const, const B * const, const D>));
}

TEST(TEST_LABEL, are_volatile) {
    ASSERT_EQ((are_volatile<int>::value), (are_volatile_v<int>));
    ASSERT_TRUE((are_volatile_v<volatile char>));
    ASSERT_FALSE((are_volatile_v<volatile double, int, volatile float>));
    ASSERT_TRUE((are_volatile_v<volatile double,
                 volatile int, volatile float>));
}

TEST(TEST_LABEL, are_trivial) {
    ASSERT_EQ((are_trivial<A>::value), (are_trivial_v<A>));
    ASSERT_TRUE((are_trivial_v<A>));
    ASSERT_FALSE((are_trivial_v<A, B, S, D>));
    ASSERT_TRUE((are_trivial_v<A, int, B[], char[], D>));
}

TEST(TEST_LABEL, are_trivially_copyable) {
    ASSERT_EQ((are_trivially_copyable<int>::value),
              (are_trivially_copyable_v<int>));
    ASSERT_TRUE((are_trivially_copyable_v<A>));
    ASSERT_FALSE((are_trivially_copyable_v<A, B, S, D>));
    ASSERT_TRUE((are_trivially_copyable_v<A, int, B[], char[], D>));
}

TEST(TEST_LABEL, are_standard_layout) {
    ASSERT_EQ((are_standard_layout<A>::value), (are_standard_layout_v<A>));
    ASSERT_TRUE((are_standard_layout_v<float[]>));
    ASSERT_FALSE((are_standard_layout_v<A, int[], B[], S>));
    ASSERT_TRUE((are_standard_layout_v<A, int[], B[]>));
}

TEST(TEST_LABEL, are_pod) {
    ASSERT_EQ((are_pod<char>::value), (are_pod_v<char>));
    ASSERT_TRUE((are_pod_v<A>));
    ASSERT_FALSE((are_pod_v<S>));
    ASSERT_TRUE((are_pod_v<A, int, B, char[], D>));
}

TEST(TEST_LABEL, are_literal_type) {
    ASSERT_EQ((are_literal_type<B>::value), (are_literal_type_v<B>));
    ASSERT_TRUE((are_literal_type_v<A>));
    ASSERT_FALSE((are_literal_type_v<A, B, D, S>));
    ASSERT_TRUE((are_literal_type_v<A, int, E, B, U, char[], D>));
}

TEST(TEST_LABEL, are_empty) {
    ASSERT_EQ((are_empty<A, B, D>::value), (are_empty_v<A, B, D>));
    ASSERT_TRUE((are_empty_v<B>));
    ASSERT_FALSE((are_empty_v<S>));
    ASSERT_TRUE((are_empty_v<A, B, D>));
}

TEST(TEST_LABEL, are_polymorphic) {
    ASSERT_EQ((are_polymorphic<S, T>::value), (are_polymorphic_v<S, T>));
    ASSERT_TRUE((are_polymorphic_v<T>));
    ASSERT_FALSE((are_polymorphic_v<S, B, T>));
    ASSERT_TRUE((are_polymorphic_v<S, T>));
}

TEST(TEST_LABEL, are_abstract) {
    ASSERT_EQ((are_abstract<A, B, D>::value), (are_abstract_v<A, B, D>));
    ASSERT_TRUE((are_abstract_v<S>));
    ASSERT_FALSE((are_abstract_v<T>));
    ASSERT_TRUE((are_abstract_v<S, S, S>));
}

TEST(TEST_LABEL, are_signed) {
    ASSERT_EQ((are_signed<float>::value), (are_signed_v<float>));
    ASSERT_TRUE((are_signed_v<int>));
    ASSERT_FALSE((are_signed_v<float, bool, int>));
    ASSERT_TRUE((are_signed_v<int, float>));
}

TEST(TEST_LABEL, are_unsigned) {
    ASSERT_EQ((are_unsigned<char>::value), (are_unsigned_v<char>));
    ASSERT_TRUE((are_unsigned_v<unsigned int>));
    ASSERT_FALSE((are_unsigned_v<bool, int, unsigned int>));
    ASSERT_TRUE((are_unsigned_v<bool ,unsigned int>));
}
