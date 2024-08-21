#include <iostream>
#include <vector>
#include <algorithm>

#include "classes/Test.hpp"
#include "classes/Array.hpp"
#include "classes/DoublyLinkedList.hpp"
#include "classes/Stack.hpp"
#include "classes/Queue.hpp"
#include "classes/PQueue.hpp"
#include "classes/UnionFind.hpp"
#include "classes/BinarySearchTree.hpp"

int main() {
    // Create a BinarySearchTree of integers
    BinarySearchTree<int> bst;

    // Test isEmpty on an empty tree
    std::cout << "Is tree empty? " << bst.isEmpty() << " (Expected: 1)\n"; // Expected: 1 (true)

    // Test add method
    bst.add(10);
    bst.add(5);
    bst.add(15);
    bst.add(3);
    bst.add(7);
    bst.add(13);
    bst.add(18);

    // Test isEmpty after adding elements
    std::cout << "Is tree empty? " << bst.isEmpty() << " (Expected: 0)\n"; // Expected: 0 (false)

    // Test size method
    std::cout << "Tree size: " << bst.size() << " (Expected: 7)\n"; // Expected: 7

    // Test min method
    std::cout << "Minimum value: " << bst.min() << " (Expected: 3)\n"; // Expected: 3

    // Test max method
    std::cout << "Maximum value: " << bst.max() << " (Expected: 18)\n"; // Expected: 18

    // Test height method
    std::cout << "Tree height: " << bst.height() << " (Expected: 2)\n"; // Expected: 2

    // Test contains method
    std::cout << "Contains 7? " << bst.contains(7) << " (Expected: 1)\n"; // Expected: 1 (true)
    std::cout << "Contains 4? " << bst.contains(4) << " (Expected: 0)\n"; // Expected: 0 (false)

    // Test traversal methods
    std::cout << "In-order traversal: ";
    bst.traverse(BinarySearchTree<int>::TraversalOrder::IN_ORDER); // Expected: 3 5 7 10 13 15 18
    std::cout << std::endl;

    std::cout << "Pre-order traversal: ";
    bst.traverse(BinarySearchTree<int>::TraversalOrder::PRE_ORDER); // Expected: 10 5 3 7 15 13 18
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    bst.traverse(BinarySearchTree<int>::TraversalOrder::POST_ORDER); // Expected: 3 7 5 13 18 15 10
    std::cout << std::endl;

    std::cout << "Level-order traversal: ";
    bst.traverse(BinarySearchTree<int>::TraversalOrder::LEVEL_ORDER); // Expected: 10 5 15 3 7 13 18
    std::cout << std::endl;

    // Test remove method
    bst.remove(15); // Removing a node with two children
    std::cout << "After removing 15, in-order traversal: ";
    bst.traverse(BinarySearchTree<int>::TraversalOrder::IN_ORDER); // Expected: 3 5 7 10 13 18
    std::cout << std::endl;

    bst.remove(5); // Removing a node with two children
    std::cout << "After removing 5, in-order traversal: ";
    bst.traverse(BinarySearchTree<int>::TraversalOrder::IN_ORDER); // Expected: 3 7 10 13 18
    std::cout << std::endl;

    bst.remove(3); // Removing a leaf node
    std::cout << "After removing 3, in-order traversal: ";
    bst.traverse(BinarySearchTree<int>::TraversalOrder::IN_ORDER); // Expected: 7 10 13 18
    std::cout << std::endl;

    bst.remove(10); // Removing the root node
    std::cout << "After removing 10, in-order traversal: ";
    bst.traverse(BinarySearchTree<int>::TraversalOrder::IN_ORDER); // Expected: 7 13 18
    std::cout << std::endl;

    // Test clear method
    bst.clear();
    std::cout << "After clearing, is tree empty? " << bst.isEmpty() << " (Expected: 1)\n"; // Expected: 1 (true)

    return 0;
}
