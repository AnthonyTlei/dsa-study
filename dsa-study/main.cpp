#include <iostream>
#include "classes/Test.hpp"
#include "classes/Array.hpp"

template <typename T>
void printArray(const Array<T>& arr) {
    for (std::size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr.get(i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    Array<int> arr(5);

    for (int i = 0; i < 5;) {
        arr.add(++i);
    }

    printArray(arr);
    
    std::cout << std::endl;
    std::cout << "Array size: " << arr.size() << std::endl;
    std::cout << "Array third element : " << arr.get(2) << std::endl;
    std::cout << "Array is empty: " << (arr.isEmpty() ? "Yes" : "No") << std::endl;
    arr.clear();
    std::cout << "Array is empty after clear: " << (arr.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
