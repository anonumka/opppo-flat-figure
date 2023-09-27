#include "../lib/mainprocess.h"
#include "gtest/gtest.h"

TEST(GeometrysTests, TestIntegerOne_One)
{
    const auto expected = static_cast<int>(ERROR_TYPE::NOT_FOUND_OBJ);

    MainProcess *mp = new MainProcess();
    std::string test_only_add = "add";
    const auto actual = mp->commandAdd(test_only_add);
    ASSERT_EQ(expected, actual);
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}