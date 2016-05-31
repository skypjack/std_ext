#include "./common.h"

#define TEST_CASE_LABEL SUPPORTED_OPERATIONS

TEST(TEST_CASE_LABEL, are_constructible) {
    ASSERT_EQ((are_constructible<std::tuple<B>>::value),
              (are_constructible_v<std::tuple<B>>));
    ASSERT_FALSE((are_constructible_v<std::tuple<B>, int>));
    ASSERT_TRUE((are_constructible_v<std::tuple<A, B, D>>));
    ASSERT_FALSE((are_constructible_v<std::tuple<B, A>, D>));
}

TEST(TEST_CASE_LABEL, are_trivially_constructible) {
    ASSERT_EQ((are_trivially_constructible<std::tuple<B>>::value),
              (are_trivially_constructible_v<std::tuple<B>>));
    ASSERT_FALSE((are_trivially_constructible_v<std::tuple<B>, int>));
    ASSERT_TRUE((are_trivially_constructible_v<std::tuple<A, B, D>>));
    ASSERT_FALSE((are_trivially_constructible_v<std::tuple<B, A>, D>));
}

TEST(TEST_CASE_LABEL, are_nothrow_constructible) {
    ASSERT_EQ((are_nothrow_constructible<std::tuple<B>>::value),
              (are_nothrow_constructible_v<std::tuple<B>>));
    ASSERT_FALSE((are_nothrow_constructible_v<std::tuple<B>, int>));
    ASSERT_TRUE((are_nothrow_constructible_v<std::tuple<A, B, D>>));
    ASSERT_FALSE((are_nothrow_constructible_v<std::tuple<B, A>, D>));
}

TEST(TEST_CASE_LABEL, are_default_constructible) {
    ASSERT_EQ((are_default_constructible<A>::value),
              (are_default_constructible_v<A>));
    ASSERT_FALSE((are_default_constructible_v<T>));
    ASSERT_TRUE((are_default_constructible_v<A, B, D>));
    ASSERT_FALSE((are_default_constructible_v<B, S, D>));
}

TEST(TEST_CASE_LABEL, are_trivially_default_constructible) {
    ASSERT_EQ((are_trivially_default_constructible<A>::value),
              (are_trivially_default_constructible_v<A>));
    ASSERT_FALSE((are_trivially_default_constructible_v<T>));
    ASSERT_TRUE((are_trivially_default_constructible_v<A, B, D>));
    ASSERT_FALSE((are_trivially_default_constructible_v<B, S, D>));
}

TEST(TEST_CASE_LABEL, are_nothrow_default_constructible) {
    ASSERT_EQ((are_nothrow_default_constructible<A>::value),
              (are_nothrow_default_constructible_v<A>));
    ASSERT_FALSE((are_nothrow_default_constructible_v<T>));
    ASSERT_TRUE((are_nothrow_default_constructible_v<A, B, D>));
    ASSERT_FALSE((are_nothrow_default_constructible_v<B, S, D>));
}

TEST(TEST_CASE_LABEL, are_copy_constructible) {
    ASSERT_EQ((are_copy_constructible<A, B, D>::value),
              (are_copy_constructible_v<A, B, D>));
    ASSERT_FALSE((are_copy_constructible_v<S>));
    ASSERT_TRUE((are_copy_constructible_v<A, B, D>));
    ASSERT_FALSE((are_copy_constructible_v<A, S, D>));
}

TEST(TEST_CASE_LABEL, are_trivially_copy_constructible) {
    ASSERT_EQ((are_trivially_copy_constructible<A, B, D>::value),
              (are_trivially_copy_constructible_v<A, B, D>));
    ASSERT_FALSE((are_trivially_copy_constructible_v<S>));
    ASSERT_TRUE((are_trivially_copy_constructible_v<A, B, D>));
    ASSERT_FALSE((are_trivially_copy_constructible_v<A, S, D>));
}

TEST(TEST_CASE_LABEL, are_nothrow_copy_constructible) {
    ASSERT_EQ((are_nothrow_copy_constructible<A, B, D>::value),
              (are_nothrow_copy_constructible_v<A, B, D>));
    ASSERT_FALSE((are_nothrow_copy_constructible_v<S>));
    ASSERT_TRUE((are_nothrow_copy_constructible_v<A, B, D>));
    ASSERT_FALSE((are_nothrow_copy_constructible_v<A, S, D>));
}

TEST(TEST_CASE_LABEL, are_move_constructible) {
    ASSERT_EQ((are_move_constructible<S, B, T>::value),
              (are_move_constructible_v<S, B, T>));
    ASSERT_FALSE((are_move_constructible_v<S>));
    ASSERT_TRUE((are_move_constructible_v<A, D>));
    ASSERT_FALSE((are_move_constructible_v<T, S>));
}

TEST(TEST_CASE_LABEL, are_trivially_move_constructible) {
    ASSERT_EQ((are_trivially_move_constructible<S, B, T>::value),
              (are_trivially_move_constructible_v<S, B, T>));
    ASSERT_FALSE((are_trivially_move_constructible_v<S>));
    ASSERT_TRUE((are_trivially_move_constructible_v<A, D>));
    ASSERT_FALSE((are_trivially_move_constructible_v<T, S>));
}

TEST(TEST_CASE_LABEL, are_nothrow_move_constructible) {
    ASSERT_EQ((are_nothrow_move_constructible<S, B, T>::value),
              (are_nothrow_move_constructible_v<S, B, T>));
    ASSERT_FALSE((are_nothrow_move_constructible_v<S>));
    ASSERT_TRUE((are_nothrow_move_constructible_v<A, D>));
    ASSERT_FALSE((are_nothrow_move_constructible_v<T, S>));
}
