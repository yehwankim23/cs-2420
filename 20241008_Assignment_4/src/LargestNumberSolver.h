// Ye-Hwan Kim (1130720) & Sungjae Hwang (1503349)
// October 8, 2024

#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <exception>

// create to_string(string)
namespace std {
    std::string to_string(std::string s) {
        return s;
    }
}

// sorts array by using insertion sort
template <class T>
void insertionSort(std::vector<T>& array,
    bool (*compareFunction)(const std::string& a, const std::string& b)) {
    // iterate through array
    for (int start_index = 1; start_index < array.size(); start_index++) {
        const T current = array.at(start_index);
        int end_index = start_index;

        // swap while previous > current
        while (end_index > 0) {
            const T previous = array.at(end_index - 1);

            // convert to string and compare
            if (compareFunction(std::to_string(previous), std::to_string(current))) {
                break;
            }

            array.at(end_index--) = previous;
        }

        array.at(end_index) = current;
    }
}

// returns true if a > b lexicographically
bool isLexicographicallyGreater(const std::string& a, const std::string& b) {
    return a > b;
}

// returns largest number that can be formed as string
std::string findLargestNumber(std::vector<int> array) {
    // return 0 if array is empty
    if (array.empty()) {
        return "0";
    }

    // sort array
    insertionSort<int>(array, isLexicographicallyGreater);

    // create and return largest number
    std::string largest_number;

    for (const int& number : array) {
        largest_number += std::to_string(number);
    }

    return largest_number;
}

// returns true if a > b numerically
bool isNumericallyGreater(const std::string& a, const std::string& b) {
    // check length
    const int a_length = a.size();
    const int b_length = b.size();

    if (a_length > b_length) {
        return true;
    }

    if (a_length < b_length) {
        return false;
    }

    // compare lexicographically if same length
    return isLexicographicallyGreater(a, b);
}

// returns largest number that can be formed as int
int findLargestInt(const std::vector<int>& array) {
    // find largest number
    const std::string largest_number = findLargestNumber(array);

    // return 0 if array is empty
    if (largest_number == "0") {
        return 0;
    }

    // throw out_of_range if number is too large for int
    if (!isNumericallyGreater(largest_number, "2147483647")) {
        return std::stoi(largest_number);
    }

    throw std::out_of_range("too large for int");
}

// returns largest number that can be formed as long long
long long findLargestLong(const std::vector<int>& array) {
    // find largest number
    const std::string largest_number = findLargestNumber(array);

    // return 0 if array is empty
    if (largest_number == "0") {
        return 0;
    }

    // throw out_of_range if number is too large for int
    if (!isNumericallyGreater(largest_number, "9223372036854775807")) {
        return std::stoll(largest_number);
    }

    throw std::out_of_range("too large for long long");
}

// returns sum of largest numbers that can be formed
long long sum(const std::vector<std::vector<int>>& arrays) {
    // return 0 if array is empty
    if (arrays.empty()) {
        return 0;
    }

    long long sum = 0;

    // iterate through arrays add largest long
    for (const std::vector<int>& array : arrays) {
        sum += findLargestLong(array);
    }

    return sum;
}

// returns array that can form kth largest number
std::vector<int> findKthLargest(const std::vector<std::vector<int>>& arrays, const int& k) {
    int length = arrays.size();

    // throw invalid_argument if k is not valid position
    if (k < 0 || k >= length) {
        throw std::invalid_argument("k is not valid position");
    }

    // get largest numbers
    std::vector<std::string> largest_numbers_sorted;
    std::vector<std::string> largest_numbers_unsorted;
    largest_numbers_sorted.reserve(length);
    largest_numbers_unsorted.reserve(length);

    for (const std::vector<int>& array : arrays) {
        largest_numbers_sorted.push_back(findLargestNumber(array));
        largest_numbers_unsorted.push_back(findLargestNumber(array));
    }

    // sort largest numbers
    insertionSort<std::string>(largest_numbers_sorted, isNumericallyGreater);

    // return original array
    for (int index = 0; index < length; index++) {
        if (largest_numbers_sorted.at(k) == largest_numbers_unsorted.at(index)) {
            return arrays.at(index);
        }
    }
}

// returns arrays created from input file
std::vector<std::vector<int>> readFile(const std::string& filename) {
    std::ifstream file;

    // return empty array if file does not exist
    try {
        file.open(filename);
    } catch (std::exception& e) {
        return {};
    }

    // create return arrays
    std::string line;
    std::vector<std::vector<int>> arrays;

    // get lines
    while (std::getline(file, line)) {
        std::istringstream line_stream(line);
        int number;
        std::vector<int> array;

        // get words
        while (line_stream >> number) {
            array.push_back(number);
        }

        arrays.push_back(array);
    }

    file.close();
    return arrays;
}
