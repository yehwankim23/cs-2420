// Ye-Hwan Kim (1130720) & Sungjae Hwang (1503349)
// September 30, 2024

#include "searching.h"

#include <vector>

// constructor
searching::searching(std::vector<int> array) {
    // assign instance variable
    vec = array;
}

// returns left-most index or -1 if it doesn't exist
int searching::findIndex(std::vector<int> array, int target) {
    // iterate through array
    for (int index = 0; index < array.size(); index++) {
        // check element
        if (array[index] == target) {
            return index;
        }
    }

    return -1;
}
