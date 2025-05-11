/**
 * @file uniquearray.h
 * @brief Header file for the UniqueReverseArray class.
 */

#pragma once

#include "arraytransformer.h"
#include "utility.h"

#include <unordered_set>

/**
 * @brief Class to find unique elements in reverse order.
 * This file defines the UniqueReverseArray class,
 * which is responsible for finding unique elements in reverse order.
 * It inherits from the ArrayTransformer class
 */
template<typename T>
class UniqueReverseArray : public ArrayTransformer<T>
{
public:
    UniqueReverseArray(const std::vector<std::vector<T>>& arrays)
    : ArrayTransformer<T>(arrays) {}

    std::string header() const override {
            return "=======Unique Elements in Reverse Order=======\n";
    }

    /**
     * Transforms the input arrays to find unique elements in reverse order.
     * This method finds unique elements across all arrays and sorts them in reverse order.
     */
    void transform() override {
        std::unordered_map<T, int> countMap;

        for (const auto& arr : this->arrays_) {
            for (const auto& val : arr) {
                countMap[val]++;
            }
        }

        std::vector<T> uniqueElements;
        for (typename std::unordered_map<T, int>::const_iterator it = countMap.begin(); it != countMap.end(); ++it) {
            if (it->second == 1) {
                uniqueElements.push_back(it->first);
            }
        }
        Sort::quickSort(uniqueElements, 0, uniqueElements.size() - 1);
        std::reverse(uniqueElements.begin(), uniqueElements.end());

        uniqueElementsInReverseOrder_.insert(uniqueElementsInReverseOrder_.end(), uniqueElements.begin(), uniqueElements.end());
    }

private:
    /**
     * Prints the unique elements in reverse order to the output stream.
     * 
     * @param out The output stream to print to.
     */
    void printArrays(std::ostream& out) const override {
        if (uniqueElementsInReverseOrder_.empty()) {
            out << "No unique elements found.\n";
            return;
        }

        for (const T& val : uniqueElementsInReverseOrder_) {
            out << val << " ";
        }
    }

    std::vector<T> uniqueElementsInReverseOrder_;
};