#pragma once

#include "arraytransformer.h"
#include "utility.h"

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