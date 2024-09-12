// Ye-Hwan Kim (1130720)
// September 11, 2024

#pragma once

#include <vector>

// returns maximum sum
int maxSubArraySum(int array[], int size) {
    if (size == 0) {
        return 0;
    }

    int max_sum = array[0];

    for (int start_index = 0; start_index < size; start_index++) {
        int sum = 0;

        for (int end_index = start_index; end_index < size; end_index++) {
            sum += array[end_index];

            if (sum > max_sum) {
                max_sum = sum;
            }
        }
    }

    return max_sum;
}

// returns maximum product
int maxSubArrayProduct(std::vector<int> arary) {
    if (arary.empty()) {
        return 0;
    }

    const int size = arary.size();
    int max_product = arary.at(0);

    for (int start_index = 0; start_index < size; start_index++) {
        int product = 1;

        for (int end_index = start_index; end_index < size; end_index++) {
            product *= arary.at(end_index);

            if (product > max_product) {
                max_product = product;
            }
        }
    }

    return max_product;
}
