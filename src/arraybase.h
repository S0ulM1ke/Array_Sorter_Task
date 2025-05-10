#pragma once

template<typename T>
class ArrayBase
{
public:
    ArrayBase(const std::vector<std::vector<T>>& arrays) : arrays_(arrays) {}
    virtual ~ArrayBase() = default;

    virtual void transform() = 0;
    virtual void print(std::ostream& out = std::cout) const {
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
class PlainArray : public ArrayBase<T>
{
public:
    PlainArray(const std::vector<std::vector<T>>& arrays)
    : ArrayBase<T>(arrays) {}

    void transform() override {
        // This class does not perform any transformation.
    }
};