#include <iostream>

using namespace std;

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
    int getItem(T item);
    void remove(T item);
    void clear();
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

// Your code here
template<class T>
int Heap<T>::getItem(T item) {
    // TODO: return the index of item in heap
    for (int i = 0; i < this->count; ++i) {
        if (this->elements[i] == item) {
            return i;
        }
    }
    return -1;
}

template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    int index = getItem(item);
    if (index == -1) {
        return;
    }
    this->elements[index] = this->elements[this->count - 1];
    this->count--;

    if (index < this->count) {
        int parentIndex = (index - 1) / 2;
        if (index > 0 && this->elements[index] > this->elements[parentIndex]) {
            reheapUp(index);
        } else {
            reheapDown(index);
        }
    }    
}

template<class T>
void Heap<T>::clear() {
    // TODO: delete all elements in heap
    //    then reallocate memory as initial state
    delete[] this->elements;

    this->capacity = 10;
    this->count = 0;
    this->elements = new T[this->capacity];    
}

int main() {
    Heap<int> maxHeap;
    int arr[] = {42,35,30,15,20,21,18,3,7,14};
    for (int i = 0; i < 10; i++)
        maxHeap.push(arr[i]);
    maxHeap.remove(42);
    maxHeap.remove(35);
    maxHeap.remove(30);
    maxHeap.printHeap();
    return 0;
}