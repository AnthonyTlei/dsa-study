#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include <stdexcept>
#include "DoublyLinkedList.hpp"

template <typename T>
class Stack {
public:
    Stack();
    Stack(T elem);
    ~Stack();
    int size() const;
    bool isEmpty() const;
    void push(T elem);
    T pop();
    T peek() const;
    
private:
    DoublyLinkedList<T>* _stack;
};

template <typename T>
Stack<T>::Stack() {
    _stack = new DoublyLinkedList<T>;
}

template <typename T>
Stack<T>::Stack(T elem) {
    _stack = new DoublyLinkedList<T>;
    _stack->addFirst(elem);
}

template <typename T>
Stack<T>::~Stack() {
    delete _stack;
}

template <typename T>
int Stack<T>::size() const {
    return _stack->size();
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return _stack->isEmpty();
}

template <typename T>
void Stack<T>::push(T elem) {
    _stack->addFirst(elem);
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return _stack->removeFirst();
}

template <typename T>
T Stack<T>::peek() const {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return _stack->peekFirst();
}

#endif /* Stack_hpp */
