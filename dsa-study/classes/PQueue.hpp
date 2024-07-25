#ifndef PQueue_hpp
#define PQueue_hpp

#include <stdio.h>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include <sstream>

template <typename T>
class PQueue {
public:
    PQueue();
    PQueue(const std::vector<T>& elements);
    ~PQueue();
    
    int size() const;
    bool isEmpty() const;
    bool contains(const T& elem) const;
    bool isMinHeap() const;
    
    void add(const T& elem);
    T peek() const;
    T poll();
    bool remove(const T& elem);
    T removeAt(int i);
    
    void clear();
    std::string toString() const;
    void printMap() const;
    
private:
    std::vector<T> _heap;
    std::unordered_map<T, std::set<int>> _map;
    
private:
    bool less(int i, int j) const;
    void swap(int i, int j);
    void addToMap(const T& key, int value);
    void removeFromMap(const T& key, int value);
    int getFromMap(const T& key) const;
    void swapInMap(const T& key1, int value1, const T& key2, int value2);
    void bubbleUp(int k);
    void bubbleDown(int k);
};

/* Public Methods */

template <typename T>
PQueue<T>::PQueue() {}

template <typename T>
PQueue<T>::PQueue(const std::vector<T>& elements) {
    _heap = elements;
    for (int i = 0; i < _heap.size(); ++i) {
        addToMap(_heap[i], i);
    }
    int index = std::floor(_heap.size() / 2) - 1;
    for (int i = index; i >= 0; --i) {
        bubbleDown(i);
    }
}

template <typename T>
PQueue<T>::~PQueue() {}

template <typename T>
int PQueue<T>::size() const {
    return _heap.size();
}

template <typename T>
bool PQueue<T>::isEmpty() const {
    return _heap.empty();
}

template <typename T>
bool PQueue<T>::contains(const T& elem) const {
    return _map.find(elem) != _map.end();
}

template <typename T>
bool PQueue<T>::isMinHeap() const {
    int n = _heap.size();
    for (int i = 0; i <= (n - 2) / 2; ++i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && _heap[i] > _heap[left]) {
            return false;
        }

        if (right < n && _heap[i] > _heap[right]) {
            return false;
        }
    }
    return true;
}

template <typename T>
void PQueue<T>::add(const T& elem) {
    _heap.push_back(elem);
    int index = _heap.size() - 1;
    addToMap(elem, index);
    bubbleUp(index);
}

template <typename T>
T PQueue<T>::peek() const {
    if(isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return _heap[0];
}

template <typename T>
T PQueue<T>::poll() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    int lastIndex = _heap.size() - 1;
    T removed = _heap[0];
    swapInMap(_heap[0], 0, _heap[lastIndex], lastIndex);
    swap(0, _heap.size() - 1);
    removeFromMap(_heap.back(), _heap.size() - 1);
    _heap.pop_back();
    if (!isEmpty()) {
        bubbleDown(0);
    }
    return removed;
}

template <typename T>
bool PQueue<T>::remove(const T& elem) {
    auto it = _map.find(elem);
    if (it == _map.end()) {
        return false;
    }
    int firstIndex = *(it->second.begin());
    int lastIndex = _heap.size() - 1;
    swapInMap(_heap[firstIndex], firstIndex, _heap[lastIndex], lastIndex);
    swap(firstIndex, lastIndex);
    removeFromMap(_heap.back(), _heap.size() - 1);
    _heap.pop_back();
    if (!isEmpty()) {
        if (firstIndex < _heap.size()) {
            bubbleDown(firstIndex);
            bubbleUp(firstIndex);
        }
    }
    return true;
}

template <typename T>
T PQueue<T>::removeAt(int i) {
    if (i == 0) {
        return poll();
    }
    if (i >= _heap.size()) {
        throw std::out_of_range("Out of bounds");
    }
    int lastIndex = _heap.size() - 1;
    T removed = _heap[i];
    swapInMap(_heap[i], i, _heap[lastIndex], lastIndex);
    swap(i, _heap.size() - 1);
    removeFromMap(_heap.back(), _heap.size() - 1);
    _heap.pop_back();
    if (i < _heap.size()) {
            bubbleDown(i);
            bubbleUp(i);
    }
    return removed;
}

template <typename T>
void PQueue<T>::clear() {
    _heap.clear();
    _map.clear();
}

template <typename T>
std::string PQueue<T>::toString() const {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < _heap.size(); ++i) {
        oss << _heap[i];
        if (i < _heap.size() - 1) {
            oss << ", ";
        }
    }
    oss << "]";
    return oss.str();
}

template <typename T>
void PQueue<T>::printMap() const {
    for (const auto& pair : _map) {
        std::cout << pair.first << ": { ";
        for (const auto& index : pair.second) {
            std::cout << index << " ";
        }
        std::cout << "}" << std::endl;
    }
}

/* Private Methods */

template <typename T>
bool PQueue<T>::less(int i, int j) const {
    return _heap[i] < _heap[j];
}

template <typename T>
void PQueue<T>::swap(int i, int j) {
    T temp = _heap[i];
    _heap[i] = _heap[j];
    _heap[j] = temp;
}

template <typename T>
void PQueue<T>::addToMap(const T& key, int value) {
    _map[key].emplace(value);
}

template <typename T>
void PQueue<T>::removeFromMap(const T& key, int value) {
    _map[key].erase(value);
    if (_map[key].empty()) {
        _map.erase(key);
    }
}

template <typename T>
int PQueue<T>::getFromMap(const T& key) const {
    return _map.at(key);
}

template <typename T>
void PQueue<T>::swapInMap(const T& value1, int index1, const T& value2, int index2) {
    _map[value1].erase(index1);
    _map[value1].emplace(index2);
    _map[value2].erase(index2);
    _map[value2].emplace(index1);
}

template <typename T>
void PQueue<T>::bubbleUp(int k) {
    while (k > 0) {
        int parentIndex = (k - 1) / 2;
        if (_heap[k] < _heap[parentIndex]) {
            swapInMap(_heap[k], k, _heap[parentIndex], parentIndex);
            swap(k, parentIndex);
            k = parentIndex;
        } else {
            break;
        }
    }
}

template <typename T>
void PQueue<T>::bubbleDown(int k) {
    int size = _heap.size();
    while (k < size) {
        int leftChildIndex = 2 * k + 1;
        int rightChildIndex = 2 * k + 2;
        int minIndex = k;

        if (leftChildIndex < size && less(leftChildIndex, minIndex)) {
            minIndex = leftChildIndex;
        }
        if (rightChildIndex < size && less(rightChildIndex, minIndex)) {
            minIndex = rightChildIndex;
        }
        if (minIndex != k) {
            swapInMap(_heap[k], k, _heap[minIndex], minIndex);
            swap(k, minIndex);
            k = minIndex;
        } else {
            break;
        }
    }
}

#endif /* PQueue_hpp */
