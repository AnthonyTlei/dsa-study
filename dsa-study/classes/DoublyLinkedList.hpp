#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp

#include <stdio.h>
#include <stdexcept>
#include <string>
#include <sstream>

template <typename T>
class DoublyLinkedList {
    
private:
    class Node {
    public:
        Node(T data, Node* prev = nullptr, Node* next = nullptr)
        : data(data), prev(prev), next(next) {}
        T data;
        Node* prev;
        Node* next;
    };
    
private:
    int _size = 0;
    Node* _head = nullptr;
    Node* _tail = nullptr;
    
public:
    DoublyLinkedList();
    void clear();
    int size() const;
    bool isEmpty() const;
    void insert(T elem, int index);
    void addFirst(T elem);
    void addLast(T elem);
    T peekFirst() const;
    T peekLast() const;
    T removeFirst();
    T removeLast();
    bool remove(T elem);
    T removeAt(int index);
    int indexOf(T elem) const;
    bool contains(T elem) const;
    std::string toString() const;
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : _size(0), _head(nullptr), _tail(nullptr) {}

template <typename T>
int DoublyLinkedList<T>::size() const {
    return _size;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() const {
    return _size == 0;
}

template <typename T>
void DoublyLinkedList<T>::addFirst(T elem) {
    if (isEmpty()) {
        _head = new Node(elem, nullptr, nullptr);
        _tail = _head;
    } else {
        Node* temp = new Node(elem, nullptr, _head);
        _head->prev = temp;
        _head = temp;
    }
    _size++;
}

template <typename T>
void DoublyLinkedList<T>::addLast(T elem) {
    if (isEmpty()) {
        _head = new Node(elem, nullptr, nullptr);
        _tail = _head;
    } else {
        Node* temp = new Node(elem, _tail, nullptr);
        _tail->next = temp;
        _tail = temp;
    }
    _size++;
}

template <typename T>
void DoublyLinkedList<T>::insert(T elem, int index) {
    if (index < 0 || index > _size) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        addFirst(elem);
        return;
    }
    if (index == _size) {
        addLast(elem);
        return;
    }
    Node* traverser = _head;
    for (int i = 0; i < index - 1; ++i) {
        traverser = traverser->next;
    }
    Node* temp = new Node(elem, traverser, traverser->next);
    traverser->next->prev = temp;
    traverser->next = temp;
    _size++;
}

template <typename T>
T DoublyLinkedList<T>::peekFirst() const {
    return _head->data;
}

template <typename T>
T DoublyLinkedList<T>::peekLast() const {
    return _tail->data;
}

template <typename T>
T DoublyLinkedList<T>::removeFirst() {
    if (isEmpty()) {
        throw std::out_of_range("List is empty");
    }
    Node* temp = _head;
    T data = temp->data;
    _head = _head->next;
    if (_head != nullptr) {
        _head->prev = nullptr;
    } else {
        _tail = nullptr;
    }
    delete temp;
    _size--;
    return data;
}

template <typename T>
T DoublyLinkedList<T>::removeLast() {
    if (isEmpty()) {
        throw std::out_of_range("List is empty");
    }
    Node* temp = _tail;
    T data = temp->data;
    _tail = _tail->prev;
    if (_tail != nullptr) {
        _tail->next = nullptr;
    } else {
        _head = nullptr;
    }
    delete temp;
    _size--;
    return data;
}

template <typename T>
T DoublyLinkedList<T>::removeAt(int index) {
    if (isEmpty()) {
        throw std::out_of_range("List is empty");
    }
    if (index < 0 || index >= _size) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        return removeFirst();
    }
    if (index == _size - 1) {
        return removeLast();
    }
    Node* temp = _head;
    for(int i=0; i < index; ++i) {
        temp = temp->next;
    }
    T data = temp->data;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    _size--;
    return data;
}

template <typename T>
bool DoublyLinkedList<T>::remove(T elem) {
    if (isEmpty()) {
        throw std::out_of_range("List is empty");
    }
    
    Node* temp = _head;
    while (temp != nullptr) {
        if (temp->data == elem) {
            if (temp == _head) {
                removeFirst();
            } else if (temp == _tail) {
                removeLast();
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                _size--;
            }
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <typename T>
int DoublyLinkedList<T>::indexOf(T elem) const {
    int i = 0;
    Node* temp = _head;
    while (temp != nullptr) {
        if (temp->data == elem) {
            return i;
        }
        temp = temp->next;
        ++i;
    }
    return -1;
}

template <typename T>
bool DoublyLinkedList<T>::contains(T elem) const {
    return indexOf(elem) != -1;
}

template <typename T>
std::string DoublyLinkedList<T>::toString() const {
    std::ostringstream oss;
    Node* traverser = _head;
    oss << "[";
    while (traverser != nullptr) {
        oss << traverser->data;
        if (traverser->next != nullptr) {
            oss << ", ";
        }
        traverser = traverser->next;
    }
    oss << "]";
    return oss.str();
}

#endif /* DoublyLinkedList_hpp */
