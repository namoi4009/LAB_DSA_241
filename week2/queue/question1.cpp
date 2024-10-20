#include <bits/stdc++.h>
#include "DLinkedList.h"

template<class T>
class Queue {
protected:
    DLinkedList<T> list;
public:
    Queue() {}
    void push(T item) {
        // TODO: Push new element into the end of the queue
        list.add(item);
    }

    T pop() {
        // TODO: Remove an element in the head of the queue
        return list.removeAt(0);
    }

    T top() {
        // TODO: Get value of the element in the head of the queue
        return list.get(0);
    }

    bool empty() {
        // TODO: Determine if the queue is empty
        return list.empty();
    }

    int size() {
        // TODO: Get the size of the queue
        return list.size();
    }

    void clear() {
        // TODO: Clear all elements of the queue
        list.clear();
    }
};

using namespace std;

int main() {
    Queue<int> queue;
    assert(queue.empty());
    assert(queue.size() == 0);
    return 0;
}