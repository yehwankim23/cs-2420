// Ye-Hwan Kim (1130720) & Sungjae Hwang (1503349)
// September 30, 2024

#pragma once

#include <vector>

class Sorting {
private:
    // instance variable
    std::vector<short> zeroOne;

public:
    // constructor
    Sorting(std::vector<short> array);

    // instance methods
    void sort_ZeroOne_elements(std::vector<short>& array);
    bool validateElements(std::vector<short>& array);
};
