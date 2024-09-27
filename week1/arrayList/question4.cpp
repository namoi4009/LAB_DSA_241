#include <iostream>
#include <vector>

using namespace std;

vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations) {
    // STUDENT ANSWER
    vector<int> newNums(nums);
    int len = operations.size();
    for (int i = 0; i < len; i++) {
        for (int j = operations[i][0]; j <= operations[i][1]; j++) {
            newNums[j] += operations[i][2];
        }
    }
    return newNums;
}

void printVector(vector<int> a) {
    cout << "[" << a[0];
    for (int i = 1; i < a.size(); i++) {
        cout << ", " << a[i];
    }
    cout << "]";
}

int main() {
    vector<int> nums {13, 0, 6, 9, 14, 16};
    vector<vector<int>> operations {{5, 5, 16}, {3, 4, 0}, {0, 2, 8}};
    printVector(updateArrayPerRange(nums, operations));
    return 0;
}