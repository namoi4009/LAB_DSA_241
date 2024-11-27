#include <iostream>

using namespace std;

void reheapDown(int maxHeap[], int numberOfElements, int index) {
    int current = index;
    int value = maxHeap[current];

    while (current * 2 + 1 < numberOfElements) {
        int leftChild = current * 2 + 1;
        int rightChild = current * 2 + 2;

        int maxChild = leftChild;
        if (rightChild < numberOfElements && maxHeap[rightChild] > maxHeap[leftChild]) {
            maxChild = rightChild;
        }

        if (maxHeap[maxChild] > value) {
            maxHeap[current] = maxHeap[maxChild];
            current = maxChild;
        } else {
            break;
        }
    }
    maxHeap[current] = value;
}

void reheapUp(int maxHeap[], int numberOfElements, int index) {
    int current = index;
    int value = maxHeap[current];

    while (current > 0) {
        int parent = (current - 1) / 2;

        if (value > maxHeap[parent]) {
            maxHeap[current] = maxHeap[parent];
            current = parent;
        } else {
            break;
        }
    }
    maxHeap[current] = value;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    reheapDown(arr,size,0);
    cout << "[ ";
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    cout << "]";

    return 0;
}