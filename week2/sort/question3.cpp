#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;
template <class T>
class Sorting
{
private:
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size; i++)
            cout << start[i] << " ";
        cout << endl;
    }

public:
    // TODO: Write your code here
    static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total) {
        // TODO
        // The size of the array and the stride between elements in the same segment
        int size = end - start;

        for (int i = segment_idx + cur_segment_total; i < size; i += cur_segment_total) {
            T temp = start[i];
            int j = i;

            while (j >= segment_idx + cur_segment_total && start[j - cur_segment_total] > temp) {
                start[j] = start[j - cur_segment_total];
                j -= cur_segment_total;
            }

            start[j] = temp;
        }
    }

    static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases) {
        // TODO
        // Note: You must print out the array after sorting segments to check whether your algorithm is
        for (int phase = num_phases - 1; phase >= 0; --phase) {
            int cur_segment_total = num_segment_list[phase];
            
            for (int segment_idx = 0; segment_idx < cur_segment_total; ++segment_idx) {
                sortSegment(start, end, segment_idx, cur_segment_total);
            }

            cout << cur_segment_total << " segments: ";
            printArray(start, end);
        }
    }
};

int main() {
    int num_segment_list[] = {1, 3, 5};
    int num_phases = 3;
    int array[] = {10, 9, 8 , 7 , 6, 5, 4, 3, 2, 1};
    Sorting<int>::ShellSort(&array[0], &array[10], &num_segment_list[0], num_phases);
    
    return 0;
}