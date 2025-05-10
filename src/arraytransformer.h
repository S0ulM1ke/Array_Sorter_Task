#pragma once

#include <string>
#include <vector>

template<typename T>
class ArrayTransformer
{
public:
    ArrayTransformer(const std::vector<std::vector<T>>& arrays) : arrays_(arrays) {}
    virtual ~ArrayTransformer() = default;

    virtual void transform() = 0;
    virtual std::string header() const { return "\n"; }
    virtual void print(std::ostream& out = std::cout) const {
        out << header();
        printArrays(out);
    }

private:
    virtual void printArrays(std::ostream& out) const {
        for (const auto& arr : arrays_) {
            for (const T& val : arr)
                out << val << " ";
            out << '\n';
        }
    }

protected:
    std::vector<std::vector<T>> arrays_;
};

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