// Ye-Hwan Kim (1130720) & Sungjae Hwang (1503349)
// September 30, 2024

#include "gtest/gtest.h"
#include "sorting.h"
#include "searching.h"
#include "merge.h"

#include <vector>
#include <stdexcept>

////////////////////////////////////////////////////////////////////////////////////////////////////
// provided sorting tests
TEST(SortingAndSearching, ProvidedSortingTest1) {
    std::vector<short> result = { 0, 1, 0, 1, 1, 0, 1 };
    Sorting s(result);
    s.sort_ZeroOne_elements(result);
    std::vector<short> answer = { 0, 0, 0, 1, 1, 1, 1 };
    EXPECT_EQ(result, answer);
}

TEST(SortingAndSearching, ProvidedSortingTest2) {
    std::vector<short> result = { 0, 0, 0, 1, 1, 1, 1, 1 };
    Sorting s(result);
    s.sort_ZeroOne_elements(result);
    std::vector<short> answer = { 0, 0, 0, 1, 1, 1, 1, 1 };
    EXPECT_EQ(result, answer);
}

TEST(SortingAndSearching, ProvidedSortingTest3) {
    std::vector<short> result = { 0, 0, 0, -1, 1, 1, 1, 1 };
    Sorting s(result);
    EXPECT_THROW(s.sort_ZeroOne_elements(result), std::invalid_argument);
}

TEST(SortingAndSearching, ProvidedSortingTest4) {
    std::vector<short> result = { 1, 1, 1, 0, 0, 0 };
    Sorting s(result);
    s.sort_ZeroOne_elements(result);
    std::vector<short> answer = { 0, 0, 0, 1, 1, 1 };
    EXPECT_EQ(result, answer);
}

TEST(SortingAndSearching, ProvidedSortingTest5) {
    std::vector<short> result = {};
    Sorting s(result);
    s.sort_ZeroOne_elements(result);
    std::vector<short> answer = {};
    EXPECT_EQ(result, answer);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// provided searching tests
TEST(SortingAndSearching, ProvidedSearchingTest1) {
    std::vector<int> array = { 6, 8, 3, 1, 3 };
    searching s(array);
    int index1 = s.findIndex(array, 3);
    EXPECT_EQ(index1, 2);
    int index2 = s.findIndex(array, 7);
    EXPECT_EQ(index2, -1);
}

TEST(SortingAndSearching, ProvidedSearchingTest2) {
    std::vector<int> array = { 6, 8, 3, 1, 3 };
    searching s(array);
    int index = s.findIndex(array, 7);
    EXPECT_EQ(index, -1);
}

TEST(SortingAndSearching, ProvidedSearchingTest3) {
    std::vector<int> array = { -6, -5, -3, -1, -3 };
    searching s(array);
    int index = s.findIndex(array, -6);
    EXPECT_EQ(index, 0);
}

TEST(SortingAndSearching, ProvidedSearchingTest4) {
    std::vector<int> array = {};
    searching s(array);
    int index = s.findIndex(array, 20);
    EXPECT_EQ(index, -1);
}

TEST(SortingAndSearching, ProvidedSearchingTest5) {
    std::vector<int> array = { 20 };
    searching s(array);
    int index = s.findIndex(array, 20);
    EXPECT_EQ(index, 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// provided merging tests
TEST(SortingAndSearching, ProvidedMergingTest1) {
    std::vector<Interval> intervals = {
        Interval(3, 6),
        Interval(1, 4),
        Interval(8, 10)
    };

    std::vector<Interval> result = Interval::merge_intervals(intervals);

    std::vector<Interval> answer = {
        Interval(1, 6),
        Interval(8, 10)
    };

    bool check = true;

    if (result.size() == answer.size()) {
        for (int index = 0; index < result.size(); index++) {
            if (!(answer[index] == result[index])) {
                check = false;
                break;
            }
        }
    } else {
        check = false;
    }

    EXPECT_TRUE(check);
}

TEST(SortingAndSearching, ProvidedMergingTest2) {
    EXPECT_THROW(Interval(9, 6), std::invalid_argument);
}

TEST(SortingAndSearching, ProvidedMergingTest3) {
    std::vector<Interval> intervals = {
        Interval(1, 3),
        Interval(2, 4),
        Interval(6, 8),
        Interval(9, 10)
    };

    std::vector<Interval> result = Interval::merge_intervals(intervals);

    std::vector<Interval> answer = {
        Interval(1, 4),
        Interval(6, 8),
        Interval(9, 10)
    };

    bool check = true;

    if (result.size() == answer.size()) {
        for (int index = 0; index < result.size(); index++) {
            if (!(answer[index] == result[index])) {
                check = false;
                break;
            }
        }
    } else {
        check = false;
    }

    EXPECT_TRUE(check);
}

TEST(SortingAndSearching, ProvidedMergingTest4) {
    std::vector<Interval> intervals = {
        Interval(-5, 5),
        Interval(0, 4),
        Interval(3, 9),
        Interval(-1, 10)
    };

    std::vector<Interval> result = Interval::merge_intervals(intervals);

    std::vector<Interval> answer = {
        Interval(-5, 10)
    };

    bool check = true;

    if (result.size() == answer.size()) {
        for (int index = 0; index < result.size(); index++) {
            if (!(answer[index] == result[index])) {
                check = false;
                break;
            }
        }
    } else {
        check = false;
    }

    EXPECT_TRUE(check);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// additional sorting tests
TEST(SortingAndSearching, AdditionalSortingTest1) {
    std::vector<short> result = { 0, 0, 0, 0 };
    Sorting s(result);
    s.sort_ZeroOne_elements(result);
    std::vector<short> answer = { 0, 0, 0, 0 };
    EXPECT_EQ(result, answer);
}

TEST(SortingAndSearching, AdditionalSortingTest2) {
    std::vector<short> result = { 0, 1, 0, 1 };
    Sorting s(result);
    s.sort_ZeroOne_elements(result);
    std::vector<short> answer = { 0, 0, 1, 1 };
    EXPECT_EQ(result, answer);
}

TEST(SortingAndSearching, AdditionalSortingTest3) {
    std::vector<short> result = { 1, 1, 1, 1 };
    Sorting s(result);
    s.sort_ZeroOne_elements(result);
    std::vector<short> answer = { 1, 1, 1, 1 };
    EXPECT_EQ(result, answer);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// additional searching tests
TEST(SortingAndSearching, AdditionalSearchingTest1) {
    std::vector<int> array = { 1, 2, 3, 4, 5 };
    searching s(array);
    int index = s.findIndex(array, 1);
    EXPECT_EQ(index, 0);
}

TEST(SortingAndSearching, AdditionalSearchingTest2) {
    std::vector<int> array = { 1, 2, 3, 4, 5 };
    searching s(array);
    int actual = s.findIndex(array, 5);
    EXPECT_EQ(actual, 4);
}

TEST(SortingAndSearching, AdditionalSearchingTest3) {
    std::vector<int> array = { 1, 2, 3, 4, 5 };
    searching s(array);
    int index = s.findIndex(array, 0);
    EXPECT_EQ(index, -1);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// additional merging tests
TEST(SortingAndSearching, AdditionalMergingTest1) {
    std::vector<Interval> intervals = {
        Interval(1, 2),
        Interval(3, 4)
    };

    std::vector<Interval> result = Interval::merge_intervals(intervals);

    std::vector<Interval> answer = {
        Interval(1, 2),
        Interval(3, 4)
    };

    bool check = true;

    if (result.size() == answer.size()) {
        for (int index = 0; index < result.size(); index++) {
            if (!(answer[index] == result[index])) {
                check = false;
                break;
            }
        }
    } else {
        check = false;
    }

    EXPECT_TRUE(check);
}

TEST(SortingAndSearching, AdditionalMergingTest2) {
    std::vector<Interval> intervals = {
        Interval(1, 3),
        Interval(2, 4)
    };

    std::vector<Interval> result = Interval::merge_intervals(intervals);

    std::vector<Interval> answer = {
        Interval(1, 4)
    };

    bool check = true;

    if (result.size() == answer.size()) {
        for (int index = 0; index < result.size(); index++) {
            if (!(answer[index] == result[index])) {
                check = false;
                break;
            }
        }
    } else {
        check = false;
    }

    EXPECT_TRUE(check);
}

TEST(SortingAndSearching, AdditionalMergingTest3) {
    std::vector<Interval> intervals = {
        Interval(1, 4),
        Interval(2, 3)
    };

    std::vector<Interval> result = Interval::merge_intervals(intervals);

    std::vector<Interval> answer = {
        Interval(1, 4)
    };

    bool check = true;

    if (result.size() == answer.size()) {
        for (int index = 0; index < result.size(); index++) {
            if (!(answer[index] == result[index])) {
                check = false;
                break;
            }
        }
    } else {
        check = false;
    }

    EXPECT_TRUE(check);
}
