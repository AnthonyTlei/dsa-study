#include <iostream>
#include <vector>

#include "classes/Test.hpp"
#include "classes/Array.hpp"
#include "classes/DoublyLinkedList.hpp"
#include "classes/Stack.hpp"
#include "classes/Queue.hpp"
#include "classes/PQueue.hpp"

int main() {
    // Test Constructor
    std::vector<int> elements = {3, 1, 6, 5, 2, 4};
    PQueue<int> pq(elements);

    // Test toString
    std::cout << "Initial heap: " << pq.toString() << std::endl;

    // Test size and isEmpty
    std::cout << "Size: " << pq.size() << std::endl;
    std::cout << "Is empty: " << (pq.isEmpty() ? "Yes" : "No") << std::endl;

    // Test contains
    std::cout << "Contains 5: " << (pq.contains(5) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 10: " << (pq.contains(10) ? "Yes" : "No") << std::endl;

    // Test add
    pq.add(7);
    std::cout << "Heap after adding 7: " << pq.toString() << std::endl;
    pq.add(1);
    std::cout << "Heap after adding 1: " << pq.toString() << std::endl;

    // Test peek
    std::cout << "Peek: " << pq.peek() << std::endl;

    // Test poll
    std::cout << "Poll: " << pq.poll() << std::endl;
    std::cout << "Heap after poll: " << pq.toString() << std::endl;

    // Test remove
    std::cout << "Remove 5: " << (pq.remove(5) ? "Removed" : "Not found") << std::endl;
    std::cout << "Contains 5: " << (pq.contains(5) ? "Yes" : "No") << std::endl;
    std::cout << "Heap after removing 5: " << pq.toString() << std::endl;

    // Test removeAt
    std::cout << "Remove at index 2: " << pq.removeAt(2) << std::endl;
    std::cout << "Heap after removing at index 2: " << pq.toString() << std::endl;
    
    // Print map
    pq.printMap();
    
    // Test isMinHeap
    PQueue<int> pq2(elements);
    std::cout << "Is min heap: " << (pq2.isMinHeap() ? "Yes" : "No") << std::endl;

    // Test clear
    pq.clear();
    std::cout << "Heap after clear: " << pq.toString() << std::endl;

    return 0;
}
