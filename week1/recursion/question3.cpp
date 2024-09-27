#include <iostream>

using namespace std;

int findMax(int* arr, int length) {
    if (length == 1) {
        return arr[0];
    } else {
        return max(arr[length - 1], findMax(arr, length - 1));
    }
}

int main() {
    int a[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};
    cout << findMax(a, 10);
    return 0;
}