#include <iostream>
using namespace std;
template <class T>
class Sorting
{
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }
    static void selectionSort(T *start, T *end);
};

template <class T>
void Sorting<T>::selectionSort(T *start, T *end) {
    int size = end - start;
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (start[j] < start[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(start[i], start[minIndex]);
        }
        printArray(start, end);
    }
}

int main() {
    int arr[] = {9, 2, 8, 1, 0, -2};
    Sorting<int>::selectionSort(&arr[0], &arr[6]);
    return 0;
}