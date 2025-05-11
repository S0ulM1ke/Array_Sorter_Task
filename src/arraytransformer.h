/**
 * @file arraytransformer.h
 * @brief Header file for the ArrayTransformer class.
 */
#pragma once

#include <string>
#include <vector>

/**
 * * @brief Base class for transforming arrays.
 * This file defines the ArrayTransformer class,
 * which serves as a base class for transforming arrays.
 * It provides a common interface for derived classes to implement specific transformations.
 * * @tparam T The type of elements in the arrays.
 * * @note This class is not intended to be instantiated directly.
 * Derived classes should implement the transform() method to perform specific transformations.
 * * Derived classes should also implement the printArrays() method to customize the output format.
 * * The header() method can be overridden to provide a custom header for the output.
 */
template<typename T>
class ArrayTransformer
{
public:
    /**
     * @brief Constructor for the ArrayTransformer class.
     * @param arrays A vector of vectors containing the arrays to be transformed.
     */
    ArrayTransformer(const std::vector<std::vector<T>>& arrays) : arrays_(arrays) {}
    virtual ~ArrayTransformer() = default;

    /**
     * @brief Transforms the input arrays.
     * This method should be overridden by derived classes to perform specific transformations.
     */
    virtual void transform() = 0;

    /**
     * @brief Basic header for the output.
     * This method can be overridden by derived classes to provide a custom header.
     */
    virtual std::string header() const { return "\n"; }

    /**
     * @brief Prints the transformed arrays to the output stream.
     * @param out The output stream to print to (default is std::cout).
     */
    virtual void print(std::ostream& out = std::cout) const {
        out << header();
        printArrays(out);
    }

protected:
    /**
     * @brief Prints the arrays to the output stream.
     * This method should be overridden by derived classes to customize the output format.
     * @param out The output stream to print to.
     */
    virtual void printArrays(std::ostream& out) const {
        for (const auto& arr : arrays_) {
            for (const T& val : arr)
                out << val << " ";
            out << '\n';
        }
    }

    std::vector<std::vector<T>> arrays_;
};

/**
 * @brief Class to represent plain arrays without any transformation.
 * This class inherits from ArrayTransformer and does not perform any transformation.
 * It is used to print the input arrays as they are.
 * @tparam T The type of elements in the arrays.
 */
template<typename T>
class PlainArray : public ArrayTransformer<T>
{
public:
    PlainArray(const std::vector<std::vector<T>>& arrays)
    : ArrayTransformer<T>(arrays) {}

    std::string header() const override {
        return "=======Input Arrays=======\n";
    }

    void transform() override {
        // This class does not perform any transformation.
    }
};