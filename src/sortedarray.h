/**
 * @file sotedarray.h
 * @brief Header file for the SortedArray class.
 */

#pragma once

#include "arraytransformer.h"
#include "utility.h"

/**
 * @brief Class to sort multiple arrays.
 * This file defines the SortedArray class,
 * which is responsible for sorting multiple arrays.
 * It inherits from the ArrayTransformer class
 */
template<typename T>
class SortedArray : public ArrayTransformer<T>
{
public:
    SortedArray(const std::vector<std::vector<T>>& arrays)
    : ArrayTransformer<T>(arrays) {}

    std::string header() const override {
        return "=======Sorted Arrays=======\n";
    }

    void transform() override {
        for (auto& arr : this->arrays_) {
            Sort::quickSort(arr, 0, arr.size() - 1);
        }
    }
};