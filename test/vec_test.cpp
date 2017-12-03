//
// Created by lex on 12.11.17.
//

#include "../FVector.h"
#include <gtest/gtest.h>

/**
 * Rudimentary test suite for basic vector operations.
 */

TEST(VecArithmeticTest, PlusOp) {
    FVector vec1 = { 0.0f, 1.0f, 4.0f};
    float val = 6.0f;

    FVector vecPlus = vec1 + val;

    ASSERT_FLOAT_EQ(6.0f, vecPlus[0]);
    ASSERT_FLOAT_EQ(7.0f, vecPlus[1]);
    ASSERT_FLOAT_EQ(10.0f, vecPlus[2]);
}

TEST(VecArithmeticTest, MinusOp) {
    FVector vec1 = { 0.0f, 1.0f, 4.0f};
    float val = 6.0f;

    FVector vecPlus = vec1 - val;

    ASSERT_FLOAT_EQ(-6.0f, vecPlus[0]);
    ASSERT_FLOAT_EQ(-5.0f, vecPlus[1]);
    ASSERT_FLOAT_EQ(-2.0f, vecPlus[2]);
}

TEST(VecArithmeticTest, PlusOpVec) {
    FVector vec1 = { 1.0f, 1.0f, 4.0f};
    FVector vec2 = { 0.45f, -1.0f, 3.0f};

    FVector vecPlus = vec1 + vec2;

    ASSERT_FLOAT_EQ(1.45f, vecPlus[0]);
    ASSERT_FLOAT_EQ(0.0f, vecPlus[1]);
    ASSERT_FLOAT_EQ(7.0f, vecPlus[2]);
}

TEST(VecArithmeticTest, MinusOpVec) {
    FVector vec1 = { 1.0f, 1.0f, 4.0f};
    FVector vec2 = { 0.45f, -1.0f, 3.0f};

    FVector vecPlus = vec1 - vec2;

    ASSERT_FLOAT_EQ(0.55f, vecPlus[0]);
    ASSERT_FLOAT_EQ(2.0f, vecPlus[1]);
    ASSERT_FLOAT_EQ(1.0f, vecPlus[2]);
}

TEST(VecArithmeticTest, DotOpVec) {
    FVector vec1 = { 0.5f, 2.0f, 0.0f};
    FVector vec2 = { 2.0f, -1.0f, 3.0f};

    float dot = vec1 ^ vec2;
    //(0.5, 2, 0) x (2, -1, 3) = 1 - 2 + 0 = -1
    ASSERT_FLOAT_EQ(-1.00f, dot);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}