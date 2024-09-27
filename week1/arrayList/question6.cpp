#include <iostream>
#include <algorithm>

using namespace std;

int buyCar(int* nums, int length, int k) {
    sort(nums, nums + length);
    int spend = 0, count = 0;
    for (int i = 0; i < length; i++) {
        if (spend + nums[i] <= k) {
            spend += nums[i];
            count++;
        } else {
            break;
        }
    }
    return count;
}

int main() {
    int nums[] = {90, 30, 40, 90, 20};
    int length = sizeof(nums)/sizeof(nums[0]);
    cout << buyCar(nums, length, 90) << "\n";

    return 0;
}