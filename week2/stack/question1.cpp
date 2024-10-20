#include <iostream>
#include <cassert>
#include "DLinkedList.h"

using namespace std;

template<class T>
class Stack {
protected:
    DLinkedList<T> list;
public:
    Stack() {}
    void push(T item) {
        // TODO: Push new element into the top of the stack
        list.add(item);
    }

    T pop() {
        // TODO: Remove an element on top of the stack
        return list.removeAt(list.size() - 1);
    }

    T top() {
        // TODO: Get value of the element on top of the stack
        return list.get(list.size() - 1);
    }

    bool empty() {
        // TODO: Determine if the stack is empty
        return list.size() == 0;
    }

    int size() {
        // TODO: Get the size of the stack
        return list.size();
    }

    void clear() {
        // TODO: Clear all elements of the stack
        list.clear();
    }
};

int main() {
    Stack<int> stack;

    int item[] = { 3, 1, 4, 5, 2, 8, 10, 12 };
    for (int idx = 0; idx < 8; idx++) stack.push(item[idx]);
        
    assert(stack.top() == 12);
        
    stack.pop();
    stack.pop();
        
    cout << stack.top();

    return 0;
}