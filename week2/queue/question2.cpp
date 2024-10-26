#include <bits/stdc++.h>

using namespace std;

int sumOfMaxSubarray(vector<int>& nums, int k) {
    // STUDENT ANSWER
    int n = nums.size();
    if (k > n || k < 0) return 0;
    
    deque<int> idx;
    int sum = 0;

    // Traversing the array
    for (int i = 0; i < n; ++i) {
        // Remove elements from the front of the deque if they are out of the window
        if (!idx.empty() && idx.front() < i - k + 1) {
            idx.pop_front();
        }

        // Remove elements from the back of the deque if they are less than the current element
        while (!idx.empty() && nums[idx.back()] <= nums[i]) {
            idx.pop_back();
        }

        // Add the current element's index to the deque
        idx.push_back(i);

        // Once we have a valid window, add the maximum element (idx.front()) to the sum
        if (i >= k - 1) {
            sum += nums[idx.front()];
        }
    }
    return sum;
}

int main() {
    vector<int> nums {1, 2, 4, 3, 6};
    int k = 10;
    cout << sumOfMaxSubarray(nums, k);
    return 0;
}