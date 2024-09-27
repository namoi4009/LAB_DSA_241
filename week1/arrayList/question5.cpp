#include <bits/stdc++.h>

using namespace std;

bool consecutiveOnes(vector<int>& nums) {
    // STUDENT ANSWER
    if (nums.empty()) return true;
    int s = -1, e = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            if (s == -1) {
                s = i;
            }
            e = i;
        }
    }
    if (s == -1) return false;
    for (int i = s; i <= e; i++) {
        if (nums[i] != 1) return false;
    }
    return true;
}

int main() {
    vector<int> nums {0, 1, 1, 0, 9, 8, 1, 1, 6, 1};
    cout << consecutiveOnes(nums);
    return 0;
}