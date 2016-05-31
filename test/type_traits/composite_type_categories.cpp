#include "./common.h"

#define TEST_CASE_LABEL COMPOSITE_TYPE_CATEGORIES

TEST(TEST_CASE_LABEL, are_fundamental) {
    ASSERT_EQ((are_fundamental<void, std::nullptr_t>::value),
              (are_fundamental_v<void, std::nullptr_t>));
    ASSERT_TRUE((are_fundamental_v<std::nullptr_t>));
    ASSERT_FALSE((are_fundamental_v<void, A, std::nullptr_t>));
    ASSERT_TRUE((are_fundamental_v<int, char, void, std::nullptr_t>));
}

TEST(TEST_CASE_LABEL, are_arithmetic) {
    ASSERT_EQ((are_arithmetic<std::nullptr_t>::value),
              (are_arithmetic_v<std::nullptr_t>));
    ASSERT_TRUE((are_arithmetic_v<float>));
    ASSERT_FALSE((are_arithmetic_v<int, char, A, double>));
    ASSERT_TRUE((are_arithmetic_v<int, char, float, double>));
}

TEST(TEST_CASE_LABEL, are_scalar) {
    ASSERT_EQ((are_scalar<E>::value), (are_scalar_v<E>));
    ASSERT_TRUE((are_scalar_v<E>));
    ASSERT_FALSE((are_scalar_v<A*, std::nullptr_t, int, B>));
    ASSERT_TRUE((are_scalar_v<B*, std::nullptr_t, E, void(B::*)()>));
}

TEST(TEST_CASE_LABEL, are_object) {
    ASSERT_EQ((are_object<std::nullptr_t>::value),
              (are_object_v<std::nullptr_t>));
    ASSERT_TRUE((are_object_v<A>));
    ASSERT_FALSE((are_object_v<A, B, D&, int>));
    ASSERT_TRUE((are_object_v<A, B, D, int>));
}

TEST(TEST_CASE_LABEL, are_compound) {
    ASSERT_EQ((are_compound<int[]>::value), (are_compound_v<int[]>));
    ASSERT_TRUE((are_compound_v<void(*)(int)>));
    ASSERT_FALSE((are_compound_v<A[], char, int(B::*)(char, float)>));
    ASSERT_TRUE((are_compound_v<A[], int(B::*)(char, float), D&, E>));
}

TEST(TEST_CASE_LABEL, are_reference) {
    ASSERT_EQ((are_reference<A&&>::value), (are_reference_v<A&&>));
    ASSERT_TRUE((are_reference_v<B&>));
    ASSERT_FALSE((are_reference_v<A&, B, D&&>));
    ASSERT_TRUE((are_reference_v<A&, B&&, D&>));
}

TEST(TEST_CASE_LABEL, are_member_pointer) {
    ASSERT_EQ((are_member_pointer<A&&>::value), (are_member_pointer_v<A&&>));
    ASSERT_TRUE((are_member_pointer_v<int(D::*)>));
    ASSERT_FALSE((are_member_pointer_v<void(A::*)(int), B>));
    ASSERT_TRUE((are_member_pointer_v<B(A::*)(D, D), char(B::*)>));
}
