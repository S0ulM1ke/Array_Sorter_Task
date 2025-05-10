#pragma once

#include "arraytransformer.h"

#include <unordered_map>

template<typename T>
class IntersectArray : public ArrayTransformer<T>
{
public:
    IntersectArray(const std::vector<std::vector<T>>& arrays)
    : ArrayTransformer<T>(arrays) {}

    std::string header() const override {
        return "=======Intersection of Arrays=======\n";
    }

    void transform() override {
        std::pair<std::vector<T>, std::vector<T>> longest = findTwoLongest(this->arrays_);
        const std::vector<T>& first = longest.first;
        const std::vector<T>& second = longest.second;
        _intersectionOfLongestArrays = intersectArrays({first, second});

        _intersectionOfAllArrays = intersectArrays(this->arrays_);
    }

private:
    void printArrays(std::ostream& out) const override {
        if (_intersectionOfLongestArrays.empty() && _intersectionOfAllArrays.empty()) {
            out << "No intersection found.\n";
            return;
        }

        if (!_intersectionOfLongestArrays.empty()) {
            out << "Intersection of Longest Arrays:\n";
            for (const T& val : _intersectionOfLongestArrays) {
                out << val << " ";
            }
        }  else {
            out << "No intersection found between longest arrays.\n";
        }

        out << "\n\n";

        if (!_intersectionOfAllArrays.empty()) {
            out << "Intersection of All Arrays:\n";
            for (const T& val : _intersectionOfAllArrays) {
                out << val << " ";
            }
        } else {
            out << "No intersection found between all arrays.\n";
        }
    }

    std::pair<std::vector<T>, std::vector<T>> findTwoLongest(const std::vector<std::vector<T>>& arrays) {
        if (arrays.size() < 2)
            throw std::runtime_error("Need at least two arrays");
    
        std::vector<T> first, second;
        for (const auto& arr : arrays) {
            if (arr.size() > first.size()) {
                second = first;
                first = arr;
            } else if (arr.size() > second.size()) {
                second = arr;
            }
        }
        return {first, second};
    }

    std::vector<T> intersectArrays(const std::vector<std::vector<T>>& arrays) {
        if (arrays.empty()) return {};

        std::unordered_map<T, int> countMap;
        for (const auto& val : arrays[0])
            ++countMap[val];
    
        for (size_t i = 1; i < arrays.size(); ++i) {
            std::unordered_map<T, int> local;
            for (const auto& val : arrays[i]) {
                if (countMap.count(val))
                    ++local[val];
            }
            countMap = local;
        }
    
        std::vector<T> result;
        for (typename std::unordered_map<T, int>::const_iterator it = countMap.begin(); it != countMap.end(); ++it) {
            result.push_back(it->first);
        }
        
        return result;
    }

    std::vector<T> _intersectionOfLongestArrays;
    std::vector<T> _intersectionOfAllArrays;
};
