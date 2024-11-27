#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template<class T>
class Heap {
protected:
    T* elements;
    int capacity;
    int count;
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[]elements;
    }
    void push(T item);
    
    bool isEmpty();
    bool contains(T item);
    T peek();
    bool pop();
    int size();
    
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};

//Your code goes here

// Question 1
template<class T>
int Heap<T>::size(){
    return this->count;
}

template<class T>
bool Heap<T>::isEmpty(){
    return this->count == 0;
}

template<class T>
T Heap<T>::peek(){
    if (this->count == 0) throw -1;
    return this->elements[0];
}

template<class T>
bool Heap<T>::contains(T item){
    for (int i = 0; i < this->count; ++i) {
        if (this->elements[i] == item)
            return true;
    }
    return false;
}

template<class T>
bool Heap<T>::pop(){
    if (this->count == 0) return false;

    this->elements[0] = this->elements[this->count - 1];
    this->count--;
    reheapDown(0);
    return true;
}

// Question 2
template<class T>
void Heap<T>::push(T item){
    ensureCapacity(this->count + 1);
    this->elements[this->count] = item;
    this->count++;
    reheapUp(this->count - 1);
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    if (minCapacity > this->capacity) {
        int newCapacity = this->capacity * 2;
        if (newCapacity < minCapacity)
            newCapacity = minCapacity;

        T* newElements = new T[newCapacity];
        for (int i = 0; i < this->count; ++i) {
            newElements[i] = this->elements[i];
        }
        delete[] this->elements;
        this->elements = newElements;
        this->capacity = newCapacity;
    }
}

template<class T>
void Heap<T>::reheapUp(int position){
    if (position == 0)
        return;

    int parent = (position - 1) / 2;
    if (this->elements[position] > this->elements[parent]) {
        T temp = this->elements[position];
        this->elements[position] = this->elements[parent];
        this->elements[parent] = temp;
        reheapUp(parent);
    }
}

int main() {
    Heap<int> maxHeap;
    for (int i=0;i<10;i++){
        maxHeap.push(i);
    }
    cout << maxHeap.size();

    return 0;
}