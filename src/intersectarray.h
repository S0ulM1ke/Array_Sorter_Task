/**
 * @file intersectarray.h
 * @brief Header file for the IntersectArray class.
*/

#pragma once

#include "arraytransformer.h"

#include <unordered_map>

/**
 * @brief Class to find the intersection of multiple arrays.
 * This file defines the IntersectArray class,
 * which is responsible for finding
 * the intersection of multiple arrays.
 * It inherits from the ArrayTransformer class
 */
template<typename T>
class IntersectArray : public ArrayTransformer<T>
{
public:
    IntersectArray(const std::vector<std::vector<T>>& arrays)
    : ArrayTransformer<T>(arrays) {}

    std::string header() const override {
        return "=======Intersection of Arrays=======\n";
    }

    /**
     * Transforms the input arrays to find the intersection.
     * This method finds the intersection of the two longest arrays
     * and the intersection of all arrays.
     */
    void transform() override {
        std::pair<std::vector<T>, std::vector<T>> longest = findTwoLongest(this->arrays_);
        const std::vector<T>& first = longest.first;
        const std::vector<T>& second = longest.second;
        intersectionOfLongestArrays_ = intersectArrays({first, second});

        intersectionOfAllArrays_ = intersectArrays(this->arrays_);
    }

private:
    /**
     * Prints the intersection arrays to the output stream.
     * 
     * @param out The output stream to print to.
     */
    void printArrays(std::ostream& out) const override {
        if (intersectionOfLongestArrays_.empty() && intersectionOfAllArrays_.empty()) {
            out << "No intersection found.\n";
            return;
        }

        if (!intersectionOfLongestArrays_.empty()) {
            out << "Intersection of Longest Arrays:\n";
            for (const T& val : intersectionOfLongestArrays_) {
                out << val << " ";
            }
        }  else {
            out << "No intersection found between longest arrays.\n";
        }

        out << "\n\n";

        if (!intersectionOfAllArrays_.empty()) {
            out << "Intersection of All Arrays:\n";
            for (const T& val : intersectionOfAllArrays_) {
                out << val << " ";
            }

            out << "\n";
        } else {
            out << "No intersection found between all arrays.\n";
        }
    }

    /**
     * Finds the two longest arrays from the given list of arrays.
     * 
     * @param arrays A vector of vectors containing the arrays to evaluate.
     * @return A pair of vectors representing the two longest arrays.
     * @throws std::runtime_error if the input contains fewer than two arrays.
     */
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

    /**
     * Finds the intersection of multiple arrays.
     * 
     * @param arrays A vector of vectors containing the arrays to evaluate.
     * @return A vector containing the elements that are present in all arrays.
     */
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

    std::vector<T> intersectionOfLongestArrays_;
    std::vector<T> intersectionOfAllArrays_;
};
