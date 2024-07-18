#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>

template <typename T>
class Queue {
public:
    Queue();
    Queue(T elem);
    int size() const;
    bool isEmpty() const;
    T peek() const;
    void enqueue(T elem);
    T deqeueu();
    
private:
    
    
}

#endif /* Queue_hpp */
