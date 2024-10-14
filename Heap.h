#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
template <class T>
struct Myless {
    bool operator()(const T& a, const T& b) {
        return a < b;
    }
};
template <class T>
struct Mygreater {
    bool operator()(const T& a, const T& b) {
        return a > b;
    }
};
namespace pzp {
    template<typename T>
    void swap(T& a, T& b) {
        T c = a;
        a = b;
        b = c;
    }
}
template <typename T = int, class cmp = Myless<T>, class Container = vector<T>>
class Heap {
public:

    Heap() {
        container.push_back(T());
    };
    Heap(vector<T> arr) {
        container.push_back(0);
        for (int i = 0; i < arr.size(); i++) container.push_back(arr[i]);
        Size = container.size() - 1;
        build();
    }
    void push(T value);
    void pop();
    T& top();
    int size();
    void build();
private:
    void shiftUp();
    void shiftDown(int n, int f);
    int Size = 0;
    Container container;
    cmp compare;
};
#include "Heap.cpp"