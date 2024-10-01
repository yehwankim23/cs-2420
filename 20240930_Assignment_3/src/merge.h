// Ye-Hwan Kim (1130720) & Sungjae Hwang (1503349)
// September 30, 2024

#pragma once

#include <vector>

class Interval {
private:
    // instance variables
    int first;
    int second;

public:
    // constructor
    Interval(int first, int second);

    // getters
    int getFirst();
    int getSecond();

    // static methods
    static bool compare(Interval& left, Interval& right);
    static std::vector<Interval> merge_intervals(std::vector<Interval>& array);

    // operator ==
    bool operator==(Interval& other);
};
