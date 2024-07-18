#include <iostream>
#include "classes/Test.hpp"
#include "classes/Array.hpp"
#include "classes/DoublyLinkedList.hpp"
#include "classes/Stack.hpp"

int main() {
    Stack<int> stack;
    for (int i = 0; i < 5; ++i) {
        stack.push(i);
    }
    std::cout << "Stack size: " << stack.size() << std::endl;
    
    std::cout << "Top: " << stack.peek() << std::endl;
    
    while (!stack.isEmpty()) {
        int popped = stack.pop();
        std::cout << "Popped : " << popped << std::endl;
    }
    
    std::cout << "Stack size: " << stack.size() << std::endl;

    return 0;
}
