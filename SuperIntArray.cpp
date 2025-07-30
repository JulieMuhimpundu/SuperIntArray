#include "SuperIntArray.h"
#include <stdexcept>
#include <iomanip>
#include <numeric>
#include <algorithm>

SuperIntArray::SuperIntArray() : nums(nullptr), numberOfNums(0) {}

SuperIntArray::SuperIntArray(int* inputNums, int size) {
    numberOfNums = size;
    nums = new int[size];
    for (int i = 0; i < size; ++i) {
        nums[i] = inputNums[i];
    }
}

SuperIntArray::SuperIntArray(int num) {
    numberOfNums = 1;
    nums = new int[1];
    nums[0] = num;
}

SuperIntArray::SuperIntArray(std::vector<int> vec) {
    numberOfNums = vec.size();
    nums = new int[numberOfNums];
    for (int i = 0; i < numberOfNums; ++i) {
        nums[i] = vec[i];
    }
}

SuperIntArray::SuperIntArray(const SuperIntArray& arr) {
    numberOfNums = arr.numberOfNums;
    nums = new int[numberOfNums];
    for (int i = 0; i < numberOfNums; ++i) {
        nums[i] = arr.nums[i];
    }
}

SuperIntArray::~SuperIntArray() {
    delete[] nums;
}

int SuperIntArray::getSize() const {
    return numberOfNums;
}

int* SuperIntArray::getNums() const {
    return nums;
}

void SuperIntArray::setNums(int* newNums, int size) {
    delete[] nums;
    numberOfNums = size;
    nums = new int[size];
    for (int i = 0; i < size; ++i) {
        nums[i] = newNums[i];
    }
}

void SuperIntArray::add(int num) {
    int* newArr = new int[numberOfNums + 1];
    for (int i = 0; i < numberOfNums; ++i) {
        newArr[i] = nums[i];
    }
    newArr[numberOfNums] = num;
    delete[] nums;
    nums = newArr;
    numberOfNums++;
}

int SuperIntArray::get(int index) const {
    if (index < 0 || index >= numberOfNums) {
        throw std::out_of_range("Index out of range");
    }
    return nums[index];
}

void SuperIntArray::change(int index, int value) {
    if (index < 0 || index >= numberOfNums) {
        throw std::out_of_range("Index out of range");
    }
    nums[index] = value;
}

SuperIntArray& SuperIntArray::operator=(const SuperIntArray& right) {
    if (this != &right) {
        delete[] nums;
        numberOfNums = right.numberOfNums;
        nums = new int[numberOfNums];
        for (int i = 0; i < numberOfNums; ++i) {
            nums[i] = right.nums[i];
        }
    }
    return *this;
}

SuperIntArray SuperIntArray::operator+(const SuperIntArray& right) const {
    SuperIntArray result;
    result.numberOfNums = numberOfNums + right.numberOfNums;
    result.nums = new int[result.numberOfNums];
    for (int i = 0; i < numberOfNums; ++i) {
        result.nums[i] = nums[i];
    }
    for (int i = 0; i < right.numberOfNums; ++i) {
        result.nums[numberOfNums + i] = right.nums[i];
    }
    return result;
}

int& SuperIntArray::operator[](int index) {
    if (index < 0 || index >= numberOfNums) {
        throw std::out_of_range("Index out of range");
    }
    return nums[index];
}

std::ostream& operator<<(std::ostream& stream, const SuperIntArray& right) {
    stream << "[";
    for (int i = 0; i < right.numberOfNums; ++i) {
        stream << right.nums[i];
        if (i < right.numberOfNums - 1)
            stream << ", ";
    }
    stream << "]";
    return stream;
}

int SuperIntArray::getMax(int nums[], int size) {
    return *std::max_element(nums, nums + size);
}

int SuperIntArray::getMin(int nums[], int size) {
    return *std::min_element(nums, nums + size);
}

double SuperIntArray::getMean(int nums[], int size) {
    if (size == 0) return 0;
    int sum = std::accumulate(nums, nums + size, 0);
    return static_cast<double>(sum) / size;
}

