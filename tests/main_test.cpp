#include "../lib/mainprocess.h"
#include "gtest/gtest.h"

TEST(GeneralWork, NotExitsFile)
{
    const auto expected = static_cast<int>(ERROR_TYPE::FILE_NOT_FOUND);

    MainProcess *mp = new MainProcess();
    std::string test_not_exist_file = "not_existing_file.txt";
    const auto actual = mp->run(test_not_exist_file);

    ASSERT_EQ(expected, actual);   
}

TEST(GeneralWork, EmptyPrint)
{
    const auto expected = static_cast<int>(ERROR_TYPE::LIST_EMPTY);

    MainProcess *mp = new MainProcess();
    std::string test_not_exist_file = "not_existing_file.txt";
    const auto actual = mp->objs->printList();

    ASSERT_EQ(expected, actual);   
}

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

TEST(DelTests, TestDeleteOneExistColor)
{
    MainProcess *mp = new MainProcess();
    std::string test_correct_triangle = "triangle 1 2 3 red";

    mp->commandAdd(test_correct_triangle);
    test_correct_triangle = "circle 1 2 3 blue";
    mp->commandAdd(test_correct_triangle);
    mp->commandAdd(test_correct_triangle);
    const auto expected = mp->objs->getSize() - 1;
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

TEST(DelTests, TestDeleteAllExistColor)
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

TEST(DelTests, TestDeleteAllExistCircle)
{
    MainProcess *mp = new MainProcess();
    std::string test_correct_circle = "circle 1 2 3 red";

    const auto expected = mp->objs->getSize();
    mp->commandAdd(test_correct_circle);
    mp->commandAdd(test_correct_circle);
    mp->commandAdd(test_correct_circle);
    mp->commandRem("circle");
    const auto actual = mp->objs->getSize();

    ASSERT_EQ(expected, actual);
}

TEST(DelTests, TestDeleteAllExistRectangle)
{
    MainProcess *mp = new MainProcess();
    std::string test_correct_rectangle = "rectangle 1 2 red";

    const auto expected = mp->objs->getSize();
    mp->commandAdd(test_correct_rectangle);
    mp->commandAdd(test_correct_rectangle);
    mp->commandAdd(test_correct_rectangle);
    mp->commandRem("rectangle");
    const auto actual = mp->objs->getSize();

    ASSERT_EQ(expected, actual);
}

TEST(DelTests, TestDeleteAllExistTriangle)
{
    MainProcess *mp = new MainProcess();
    std::string test_correct_triangle = "triangle 1 2 3.0 red";

    const auto expected = mp->objs->getSize();
    mp->commandAdd(test_correct_triangle);
    mp->commandAdd(test_correct_triangle);
    mp->commandAdd(test_correct_triangle);
    mp->commandRem("triangle");
    const auto actual = mp->objs->getSize();

    ASSERT_EQ(expected, actual);
}

TEST(DelTests, TestDeleteNotExistCircle)
{
    MainProcess *mp = new MainProcess();
    std::string test_correct_circle_1 = "circle 1 2 3 red";
    std::string test_correct_circle_2 = "circle 5 6 2";

    mp->commandAdd(test_correct_circle_1);
    const auto expected = mp->objs->getSize();
    mp->commandRem(test_correct_circle_2);
    const auto actual = mp->objs->getSize();

    ASSERT_EQ(expected, actual);
}

TEST(DelTests, TestDeleteExistCircle)
{
    MainProcess *mp = new MainProcess();
    std::string test_correct_circle_1 = "circle 1 2 3 red";
    std::string test_correct_circle_2 = "circle 1 2 3";

    const auto expected = mp->objs->getSize();
    mp->commandAdd(test_correct_circle_1);
    mp->commandRem(test_correct_circle_2);
    const auto actual = mp->objs->getSize();

    ASSERT_EQ(expected, actual);
}

TEST(DelTests, TestDeleteNotExistRectangle)
{
    MainProcess *mp = new MainProcess();
    std::string test_correct_rectangle_1 = "rectangle 1 2 3 red";
    std::string test_correct_rectangle_2 = "rectangle 5 6 2";

    mp->commandAdd(test_correct_rectangle_1);
    const auto expected = mp->objs->getSize();
    mp->commandRem(test_correct_rectangle_2);
    const auto actual = mp->objs->getSize();

    ASSERT_EQ(expected, actual);
}

TEST(DelTests, TestDeleteExistRectangle)
{
    MainProcess *mp = new MainProcess();
    std::string test_correct_rectangle_1 = "rectangle 1 2 red";
    std::string test_correct_rectangle_2 = "rectangle 1 2";

    const auto expected = mp->objs->getSize();
    mp->commandAdd(test_correct_rectangle_1);
    mp->commandRem(test_correct_rectangle_2);
    const auto actual = mp->objs->getSize();

    ASSERT_EQ(expected, actual);
}

TEST(DelTests, TestDeleteNotExistTriangle)
{
    MainProcess *mp = new MainProcess();
    std::string test_correct_triangle_1 = "triangle 1 2 3 red";
    std::string test_correct_triangle_2 = "triangle 5 6 2";

    mp->commandAdd(test_correct_triangle_1);
    const auto expected = mp->objs->getSize();
    mp->commandRem(test_correct_triangle_2);
    const auto actual = mp->objs->getSize();

    ASSERT_EQ(expected, actual);
}

TEST(DelTests, TestDeleteExistTriangle)
{
    MainProcess *mp = new MainProcess();
    std::string test_correct_triangle_1 = "triangle 1 2 3 red";
    std::string test_correct_triangle_2 = "triangle 1 2 3";

    const auto expected = mp->objs->getSize();
    mp->commandAdd(test_correct_triangle_1);
    mp->commandRem(test_correct_triangle_2);
    const auto actual = mp->objs->getSize();

    ASSERT_EQ(expected, actual);
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}