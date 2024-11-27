#include <bits/stdc++.h>

using namespace std;

int leastAfter(vector<int>& nums, int k) {
    // STUDENT ANSWER
    priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());

    for (int i = 0; i < k; ++i) {
        int smallest = minHeap.top();
        minHeap.pop();
        smallest *= 2;
        minHeap.push(smallest);
    }

    return minHeap.top();
}

int main() {
    vector<int> nums {2, 3, 5, 7};
    int k = 3;
    cout << leastAfter(nums, k);
    return 0;
}