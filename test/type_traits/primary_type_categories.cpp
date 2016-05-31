#include "./common.h"

#define TEST_CASE_LABEL PRIMARY_TYPE_CATEGORIES

TEST(TEST_CASE_LABEL, are_void) {
    ASSERT_EQ((are_void<void, B>::value), (are_void_v<void, B>));
    ASSERT_TRUE((are_void_v<void>));
    ASSERT_FALSE((are_void_v<void, B, void>));
    ASSERT_TRUE((are_void_v<void, void, void>));
}

TEST(TEST_CASE_LABEL, are_null_pointer) {
    ASSERT_EQ((are_null_pointer<decltype(nullptr)>::value),
              (are_null_pointer_v<decltype(nullptr)>));
    ASSERT_TRUE((are_null_pointer_v<std::nullptr_t>));
    ASSERT_FALSE((are_null_pointer_v<void, decltype(nullptr), void>));
    ASSERT_TRUE((are_null_pointer_v<std::nullptr_t, std::nullptr_t>));
}

TEST(TEST_CASE_LABEL, are_integral) {
    ASSERT_EQ((are_integral<void, A>::value), (are_integral_v<void, A>));
    ASSERT_TRUE((are_integral_v<int>));
    ASSERT_FALSE((are_integral_v<A, B, bool, int, char, D>));
    ASSERT_TRUE((are_integral_v<bool, int, char, long, short>));
}

TEST(TEST_CASE_LABEL, are_floating_point) {
    ASSERT_EQ((are_floating_point<float>::value),
              (are_floating_point_v<float>));
    ASSERT_TRUE((are_floating_point_v<double>));
    ASSERT_FALSE((are_floating_point_v<float, double, int, long double>));
    ASSERT_TRUE((are_floating_point_v<float, double, long double>));
}

TEST(TEST_CASE_LABEL, are_array) {
    ASSERT_EQ((are_array<A[3]>::value), (are_array_v<A[3]>));
    ASSERT_TRUE((are_array_v<int[]>));
    ASSERT_FALSE((are_array_v<float[], B>));
    ASSERT_TRUE((are_array_v<D[], float[1], int[3], D[42]>));
}

TEST(TEST_CASE_LABEL, are_enum) {
    ASSERT_EQ((are_enum<int, float>::value), (are_enum_v<int, float>));
    ASSERT_TRUE((are_enum_v<E>));
    ASSERT_FALSE((are_enum_v<E, int, E>));
    ASSERT_TRUE((are_enum_v<E, E, E>));
}

TEST(TEST_CASE_LABEL, are_union) {
    ASSERT_EQ((are_union<U>::value), (are_union_v<U>));
    ASSERT_TRUE((are_union_v<U>));
    ASSERT_FALSE((are_union_v<U, E>));
    ASSERT_TRUE((are_union_v<U, U, U>));
}

TEST(TEST_CASE_LABEL, are_class) {
    ASSERT_EQ((are_class<A, B, D>::value), (are_class_v<A, B, D>));
    ASSERT_TRUE((are_class_v<B>));
    ASSERT_FALSE((are_class_v<B, U, A, E, D>));
    ASSERT_TRUE((are_class_v<A, B, D>));
}

TEST(TEST_CASE_LABEL, are_function) {
    ASSERT_EQ((are_function<A, E>::value), (are_function_v<A, E>));
    ASSERT_TRUE((are_function_v<decltype(f)>));
    ASSERT_FALSE((are_function_v<decltype(f), U, void()>));
    ASSERT_TRUE((are_function_v<int(double, char), decltype(f)>));
}

TEST(TEST_CASE_LABEL, are_pointer) {
    ASSERT_EQ((are_pointer<A*>::value), (are_pointer_v<A*>));
    ASSERT_TRUE((are_pointer_v<decltype(&f)>));
    ASSERT_FALSE((are_pointer_v<A*, decltype(f), B*>));
    ASSERT_TRUE((are_pointer_v<decltype(&f), A*, B*>));
}

TEST(TEST_CASE_LABEL, are_lvalue_reference) {
    ASSERT_EQ((are_lvalue_reference<std::nullptr_t>::value),
              (are_lvalue_reference_v<std::nullptr_t>));
    ASSERT_TRUE((are_lvalue_reference_v<B&>));
    ASSERT_FALSE((are_lvalue_reference_v<A, B&, D&&>));
    ASSERT_TRUE((are_lvalue_reference_v<A&, B&, D&>));
}

TEST(TEST_CASE_LABEL, are_rvalue_reference) {
    ASSERT_EQ((are_rvalue_reference<std::nullptr_t>::value),
              (are_rvalue_reference_v<std::nullptr_t>));
    ASSERT_TRUE((are_rvalue_reference_v<B&&>));
    ASSERT_FALSE((are_rvalue_reference_v<A, B&, D&&>));
    ASSERT_TRUE((are_rvalue_reference_v<A&&, B&&, D&&>));
}

TEST(TEST_CASE_LABEL, are_member_object_pointer) {
    ASSERT_EQ((are_member_object_pointer<int(A::*)>::value),
              (are_member_object_pointer_v<int(A::*)>));
    ASSERT_TRUE((are_member_object_pointer_v<int(B::*)>));
    ASSERT_FALSE((are_member_object_pointer_v<int(A::*),
                  int(B::*)(void), int(D::*)>));
    ASSERT_TRUE((are_member_object_pointer_v<int(A::*), int(B::*), int(D::*)>));
}

TEST(TEST_CASE_LABEL, are_member_function_pointer) {
    ASSERT_EQ((are_member_function_pointer<void(B::*)()>::value),
              (are_member_function_pointer_v<void(B::*)()>));
    ASSERT_TRUE((are_member_function_pointer_v<decltype(&B::f)>));
    ASSERT_FALSE((are_member_function_pointer_v<void(A::*)(char, int),
                  decltype(f), void(D::*)(double)>));
    ASSERT_TRUE((are_member_function_pointer_v<int(A::*)(),
                 int(B::*)(), int(D::*)()>));
}
