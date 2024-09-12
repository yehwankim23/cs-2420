// Ye-Hwan Kim (1130720)
// September 11, 2024

#include "gtest/gtest.h"
#include "subarray.h"

#include <vector>

////////////////////////////////////////////////////////////////////////////////////////////////////
// provided sum tests
TEST(SubarraySum, ProvidedSumTest1) {
    int array[] = { 0, -2, 4 };
    int size = sizeof(array) / sizeof(array[0]);
    int max_sum = maxSubArraySum(array, size);
    EXPECT_EQ(max_sum, 4);
}

TEST(SubarraySum, ProvidedSumTest2) {
    int array[] = { 60, 30, -20 };
    int size = sizeof(array) / sizeof(array[0]);
    int max_sum = maxSubArraySum(array, size);
    EXPECT_EQ(max_sum, 90);
}

TEST(SubarraySum, ProvidedSumTest3) {
    int array[] = { -1, -2, -3 };
    int size = sizeof(array) / sizeof(array[0]);
    int max_sum = maxSubArraySum(array, size);
    EXPECT_EQ(max_sum, -1);
}

TEST(SubarraySum, ProvidedSumTest4) {
    int array[] = { -5, 0, -6 };
    int size = sizeof(array) / sizeof(array[0]);
    int max_sum = maxSubArraySum(array, size);
    EXPECT_EQ(max_sum, 0);
}

TEST(SubarraySum, ProvidedSumTest5) {
    int array[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 46, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -46, 100
    };

    int size = sizeof(array) / sizeof(array[0]);
    int max_sum = maxSubArraySum(array, size);
    EXPECT_EQ(max_sum, 101);
}

TEST(SubarraySum, ProvidedSumTest6) {
    int array[1] = {};
    int size = sizeof(array) / sizeof(array[0]);
    int max_sum = maxSubArraySum(array, size);
    EXPECT_EQ(max_sum, 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// provided product tests
TEST(SubarraySum, ProvidedProductTest1) {
    std::vector<int> array = { 0, -2, 4 };
    int max_product = maxSubArrayProduct(array);
    EXPECT_EQ(max_product, 4);
}

TEST(SubarraySum, ProvidedProductTest2) {
    std::vector<int> array = { 60, 30, -20 };
    int max_product = maxSubArrayProduct(array);
    EXPECT_EQ(max_product, 1800);
}

TEST(SubarraySum, ProvidedProductTest3) {
    std::vector<int> array = { -1, -2, -3 };
    int max_product = maxSubArrayProduct(array);
    EXPECT_EQ(max_product, 6);
}

TEST(SubarraySum, ProvidedProductTest4) {
    std::vector<int> array = { -5, 0, -6 };
    int max_product = maxSubArrayProduct(array);
    EXPECT_EQ(max_product, 0);
}

TEST(SubarraySum, ProvidedProductTest5) {
    std::vector<int> array = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 46, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -46, 100
    };

    int max_product = maxSubArrayProduct(array);
    EXPECT_EQ(max_product, 2138330112);
}

TEST(SubarraySum, ProvidedProductTest6) {
    std::vector<int> array = {};
    int max_product = maxSubArrayProduct(array);
    EXPECT_EQ(max_product, 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// additional sum tests
TEST(SubarraySum, AdditionalSumTest1) {
    int array[] = { 5, 5, 5, 5, 5 };
    int size = sizeof(array) / sizeof(array[0]);
    int max_sum = maxSubArraySum(array, size);
    EXPECT_EQ(max_sum, 25);
}

TEST(SubarraySum, AdditionalSumTest2) {
    int array[] = { 5, 6, 7, 8, 9 };
    int size = sizeof(array) / sizeof(array[0]);
    int max_sum = maxSubArraySum(array, size);
    EXPECT_EQ(max_sum, 35);
}

TEST(SubarraySum, AdditionalSumTest3) {
    int array[] = { 5, 4, 3, 2, 1 };
    int size = sizeof(array) / sizeof(array[0]);
    int max_sum = maxSubArraySum(array, size);
    EXPECT_EQ(max_sum, 15);
}

TEST(SubarraySum, AdditionalSumTest4) {
    int array[] = { 5, 4, 3, 4, 5 };
    int size = sizeof(array) / sizeof(array[0]);
    int max_sum = maxSubArraySum(array, size);
    EXPECT_EQ(max_sum, 21);
}

TEST(SubarraySum, AdditionalSumTest5) {
    int array[] = { 5, 6, 7, 6, 5 };
    int size = sizeof(array) / sizeof(array[0]);
    int max_sum = maxSubArraySum(array, size);
    EXPECT_EQ(max_sum, 29);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// additional product tests
TEST(SubarraySum, AdditionalProductTest1) {
    std::vector<int> array = { 5, 5, 5, 5, 5 };
    int max_product = maxSubArrayProduct(array);
    EXPECT_EQ(max_product, 3125);
}

TEST(SubarraySum, AdditionalProductTest2) {
    std::vector<int> array = { 5, 6, 7, 8, 9 };
    int max_product = maxSubArrayProduct(array);
    EXPECT_EQ(max_product, 15120);
}

TEST(SubarraySum, AdditionalProductTest3) {
    std::vector<int> array = { 5, 4, 3, 2, 1 };
    int max_product = maxSubArrayProduct(array);
    EXPECT_EQ(max_product, 120);
}

TEST(SubarraySum, AdditionalProductTest4) {
    std::vector<int> array = { 5, 4, 3, 4, 5 };
    int max_product = maxSubArrayProduct(array);
    EXPECT_EQ(max_product, 1200);
}

TEST(SubarraySum, AdditionalProductTest5) {
    std::vector<int> array = { 5, 6, 7, 6, 5 };
    int max_product = maxSubArrayProduct(array);
    EXPECT_EQ(max_product, 6300);
}
