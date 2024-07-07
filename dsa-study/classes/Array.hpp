#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T, std::size_t N>
class Array {
public:
    Array();
    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;
    std::size_t size() const;

private:
    T data[N];
};

template <typename T, std::size_t N>
Array<T, N>::Array() {
    for (std::size_t i = 0; i < N; ++i) {
        data[i] = T();
    }
}

template <typename T, std::size_t N>
T& Array<T, N>::operator[](std::size_t index) {
    if (index >= N) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T, std::size_t N>
const T& Array<T, N>::operator[](std::size_t index) const {
    if (index >= N) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T, std::size_t N>
std::size_t Array<T, N>::size() const {
    return N;
}

#endif /* Array_hpp */
