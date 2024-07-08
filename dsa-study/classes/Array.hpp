#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>
#include <iostream>

template <typename T>
class Array {
public:
    Array();
    Array(int capacity);
    ~Array();

    std::size_t size() const;
    bool isEmpty() const;
    T get(int index) const;
    void set(int index, T value);
    void clear();
    void add(T elem);
    void removeAt(int index);
    void remove(T elem);

private:
    T* data;
    int length;
    int capacity;
    
private:
    void resize(int newCapacity);
};

template <typename T>
Array<T>::Array() : length(0), capacity(16) {
    data = new T[capacity];
}

template <typename T>
Array<T>::Array(int capacity) : length(0), capacity(capacity) {
    if (capacity <= 0) {
        throw std::invalid_argument("Capacity must be greater than 0");
    }
    data = new T[capacity];
}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template <typename T>
std::size_t Array<T>::size() const {
    return length;
}

template <typename T>
bool Array<T>::isEmpty() const {
    return length == 0;
}

template <typename T>
T Array<T>::get(int index) const {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
void Array<T>::set(int index, T value) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }
    data[index] = value;
}

template <typename T>
void Array<T>::clear() {
    delete[] data;
    data = new T[capacity];
    length = 0;
}

template <typename T>
void Array<T>::add(T elem) {
    if (length >= capacity) {
        resize(capacity * 2);
    }
    data[length++] = elem;
}

template <typename T>
void Array<T>::removeAt(int index) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }
    for (int i = index; i < length - 1; ++i) {
        data[i] = data[i + 1];
    }
    --length;
}

template <typename T>
void Array<T>::remove(T elem) {
    for (int i = 0; i < length; ++i) {
        if (data[i] == elem) {
            removeAt(i);
            --i;
        }
    }
}

template <typename T>
void Array<T>::resize(int newCapacity) {
    T* newData = new T[newCapacity];
    std::copy(data, data + length, newData);
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

#endif /* Array_hpp */
