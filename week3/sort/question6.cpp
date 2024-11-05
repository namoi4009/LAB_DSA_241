#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string minDiffPairs(int* arr, int n){
    // STUDENT ANSWER
    if (n <= 1) return "";

    string res = "";
    sort(arr, arr + n);
    int minDiff = arr[1] - arr[0];

    // find minimum difference
    for (int i = 0; i < n - 1; i++) {
        int d = arr[i + 1] - arr[i];
        if (d < minDiff) minDiff = d;
    }

    bool first = true;
    for (int i = 0; i < n; i++) {
        if (arr[i + 1] - arr[i] == minDiff) {
            if (first) {
                res = res + "(" + to_string(arr[i]) + ", " + to_string(arr[i + 1]) + ")";
                first = false;
            } else {
                res = res + ", (" + to_string(arr[i]) + ", " + to_string(arr[i + 1]) + ")";
            }
        }
    }
    return res;
}

int main() {
    int arr[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};
    cout << minDiffPairs(arr, 10);
    return 0;
}