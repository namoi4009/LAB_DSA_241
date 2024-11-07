#include <iostream>
#include <algorithm>

using namespace std;

int getIndex(int arr[], int n, int e) {
    if (n == 0) return -1;
    for (int i = 0; i < n; i++) {
        if (e == arr[i]) return i;
    }
    return -1;
}

void sortByFrequency(int arr[], int n){
    // count frequency
    int e[n], f[n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        int index = getIndex(e, count, arr[i]);
        if (index == -1) {
            e[count] = arr[i];
            f[count++] = 1;
        } else f[index]++;
    }

    // sort the "e" array
    for (int i = 1; i < count; i++) {
        int keyf = f[i];
        int keye = e[i];
        int j = i - 1;
        while (j >= 0 && f[j] < keyf) {
            f[j + 1] = f[j];
            e[j + 1] = e[j];
            j--;
        }
        f[j + 1] = keyf;
        e[j + 1] = keye;
    }

    // pour the value from e[] to arr[] based on f[]
    int it = 0;
    for (int i = 0; i < count; i++) {
        int time = f[i];
        while (time > 0) {
            arr[it++] = e[i];
            time--;
        }
    }
}

int main() {
    int arr[] = {-5,3,8,1,-9,-9};
    sortByFrequency(arr, 6);
    return 0;
}