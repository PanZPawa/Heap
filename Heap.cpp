#pragma once
#include "Heap.h"
template <class T, class cmp, class Container>
int Heap<T, cmp, Container>::size() {
    return Size;
}
template <class T, class cmp, class Container>
void Heap<T, cmp, Container>::shiftDown(int n, int f) {
    int m = f;
    int left = f << 1;
    int right = f << 1 | 1;
    if (left <= n && compare(container[left], container[f])) {
        f = left;
    }
    if (right <= n && compare(container[right], container[f])) {
        f = right;
    }
    if (f != m) {
        swap(container[f], container[m]);
        shiftDown(n, f);
    }
}
template <class T, class cmp, class Container >
void Heap<T, cmp, Container>::build() {
    for (int i = Size / 2; i > 0; i--) shiftDown(Size, i);
}
template <class T, class cmp, class Container>
void Heap<T, cmp, Container>::push(T value) {
    Size++;
    if (Size >= container.size()) container.push_back(0);
    container[Size] = value;
    shiftUp();
}
template <class T, class cmp, class Container>
T& Heap<T, cmp, Container>::top() {
    if (Size >= 1)
        return container[1];
    else {
        // cout << "堆空" << endl;
        exit(1);
    }
}
template <class T, class cmp, class Container>
void Heap<T, cmp, Container>::pop() {
    if (Size >= 1) {
        container[1] = container[Size];
        Size--;
        shiftDown(Size, 1);
    }
    else {
        // cout << "不能弹出一个空堆" << endl;
        exit(1);
    }
}

template <class T, class cmp, class Container>
void Heap<T, cmp, Container>::shiftUp() {
    int f = Size;
    while (f / 2 > 0) {
        if (compare(container[f], container[f / 2])) {
            pzp::swap(container[f], container[f / 2]);
            f /= 2;
        }
        else {
            return;
        }
    }
}
