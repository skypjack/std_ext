#include "./common.h"

#define TEST_CASE_LABEL TYPE_RELATIONSHIPS

TEST(TEST_LABEL, is_same_of_any) {
    ASSERT_EQ((is_same_of_any<B, B>::value), (is_same_of_any_v<B, B>));
    ASSERT_FALSE(is_same_of_any_v<B>);
    ASSERT_TRUE((is_same_of_any_v<B, D, B, A>));
    ASSERT_FALSE((is_same_of_any_v<B, A, D>));
}

TEST(TEST_LABEL, is_same_of_all) {
    ASSERT_EQ((is_same_of_all<B, B>::value), (is_same_of_all_v<B, B>));
    ASSERT_TRUE(is_same_of_all_v<B>);
    ASSERT_TRUE((is_same_of_all_v<B, B, B, B>));
    ASSERT_FALSE((is_same_of_all_v<B, B, A, D>));
}

TEST(TEST_LABEL, are_all_same_of) {
    ASSERT_EQ((are_all_same_of<B, B>::value), (are_all_same_of_v<B, B>));
    ASSERT_TRUE(are_all_same_of_v<B>);
    ASSERT_TRUE((are_all_same_of_v<B, B, B, B>));
    ASSERT_FALSE((are_all_same_of_v<B, B, A, D>));
}

TEST(TEST_LABEL, is_base_of_any) {
    ASSERT_EQ((is_base_of_any<B, D>::value), (is_base_of_any_v<B, D>));
    ASSERT_FALSE(is_base_of_any_v<B>);
    ASSERT_TRUE((is_base_of_any_v<B, B, A>));
    ASSERT_TRUE((is_base_of_any_v<B, A, D>));
    ASSERT_FALSE((is_base_of_any_v<B, A>));
}

TEST(TEST_LABEL, is_base_of_all) {
    ASSERT_EQ((is_base_of_all<B, B>::value), (is_base_of_all_v<B, B>));
    ASSERT_TRUE(is_base_of_all_v<B>);
    ASSERT_FALSE((is_base_of_all_v<B, A, B, D>));
    ASSERT_TRUE((is_base_of_all_v<B, B, D>));
}

TEST(TEST_LABEL, are_all_base_of) {
    ASSERT_EQ((are_all_base_of<B, A>::value), (are_all_base_of_v<B, A>));
    ASSERT_TRUE(are_all_base_of_v<B>);
    ASSERT_FALSE((are_all_base_of_v<D, A, B, D>));
    ASSERT_TRUE((are_all_base_of_v<D, D, B>));
}

TEST(TEST_LABEL, is_convertible_to_any) {
    ASSERT_EQ((is_convertible_to_any<B, A>::value), (is_convertible_to_any_v<B, A>));
    ASSERT_FALSE((is_convertible_to_any_v<B>));
    ASSERT_TRUE((is_convertible_to_any_v<D, A, B>));
    ASSERT_FALSE((is_convertible_to_any_v<B, A>));
}

TEST(TEST_LABEL, is_convertible_to_all) {
    ASSERT_EQ((is_convertible_to_all<D, B>::value), (is_convertible_to_all_v<D, B>));
    ASSERT_TRUE((is_convertible_to_all_v<B>));
    ASSERT_FALSE((is_convertible_to_all_v<D, A, B>));
    ASSERT_TRUE((is_convertible_to_all_v<D, B, D, B>));
}

TEST(TEST_LABEL, are_all_convertible_to) {
    ASSERT_EQ((are_all_convertible_to<A, D>::value), (are_all_convertible_to_v<A, D>));
    ASSERT_TRUE((are_all_convertible_to_v<A>));
    ASSERT_FALSE((are_all_convertible_to_v<D, A, B>));
    ASSERT_TRUE((are_all_convertible_to_v<B, D, B, D>));
}
