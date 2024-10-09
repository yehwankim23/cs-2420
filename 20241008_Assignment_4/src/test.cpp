// Ye-Hwan Kim (1130720) & Sungjae Hwang (1503349)
// October 8, 2024

#include <vector>
#include <string>
#include <stdexcept>

#include "pch.h"
#include "LargestNumberSolver.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// insertion sort test
TEST(insertionSort, insertionSort1) {
    std::vector<int> result = { 1, 45, 9 };
    insertionSort<int>(result, isLexicographicallyGreater);
    std::vector<int> answer = { 9, 45, 1 };
    EXPECT_EQ(result, answer);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// find largest number test
TEST(findLargestNumber, findLargestNumber1) {
    std::string largest = findLargestNumber({ 1, 45, 9 });
    EXPECT_EQ(largest, "9451");
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// find largest int tests
TEST(findLargestInt, findLargestInt1) {
    EXPECT_THROW(findLargestInt({ 999, 639, 1, 7, 58, 9 }), std::out_of_range);
}

TEST(findLargestInt, findLargestInt2) {
    int largest = findLargestInt({ 2147483647 });
    EXPECT_EQ(largest, 2147483647);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// find largest long test
TEST(findLargestLong, findLargestLong1) {
    long long largest = findLargestLong({ 999, 639, 1, 7, 58, 9 });
    EXPECT_EQ(largest, 99997639581L);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// sum test
TEST(sum, sum1) {
    std::vector<std::vector<int>> array = { {88, 51}, {7, 42, 97} };
    long long asdf = sum(array);
    EXPECT_EQ(asdf, 106593L);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// find kth largest test
TEST(findKthLargest, findKthLargest1) {
    std::vector<std::vector<int>> array = { {88, 51}, {7, 42, 97} };
    std::vector<int> result = findKthLargest(array, 0);
    std::vector<int> answer = { 7, 42, 97 };
    EXPECT_EQ(result, answer);
}

TEST(findKthLargest, findKthLargest2) {
    std::vector<std::vector<int>> array = { {88, 51}, {7, 42, 97} };
    std::vector<int> result = findKthLargest(array, 1);
    const std::vector<int> answer = { 88, 51 };
    EXPECT_EQ(result, answer);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// read file test
TEST(readFile, readFile1) {
    std::vector<std::vector<int>> arrays = readFile("integers.txt");
    EXPECT_NE(arrays.size(), 0);
}
