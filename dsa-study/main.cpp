#include <iostream>
#include "classes/Test.hpp"
#include "classes/Array.hpp"
#include "classes/DoublyLinkedList.hpp"

int main() {
    DoublyLinkedList<int> list;
    
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);
    list.addLast(4);
    
    std::cout << "List after inserting 1, 2, 3, 4: " << list.toString() << std::endl;
    std::cout << "Size: " << list.size() << std::endl;
    
    list.addFirst(0);
    
    list.addLast(6);
    
    std::cout << "List after adding 0 at the beginning and 6 at the end: " << list.toString() << std::endl;
    std::cout << "Size: " << list.size() << std::endl;
    
    list.insert(5, 5);
    
    std::cout << "List after inserting 5 at index 5: " << list.toString() << std::endl;
    std::cout << "List size: " << list.size() << std::endl;
    
    list.removeFirst();
    list.removeLast();
    
    std::cout << "List after removing 0 from the beginning and 6 from the end: " << list.toString() << std::endl;
    std::cout << "Size: " << list.size() << std::endl;
    
    bool success = list.remove(3);
    std::cout << "List after attempting to remove 3 from list: " << list.toString() << std::endl;
    std::cout << "Removed 3? " << success << std::endl;
    std::cout << "List size: " << list.size() << std::endl;
    
    list.removeAt(2);
    std::cout << "List after removing 4 at index 2: " << list.toString() << std::endl;
    std::cout << "List size: " << list.size() << std::endl;
    
    std::cout << "List first element: " << list.peekFirst() << std::endl;
    std::cout << "List last element: " << list.peekLast() << std::endl;
    
    int index = list.indexOf(2);
    std::cout << "Index of 2 is: " << index << std::endl;
    
    bool contains = list.contains(5);
    std::cout << "Contains 5? " << contains << std::endl;
    contains = list.contains(9);
    std::cout << "Contains 9? " << contains << std::endl;

    return 0;
}
