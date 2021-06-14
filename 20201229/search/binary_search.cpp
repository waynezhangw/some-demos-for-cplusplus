#include <algorithm>
#include <stdlib.h>

#include "thirdparty/gtest/gtest.h"  //gtest 1.6.0 will not work here
//#include "gtest/gtest.h"
#include "binary_search.h"


// the first one no less than val
int lower_bound(const std::vector<int>& inputs, int val) {
    if (inputs.size() == 0) return -1;
    if (inputs.size() == 1) return inputs[0] < val ? -1 : 0;
    vector<int> temp(inputs);
    std::sort (temp.begin(), temp.end());

    int left_index = 0;
    int right_index = temp.size()-1;
    int found_index = temp[left_index] > val ? left_index : -1;
    while(left_index <= right_index && temp[left_index] <= val && temp[right_index] >= val) {
        int middle_index = (left_index + right_index) / 2;
        if (temp[middle_index] >= val) { // >= means move towards left first
            right_index = middle_index;
        }
        if (temp[middle_index] < val) {  // < guarantee to find the first one less than
            left_index = middle_index;
        }
        if (left_index == right_index) {
            found_index = left_index;
            break;
        }
        if (right_index - left_index == 1) {
            found_index = temp[left_index] >= val ? left_index : right_index;
            break;
        }
    }
    return found_index;
}

// the first one bigger than val
int upper_bound(const std::vector<int>& inputs, int val) {
    if (inputs.size() == 0) return -1;
    if (inputs.size() == 1) return inputs[0] <= val ? -1 : 0;
    vector<int> temp(inputs);
    std::sort (temp.begin(), temp.end());

    int left_index = 0;
    int right_index = temp.size()-1;
    int found_index = temp[left_index] > val ? left_index : -1;
    while(left_index <= right_index && temp[left_index] <= val && temp[right_index] >= val) {
        int middle_index = (left_index + right_index) / 2;
        if (temp[middle_index] > val) {
            right_index = middle_index;
        }
        if (temp[middle_index] <= val) {  // <= means move towards right first
            left_index = middle_index;
        }
        if (left_index == right_index) {
            found_index = left_index;
            break;
        }
        if (right_index - left_index == 1) {
            found_index = temp[right_index] > val ? right_index : -1;
            break;
        }
    }
    return found_index;
}


