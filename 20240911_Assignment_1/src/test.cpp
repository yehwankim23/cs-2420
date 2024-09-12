// Ye-Hwan Kim (1130720)
// September 11, 2024

#include <vector>

#include "pch.h"
#include "subarray.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// sum tests
TEST(Subarray, MaxSumTest1) {
    int array[] = { 0, -2, 4 };
    int size = sizeof(array) / sizeof(array[0]);
    int max_sum = maxSubArraySum(array, size);
    EXPECT_EQ(max_sum, 4);
}

TEST(Subarray, MaxSumTest2) {
    int array[] = { 60, 30, -20 };
    int size = sizeof(array) / sizeof(array[0]);
    int max_sum = maxSubArraySum(array, size);
    EXPECT_EQ(max_sum, 90);
}

TEST(Subarray, MaxSumTest3) {
    int array[] = { -1, -2, -3 };
    int size = sizeof(array) / sizeof(array[0]);
    int max_sum = maxSubArraySum(array, size);
    EXPECT_EQ(max_sum, -1);
}

TEST(Subarray, MaxSumTest4) {
    int array[] = { -5, 0, -6 };
    int size = sizeof(array) / sizeof(array[0]);
    int max_sum = maxSubArraySum(array, size);
    EXPECT_EQ(max_sum, 0);
}

TEST(Subarray, MaxSumTest5) {
    int array[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 46, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -46, 100
    };

    int size = sizeof(array) / sizeof(array[0]);
    int max_sum = maxSubArraySum(array, size);
    EXPECT_EQ(max_sum, 101);
}

TEST(Subarray, MaxSumTest6) {
    int array[1] = {};
    int size = sizeof(array) / sizeof(array[0]);
    int max_sum = maxSubArraySum(array, size);
    EXPECT_EQ(max_sum, 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// product tests
TEST(Subarray, MaxProductTest1) {
    std::vector<int> array = { 0, -2, 4 };
    int max_product = maxSubArrayProduct(array);
    EXPECT_EQ(max_product, 4);
}

TEST(Subarray, MaxProductTest2) {
    std::vector<int> array = { 60, 30, -20 };
    int max_product = maxSubArrayProduct(array);
    EXPECT_EQ(max_product, 1800);
}

TEST(Subarray, MaxProductTest3) {
    std::vector<int> array = { -1, -2, -3 };
    int max_product = maxSubArrayProduct(array);
    EXPECT_EQ(max_product, 6);
}

TEST(Subarray, MaxProductTest4) {
    std::vector<int> array = { -5, 0, -6 };
    int max_product = maxSubArrayProduct(array);
    EXPECT_EQ(max_product, 0);
}

TEST(Subarray, MaxProductTest5) {
    std::vector<int> array = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 46, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -46, 100
    };

    int max_product = maxSubArrayProduct(array);
    EXPECT_EQ(max_product, 2138330112);
}

TEST(Subarray, MaxProductTest6) {
    std::vector<int> array = {};
    int max_product = maxSubArrayProduct(array);
    EXPECT_EQ(max_product, 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// additional sum tests
TEST(Subarray, SumConstant) {
    int array[] = { 5, 5, 5, 5, 5 };
    int size = sizeof(array) / sizeof(array[0]);
    int max_sum = maxSubArraySum(array, size);
    EXPECT_EQ(max_sum, 25);
}

TEST(Subarray, SumIncreasing) {
    int array[] = { 5, 6, 7, 8, 9 };
    int size = sizeof(array) / sizeof(array[0]);
    int max_sum = maxSubArraySum(array, size);
    EXPECT_EQ(max_sum, 35);
}

TEST(Subarray, SumDecreasing) {
    int array[] = { 5, 4, 3, 2, 1 };
    int size = sizeof(array) / sizeof(array[0]);
    int max_sum = maxSubArraySum(array, size);
    EXPECT_EQ(max_sum, 15);
}

TEST(Subarray, SumConcaveUp) {
    int array[] = { 5, 4, 3, 4, 5 };
    int size = sizeof(array) / sizeof(array[0]);
    int max_sum = maxSubArraySum(array, size);
    EXPECT_EQ(max_sum, 21);
}

TEST(Subarray, SumConcaveDown) {
    int array[] = { 5, 6, 7, 6, 5 };
    int size = sizeof(array) / sizeof(array[0]);
    int max_sum = maxSubArraySum(array, size);
    EXPECT_EQ(max_sum, 29);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// additional product tests
TEST(Subarray, ProductConstant) {
    std::vector<int> array = { 5, 5, 5, 5, 5 };
    int max_product = maxSubArrayProduct(array);
    EXPECT_EQ(max_product, 3125);
}

TEST(Subarray, ProductIncreasing) {
    std::vector<int> array = { 5, 6, 7, 8, 9 };
    int max_product = maxSubArrayProduct(array);
    EXPECT_EQ(max_product, 15120);
}

TEST(Subarray, ProductDecreasing) {
    std::vector<int> array = { 5, 4, 3, 2, 1 };
    int max_product = maxSubArrayProduct(array);
    EXPECT_EQ(max_product, 120);
}

TEST(Subarray, ProductConcaveUp) {
    std::vector<int> array = { 5, 4, 3, 4, 5 };
    int max_product = maxSubArrayProduct(array);
    EXPECT_EQ(max_product, 1200);
}

TEST(Subarray, ProductConcaveDown) {
    std::vector<int> array = { 5, 6, 7, 6, 5 };
    int max_product = maxSubArrayProduct(array);
    EXPECT_EQ(max_product, 6300);
}
