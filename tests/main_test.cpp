#include "../lib/mainprocess.h"
#include "gtest/gtest.h"

TEST(AddTests, TestEmptyAdd)
{
    const auto expected = static_cast<int>(ERROR_TYPE::NOT_FOUND_OBJ);

    MainProcess *mp = new MainProcess();
    std::string test_empty_add = "";
    const auto actual = mp->commandAdd(test_empty_add);

    ASSERT_EQ(expected, actual);
}

TEST(AddTests, TestOnlyCircle)
{
    const auto expected = static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);

    MainProcess *mp = new MainProcess();
    std::string test_only_circle = "circle";
    const auto actual = mp->commandAdd(test_only_circle);

    ASSERT_EQ(expected, actual);
}

TEST(AddTests, TestCircleOneVar)
{
    const auto expected = static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);

    MainProcess *mp = new MainProcess();
    std::string test_circle_one_var = "circle 1";
    const auto actual = mp->commandAdd(test_circle_one_var);

    ASSERT_EQ(expected, actual);
}

TEST(AddTests, TestCircleWithoutColor)
{
    const auto expected = static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);

    MainProcess *mp = new MainProcess();
    std::string test_without_color = "circle 1 2 3";
    const auto actual = mp->commandAdd(test_without_color);

    ASSERT_EQ(expected, actual);
}

TEST(AddTests, TestBadColorCircle)
{
    const auto expected = static_cast<int>(ERROR_TYPE::COLOR_NOT_EXIST);

    MainProcess *mp = new MainProcess();
    std::string test_bad_color_circle = "circle 1 2 3 gray";
    const auto actual = mp->commandAdd(test_bad_color_circle);

    ASSERT_EQ(expected, actual);
}

TEST(AddTests, TestCorrectCircle)
{
    const auto expected = static_cast<int>(ERROR_TYPE::OK);

    MainProcess *mp = new MainProcess();
    std::string test_correct_circle = "circle 1 2 3 red";
    const auto actual = mp->commandAdd(test_correct_circle);

    ASSERT_EQ(expected, actual);
}

TEST(AddTests, TestOnlyRectangle)
{
    const auto expected = static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);

    MainProcess *mp = new MainProcess();
    std::string test_only_rectangle = "rectangle";
    const auto actual = mp->commandAdd(test_only_rectangle);

    ASSERT_EQ(expected, actual);
}

TEST(AddTests, TestRectangleOneVar)
{
    const auto expected = static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);

    MainProcess *mp = new MainProcess();
    std::string test_crectangle_one_var = "rectangle 1.5";
    const auto actual = mp->commandAdd(test_crectangle_one_var);

    ASSERT_EQ(expected, actual);
}

TEST(AddTests, TestRectangleWithoutColor)
{
    const auto expected = static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);

    MainProcess *mp = new MainProcess();
    std::string test_rectangle_without_color = "rectangle 999.9 500";
    const auto actual = mp->commandAdd(test_rectangle_without_color);

    ASSERT_EQ(expected, actual);
}

TEST(AddTests, TestBadColorRectangle)
{
    const auto expected = static_cast<int>(ERROR_TYPE::COLOR_NOT_EXIST);

    MainProcess *mp = new MainProcess();
    std::string test_bad_color_rectangle = "rectangle 123.9 777 gray";
    const auto actual = mp->commandAdd(test_bad_color_rectangle);

    ASSERT_EQ(expected, actual);
}

TEST(AddTests, TestCorrectRectangle)
{
    const auto expected = static_cast<int>(ERROR_TYPE::OK);

    MainProcess *mp = new MainProcess();
    std::string test_correct_rectangle = "rectangle 123.9 777 red";
    const auto actual = mp->commandAdd(test_correct_rectangle);

    ASSERT_EQ(expected, actual);
}

TEST(AddTests, TestOnlyTriangle)
{
    const auto expected = static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);

    MainProcess *mp = new MainProcess();
    std::string test_only_triangle = "triangle";
    const auto actual = mp->commandAdd(test_only_triangle);

    ASSERT_EQ(expected, actual);
}

TEST(AddTests, TestTriangleOneVar)
{
    const auto expected = static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);

    MainProcess *mp = new MainProcess();
    std::string test_triangle_one_var = "triangle 1";
    const auto actual = mp->commandAdd(test_triangle_one_var);

    ASSERT_EQ(expected, actual);
}

TEST(AddTests, TestTriangleWithoutColor)
{
    const auto expected = static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);

    MainProcess *mp = new MainProcess();
    std::string test_triangle_without_color = "triangle 1 2 3";
    const auto actual = mp->commandAdd(test_triangle_without_color);

    ASSERT_EQ(expected, actual);
}

TEST(AddTests, TestBadColorTriangle)
{
    const auto expected = static_cast<int>(ERROR_TYPE::COLOR_NOT_EXIST);

    MainProcess *mp = new MainProcess();
    std::string test_bad_color_triangle = "triangle 1 2 3 gray";
    const auto actual = mp->commandAdd(test_bad_color_triangle);

    ASSERT_EQ(expected, actual);
}

TEST(AddTests, TestCorrectTriangle)
{
    const auto expected = static_cast<int>(ERROR_TYPE::OK);

    MainProcess *mp = new MainProcess();
    std::string test_correct_triangle = "triangle 1 2 3 red";
    const auto actual = mp->commandAdd(test_correct_triangle);

    ASSERT_EQ(expected, actual);
}

TEST(DelTests, TestDeleteAll)
{
    const auto expected = 0;

    MainProcess *mp = new MainProcess();
    std::string test_correct_triangle = "triangle 1 2 3 red";
    mp->commandAdd(test_correct_triangle);
    mp->commandAdd(test_correct_triangle);
    mp->commandAdd(test_correct_triangle);
    mp->commandRem("*");
    const auto actual = mp->objs->getSize();

    ASSERT_EQ(expected, actual);
}

TEST(DelTests, TestDeleteExistColor)
{
    MainProcess *mp = new MainProcess();
    std::string test_correct_triangle = "triangle 1 2 3 red";

    const auto expected = mp->objs->getSize();
    mp->commandAdd(test_correct_triangle);
    mp->commandAdd(test_correct_triangle);
    mp->commandAdd(test_correct_triangle);
    mp->commandRem("color red");
    const auto actual = mp->objs->getSize();

    ASSERT_EQ(expected, actual);
}

TEST(DelTests, TestDeleteNotExistColor)
{
    MainProcess *mp = new MainProcess();
    std::string test_correct_triangle = "triangle 1 2 3 red";

    mp->commandAdd(test_correct_triangle);
    mp->commandAdd(test_correct_triangle);
    mp->commandAdd(test_correct_triangle);
    const auto expected = mp->objs->getSize();
    mp->commandRem("color blue");

    const auto actual = mp->objs->getSize();
    ASSERT_EQ(expected, actual);
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}