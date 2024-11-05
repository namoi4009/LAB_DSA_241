#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;
template <class T>
class Sorting
{
private:
    static T *Partition(T *start, T *end)
    {
        // TODO: return the pointer which points to the pivot after rearrange the array.
        T pivot = *start;
        T *i = start;
        T *j = end;
        do {
            do i++; while (*i < pivot);
            do j--; while (*j > pivot);
            if (i < j) swap(i, j);
        } while (i < j);
        swap(start, j);
        return j;
    }

public:
    static void QuickSort(T *start, T *end)
    {
        // TODO
        // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.
        if (start < end)
        {
            T *pivot = Partition(start, end);
            cout << (pivot - start) << " ";
            QuickSort(start, pivot);
            QuickSort(pivot + 1, end);
        }
    }
};

int main()
{
    int array[] = {3, 5, 7, 10, 12, 14, 15, 13, 1, 2, 9, 6, 4, 8, 11, 16, 17, 18, 20, 19};
    cout << "Index of pivots: ";
    Sorting<int>::QuickSort(&array[0], &array[20]);
    cout << "\n";
    cout << "Array after sorting: ";
    for (int i : array)
        cout << i << " ";
    return 0;
}