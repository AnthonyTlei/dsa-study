#include <iostream>
#include "classes/Test.hpp"
#include "classes/Array.hpp"
#include "classes/DoublyLinkedList.hpp"
#include "classes/Stack.hpp"
#include "classes/Queue.hpp"

int main() {
    Queue<int> q;
    
    for (int i = 0; i < 5; ++i) {
        q.enqueue(i);
    }
    
    std::cout << "Queue size: " << q.size() << std::endl;
    std::cout << "Queue front: " << q.peek() << std::endl;
    
    while (!q.isEmpty()) {
        int done = q.dequeue();
        std::cout << "De-queued: " << done << std::endl;
    }
    
    std::cout << "Queue size: " << q.size() << std::endl;

    return 0;
}
