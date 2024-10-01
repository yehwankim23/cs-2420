// Ye-Hwan Kim (1130720) & Sungjae Hwang (1503349)
// September 30, 2024

#include "sorting.h"

#include <vector>
#include <stdexcept>

// constructor
Sorting::Sorting(std::vector<short> array) {
    // assign instance variable
    zeroOne = array;
}

// sort array with only 0 and 1
void Sorting::sort_ZeroOne_elements(std::vector<short>& array) {
    // check for valid input
    if (!validateElements(array)) {
        throw std::invalid_argument("array contains element other than 0 and 1");
    }

    // create new array
    const int size = array.size();
    std::vector<short> result(size, 0);

    // iterate through array
    for (int vec_index = 0, temp_index = size - 1; vec_index < size; vec_index++) {
        // set 1 if element is 1
        if (array.at(vec_index) == 1) {
            result.at(temp_index--) = 1;
        }
    }

    array = result;
}

// returns false if element in array is other than 0 and 1
bool Sorting::validateElements(std::vector<short>& array) {
    // iterate through array
    for (const short& element : array) {
        // check element
        if (element != 0 && element != 1) {
            return false;
        }
    }

    return true;
}
