#pragma once

#include "arraytransformer.h"
#include "sort.h"

#include <unordered_set>

template<typename T>
class UniqueReverseArray : public ArrayTransformer<T>
{
public:
    UniqueReverseArray(const std::vector<std::vector<T>>& arrays)
    : ArrayTransformer<T>(arrays) {}

    std::string header() const override {
            return "=======Unique Elements in Reverse Order=======\n";
    }

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

        _uniqueElementsInReverseOrder.insert(_uniqueElementsInReverseOrder.end(), uniqueElements.begin(), uniqueElements.end());
    }

private:
    void printArrays(std::ostream& out) const override {
        if (_uniqueElementsInReverseOrder.empty()) {
            out << "No unique elements found.\n";
            return;
        }

        for (const T& val : _uniqueElementsInReverseOrder) {
            out << val << " ";
        }
    }

    std::vector<T> _uniqueElementsInReverseOrder;
};