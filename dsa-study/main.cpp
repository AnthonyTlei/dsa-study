#include <iostream>
#include "classes/Test.hpp"
#include "classes/Array.hpp"

int main(int argc, const char * argv[]) {
    Test test;
    test.sayHello();
    
    std::cout << std::endl;
    
    Array<int, 5> arr;
    for (std::size_t i = 0; i < arr.size(); ++i) {
            arr[i] = static_cast<int>(i) * 10;
        }

    for (std::size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    
    return 0;
}
