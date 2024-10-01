// Ye-Hwan Kim (1130720) & Sungjae Hwang (1503349)
// September 30, 2024

#pragma once

#include <vector>

class searching {
private:
    // instance variable
    std::vector<int> vec;

public:
    // constructor
    searching(std::vector<int> array);

    // instance method
    int findIndex(std::vector<int> array, int target);
};
