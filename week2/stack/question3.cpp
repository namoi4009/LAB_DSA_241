#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreater(vector<int>& arr){
    vector<int> res;
    bool found = false;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                found = true;
                res.push_back(arr[j]);
                break;
            }
        }
        if (!found) {
            res.push_back(-1);
        } else found = false;
    }
    res.push_back(-1);
    return res;
}

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    vector<int> greaterNums = nextGreater(nums);
    for (int i : greaterNums)
        cout << i << ' ';
    cout << '\n';

    return 0;
}