#include <iostream>
#include <vector>

using namespace std;

int equalSumIndex(vector<int>& nums) {
    // STUDENT ANSWER
    if (nums.size() == 0 || nums.size() == 2) return -1;
    if (nums.size() == 1) return 0;

    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }

    int left = 0;
    for (int i = 0; i < nums.size(); i++) {
        int right = sum - left - nums[i];
        if (left == right) return i;
        left += nums[i];
    }
    return -1;
}

int main() {
    vector<int> nums {3, 5, 2, 7, 6, 4};
    cout << equalSumIndex(nums);
    return 0;
}