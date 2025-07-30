#pragma once
#ifndef SUPERINTARRAY_H
#define SUPERINTARRAY_H

#include <iostream>
#include <vector>

class SuperIntArray {
private:
    int* nums;
    int numberOfNums;

public:
    // Constructors & Destructor
    SuperIntArray();
    SuperIntArray(int* nums, int size);
    SuperIntArray(int num);
    SuperIntArray(std::vector<int> vec);
    SuperIntArray(const SuperIntArray& arr);
    ~SuperIntArray();

    // Getters & Setters
    int getSize() const;
    int* getNums() const;
    void setNums(int* newNums, int size);

    // Core Methods
    void add(int num);
    int get(int index) const;
    void change(int index, int value);

    // Operator Overloads
    SuperIntArray& operator=(const SuperIntArray& right);
    SuperIntArray operator+(const SuperIntArray& right) const;
    int& operator[](int index);
    friend std::ostream& operator<<(std::ostream& stream, const SuperIntArray& right);

    // Static Utility Functions
    static int getMax(int nums[], int size);
    static int getMin(int nums[], int size);
    static double getMean(int nums[], int size);
};

#endif
