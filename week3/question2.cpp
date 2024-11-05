#include <iostream>
using namespace std;
template <class T>
class Sorting {
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start + 1;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }
    
    static void merge(T* left, T* middle, T* right){
        /*TODO*/
        int n1 = middle - left + 1;
        int n2 = right - middle;

        // Create temporary arrays
        T* L = new T[n1];
        T* R = new T[n2];

        // Copy data to temporary arrays L[] and R[]
        for (int i = 0; i < n1; i++)
            L[i] = left[i];

        for (int j = 0; j < n2; j++)
            R[j] = middle[1 + j];
        // Merge the temporary arrays back into left[] to right[]
        int i = 0;
        int j = 0;
        int k = 0;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                left[k] = L[i];
                i++;
            } else {
                left[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of L[], if any
        while (i < n1) {
            left[k] = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of R[], if any
        while (j < n2) {
            left[k] = R[j];
            j++;
            k++;
        }

        // Deallocate memory
        delete[] L;
        delete[] R;
        Sorting::printArray(left, right);
    }
    static void mergeSort(T* start, T* end) {
        /*TODO*/
        if (start < end) {
            T* middle = start + (end - start) / 2;

            mergeSort(start, middle);
            mergeSort(middle + 1, end);

            merge(start, middle, end);
        }
    }
};

int main() {
    int arr[] = {0,2,4,3,1,4};
    Sorting<int>::mergeSort(&arr[0], &arr[5]);
    return 0;
}