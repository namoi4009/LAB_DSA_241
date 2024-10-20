#include <bits/stdc++.h>

using namespace std;

int sumOfMaxSubarray(vector<int>& nums, int k) {
    // STUDENT ANSWER
    int n = nums.size();
    if (k > n || k <= 0) return 0;
    int sum = 0;
    for (int i = 0; i <= n - k; i++) {
        int max = nums[i];
        for (int j = i; j < i + k; j++)
            if (nums[j] > max) max = nums[j];
        sum += max;
    }
    return sum;
}

int main() {
    vector<int> nums {1, 2, 4, 3, 6};
    int k = 10;
    cout << sumOfMaxSubarray(nums, k);
    return 0;
}