#include "../lib/mainprocess.h"
#include "gtest/gtest.h"

TEST(CircleTests, TestEmptyAdd)
{
    const auto expected = static_cast<int>(ERROR_TYPE::NOT_FOUND_OBJ);

    MainProcess *mp = new MainProcess();
    std::string test_empty_add = "";
    const auto actual = mp->commandAdd(test_empty_add);

    ASSERT_EQ(expected, actual);
}

TEST(CircleTests, TestOnlyCircle)
{
    const auto expected = static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);

    MainProcess *mp = new MainProcess();
    std::string test_only_circle = "circle";
    const auto actual = mp->commandAdd(test_only_circle);

    ASSERT_EQ(expected, actual);
}

TEST(CircleTests, TestCircleOneVar)
{
    const auto expected = static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);

    MainProcess *mp = new MainProcess();
    std::string test_circle_one_var = "circle 1";
    const auto actual = mp->commandAdd(test_circle_one_var);

    ASSERT_EQ(expected, actual);
}

TEST(CircleTests, TestWithoutColor)
{
    const auto expected = static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);

    MainProcess *mp = new MainProcess();
    std::string test_without_color = "circle 1 2 3";
    const auto actual = mp->commandAdd(test_without_color);

    ASSERT_EQ(expected, actual);
}

TEST(CircleTests, TestBadColorCircle)
{
    const auto expected = static_cast<int>(ERROR_TYPE::BAD_COLOR);

    MainProcess *mp = new MainProcess();
    std::string test_bad_color_circle = "circle 1 2 3 gray";
    const auto actual = mp->commandAdd(test_bad_color_circle);

    ASSERT_EQ(expected, actual);
}

TEST(CircleTests, TestCorrectCircle)
{
    const auto expected = static_cast<int>(ERROR_TYPE::OK);

    MainProcess *mp = new MainProcess();
    std::string test_correct_circle = "circle 1 2 3 red";
    const auto actual = mp->commandAdd(test_correct_circle);

    ASSERT_EQ(expected, actual);
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}