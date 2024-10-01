// Ye-Hwan Kim (1130720) & Sungjae Hwang (1503349)
// September 30, 2024

#include "merge.h"

#include <stdexcept>
#include <vector>
#include <algorithm>

// constructor
Interval::Interval(int first, int second) {
    // check for valid input
    if (first >= second) {
        throw std::invalid_argument("first >= second");
    }

    // assign instance variables
    this->first = first;
    this->second = second;
}

// getter for first
int Interval::getFirst() {
    return first;
}

// getter for second
int Interval::getSecond() {
    return second;
}

// returns true if lhs is less than rhs
bool Interval::compare(Interval& left, Interval& right) {
    return left.first < right.first;
}

// merges overlapping intervals
std::vector<Interval> Interval::merge_intervals(std::vector<Interval>& array) {
    // return if array is empty
    if (array.empty()) {
        return array;
    }

    // sort array
    std::sort(array.begin(), array.end(), compare);

    // create new array
    const int size = array.size();
    Interval& interval = array.at(0);
    int start = interval.first;
    int end = interval.second;
    std::vector<Interval> result;

    // iterate through array
    for (int index = 1; index < size; index++) {
        interval = array.at(index);

        // does not overlap
        if (interval.first > end) {
            result.push_back(Interval(start, end));
            start = interval.first;
            end = interval.second;
            continue;
        }

        // check overlap interval
        if (interval.second > end) {
            end = interval.second;
        }
    }

    // add last element
    result.push_back(Interval(start, end));
    return result;
}

// returns true if two intervals are the same
bool Interval::operator==(Interval& other) {
    // check instance variables
    return first == other.first && second == other.second;
}
