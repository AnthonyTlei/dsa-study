#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <stdio.h>
#include <algorithm>
#include <stdexcept>
#include <queue>

template <typename T>
class BinarySearchTree {
    
private:
    class Node {
    public:
        Node(T data, Node* left = nullptr, Node* right = nullptr)
        : data(data), left(left), right(right) {}
        T data;
        Node* left;
        Node* right;
    };
    
private:
    int _nodeCount = 0;
    Node* _root = nullptr;
    
public:
    enum class TraversalOrder {
        IN_ORDER,
        PRE_ORDER,
        POST_ORDER,
        LEVEL_ORDER
    };
    
public:
    bool isEmpty() const;
    int size() const;
    int height() const;
    bool contains(T elem) const;
    void traverse(TraversalOrder order) const;
    T min() const;
    T max() const;
    bool add(T elem);
    bool remove(T elem);
    void clear();
    
private:
    int _height(Node* node) const;
    bool _contains(Node* node, T elem) const;
    Node* _add(Node* node, T elem);
    Node* _remove(Node* node, T elem);
    void _clear(Node* node);
    Node* _min(Node* node) const;
    Node* _max(Node* node) const;
    void _in_order_traversal(Node* root) const;
    void _pre_order_traversal(Node* root) const;
    void _post_order_traversal(Node* root) const;
    void _level_order_traversal(Node* root) const;
};

template <typename T>
bool BinarySearchTree<T>::isEmpty() const {
    return _nodeCount == 0;
}

template <typename T>
int BinarySearchTree<T>::size() const {
    return _nodeCount;
}

template <typename T>
int BinarySearchTree<T>::height() const {
    return _height(_root);
}

template <typename T>
int BinarySearchTree<T>::_height(Node* node) const {
    if (node == nullptr) {
        return -1;
    }
    return std::max(_height(node->left), _height(node->right)) + 1;
}

template <typename T>
bool BinarySearchTree<T>::contains(T elem) const {
    return _contains(_root, elem);
}

template <typename T>
bool BinarySearchTree<T>::_contains(Node* node, T elem) const {
    if (node == nullptr) {
        return false;
    }
    if (elem < node->data) {
        return _contains(node->left, elem);
    }
    if (elem > node->data) {
        return _contains(node->right, elem);
    }
    return true;
}

template <typename T>
T BinarySearchTree<T>::min() const {
    if (_root == nullptr) {
        throw std::runtime_error("Tree is empty, no minimum value.");
    }
    return _min(_root)->data;
}

template <typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::_min(Node* node) const {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

template <typename T>
T BinarySearchTree<T>::max() const {
    if (_root == nullptr) {
        throw std::runtime_error("Tree is empty, no maximum value.");
    }
    return _max(_root)->data;
}

template <typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::_max(Node* node) const {
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

template <typename T>
void BinarySearchTree<T>::traverse(TraversalOrder order) const {
    switch (order) {
        case TraversalOrder::IN_ORDER:
            _in_order_traversal(_root);
            break;
        case TraversalOrder::PRE_ORDER:
            _pre_order_traversal(_root);
            break;
        case TraversalOrder::POST_ORDER:
            _post_order_traversal(_root);
            break;
        case TraversalOrder::LEVEL_ORDER:
            _level_order_traversal(_root);
            break;
        default:
            throw std::invalid_argument("Invalid traversal order");
    }
}

template <typename T>
void BinarySearchTree<T>::_in_order_traversal(Node* node) const {
    if (node == nullptr) {
        return;
    }
    _in_order_traversal(node->left);
    std::cout << node->data << " ";
    _in_order_traversal(node->right);
}

template <typename T>
void BinarySearchTree<T>::_pre_order_traversal(Node* node) const {
    if (node == nullptr) {
        return;
    }
    std::cout << node->data << " ";
    _pre_order_traversal(node->left);
    _pre_order_traversal(node->right);
}

template <typename T>
void BinarySearchTree<T>::_post_order_traversal(Node* node) const {
    if (node == nullptr) {
        return;
    }
    _post_order_traversal(node->left);
    _post_order_traversal(node->right);
    std::cout << node->data << " ";
}

template <typename T>
void BinarySearchTree<T>::_level_order_traversal(Node* node) const {
    if (node == nullptr) {
        return;
    }
    std::queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
        Node* current = q.front();
        std::cout << current->data << " ";
        q.pop();
        
        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

template <typename T>
bool BinarySearchTree<T>::add(T elem) {
    if (contains(elem)) {
        return false;
    }
    _root = _add(_root, elem);
    _nodeCount++;
    return true;
}

template <typename T>
BinarySearchTree<T>::Node* BinarySearchTree<T>::_add(Node* node, T elem) {
    if (node == nullptr) {
        node = new Node(elem, nullptr, nullptr);
    } else if (elem < node->data) {
        node->left = _add(node->left, elem);
    } else if (elem > node->data) {
        node->right = _add(node->right, elem);
    }
    return node;
}

template <typename T>
bool BinarySearchTree<T>::remove(T elem) {
    if (!contains(elem)) {
        return false;
    }
    _root = _remove(_root, elem);
    _nodeCount--;
    return true;
}

template <typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::_remove(Node* node, T elem) {
    if (node == nullptr) {
        return nullptr;
    }
    if (elem < node->data) {
        node->left = _remove(node->left, elem);
    } else if (elem > node->data) {
        node->right = _remove(node->right, elem);
    } else {
        // Node with no children
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        // Node with only right child
        if (node->left == nullptr) {
            Node* rightChild = node->right;
            delete node;
            return rightChild;
        }
        // Node with only left child
        if (node->right == nullptr) {
            Node* leftChild = node->left;
            delete node;
            return leftChild;
        }
        // Node with two children
        if (node->left != nullptr && node->right != nullptr) {
            Node* successor = _min(node->right);
            node->data = successor->data;
            node->right = _remove(node->right, successor->data);
        }
    }
    return node;
}

template <typename T>
void BinarySearchTree<T>::clear() {
    _clear(_root);
    _root = nullptr;
    _nodeCount = 0;
}

template <typename T>
void BinarySearchTree<T>::_clear(Node* node) {
    if (node == nullptr) {
        return;
    }

    _clear(node->left);
    _clear(node->right);

    delete node;
}

#endif /* BinarySearchTree_hpp */
