#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include <stdexcept>
#include "DoublyLinkedList.hpp"

template <typename T>
class Queue {
public:
    Queue();
    Queue(T elem);
    ~Queue();
    int size() const;
    bool isEmpty() const;
    T peek() const;
    void enqueue(T elem);
    T dequeue();
    
private:
    DoublyLinkedList<T>* _queue;
};

template <typename T>
Queue<T>::Queue() {
    _queue = new DoublyLinkedList<T>;
}

template <typename T>
Queue<T>::Queue(T elem) {
    _queue = new DoublyLinkedList<T>;
    _queue->addLast(elem);
}

template <typename T>
Queue<T>::~Queue() {
    delete _queue;
}

template <typename T>
int Queue<T>::size() const {
    return _queue->size();
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return _queue->isEmpty();
}

template <typename T>
T Queue<T>::peek() const {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return _queue->peekFirst();
}

template <typename T>
void Queue<T>::enqueue(T elem) {
    _queue->addLast(elem);
}

template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return _queue->removeFirst();
}

#endif /* Queue_hpp */
