#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;
template <class T>
class Sorting {
private:
    static void printArray(T* start, T* end) {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << " ";
        cout << start[size - 1];
        cout << endl;
    }

    static void merge(T* start, T* middle, T* end) {
        // TODO
        int n1 = middle - start;
        int n2 = end - middle;
        T* left = new T[n1];
        T* right = new T[n2];
        for (int i = 0; i < n1; i++)
            left[i] = start[i];
        for (int j = 0; j < n2; j++)
            right[j] = middle[j];

        int i = 0, j = 0;
        T* k = start;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                *k = left[i++];
            } else {
                *k = right[j++];
            }
            k++;
        }

        while (i < n1) {
            *k = left[i++];
            k++;
        }
        while (j < n2) {
            *k = right[j++];
            k++;
        }

        delete []left;
        delete []right;
    }
public:
    static void InsertionSort(T* start, T* end) {
        // TODO
        int n = end - start;
        for (int i = 1; i < n; i++) {
            T key = start[i];
            int j = i - 1;
            
            while (j >= 0 && start[j] > key) {
                start[j + 1] = start[j];
                j--;
            }

            start[j + 1] = key;
        }
    }

    static void TimSort(T* start, T* end, int min_size) {
        // TODO
        // You must print out the array after using insertion sort and everytime calling method merge.
        int n = end - start;
        for (int i = 0; i < n; i += min_size) {
            T* run_start = start + i;
            T* run_end = (i + min_size < n) ? (start + i + min_size) : end;
            InsertionSort(run_start, run_end);
        }

        cout << "Insertion Sort: ";
        printArray(start, end);

        int countMerge = 1;
        for (int size = min_size; size < n; size *= 2) {
            for (int left = 0; left < n; left += 2 * size) {
                int mid = left + size;
                int right = left + (2 * size);

                T* left_ptr = start + left;
                T* mid_ptr = (mid < n) ? (start + mid) : end;
                T* right_ptr = (right < n) ? (start + right) : end;

                if (mid < n) merge(left_ptr, mid_ptr, right_ptr);
                cout << "Merge " << countMerge++ << ": ";
                printArray(start, end);
            }
        }
    }
};

int main() {
    int array[] = { 19, 20, 18, 17 ,12, 13, 14, 15, 1, 2, 9, 6, 4, 7, 11, 16, 10, 8, 5, 3 };
    int min_size = 4;
    Sorting<int>::TimSort(&array[0], &array[20], min_size);
    return 0;
}