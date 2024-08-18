#ifndef UnionFind_hpp
#define UnionFind_hpp

#include <stdio.h>
#include <unordered_map>

template <typename T>
class UnionFind {
private:
    std::unordered_map<T, T> _parent;
    std::unordered_map<T, int> _rank;
    
public:
    T find_set(T x) {
        if (_parent[x] != x) {
            _parent[x] = find_set(_parent[x]);
        }
        return _parent[x];
    }
    
    void union_sets(T x, T y) {
        T rootX = find_set(x);
        T rootY = find_set(y);
        
        if (rootX != rootY) {
            if (_rank[rootX] > _rank[rootY]) {
                _parent[rootY] = rootX;
            } else if (_rank[rootX] < _rank[rootY]) {
                _parent[rootX] = rootY;
            } else {
                _parent[rootY] = rootX;
                _rank[rootX]++;
            }
        }
    }
    
    void make_set(T x) {
        _parent[x] = x;
        _rank[x] = 0;
    }
    
    bool connected(T x, T y) {
        return find_set(x) == find_set(y);
    }
};

#endif /* UnionFind_hpp */
