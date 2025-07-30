#include "SuperIntArray.h"
#include <iostream>
#include <vector>

int main() {
    // Create array from vector
    std::vector<int> vec = { 1, 2, 3, 4 };
    SuperIntArray arr1(vec);

    // Add a number
    arr1.add(5);

    // Change a value
    arr1.change(0, 10);

    // Print array
    std::cout << "arr1: " << arr1 << std::endl;

    // Create from single int
    SuperIntArray arr2(100);
    std::cout << "arr2: " << arr2 << std::endl;

    // Use copy constructor
    SuperIntArray arr3 = arr1;
    std::cout << "arr3 (copy of arr1): " << arr3 << std::endl;

    // Concatenate arrays
    SuperIntArray arr4 = arr1 + arr2;
    std::cout << "arr4 (arr1 + arr2): " << arr4 << std::endl;

    // Access using []
    std::cout << "arr4[0]: " << arr4[0] << std::endl;
    arr4[0] = 999;
    std::cout << "arr4 after changing index 0: " << arr4 << std::endl;

    // Use static functions
    int* nums = arr4.getNums();
    int size = arr4.getSize();
    std::cout << "Max: " << SuperIntArray::getMax(nums, size) << std::endl;
    std::cout << "Min: " << SuperIntArray::getMin(nums, size) << std::endl;
    std::cout << "Mean: " << SuperIntArray::getMean(nums, size) << std::endl;

    return 0;
}
