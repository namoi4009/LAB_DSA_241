#include <bits/stdc++.h>

using namespace std;

int pairMatching(vector<int>& nums, int target) {
    unordered_map<int, int> numCount;
    int pairCount = 0;

    for (int num : nums) {
        numCount[num]++;
    }

    for (int num : nums) {
        int complement = target - num;
        if (numCount[num] > 0 && numCount[complement] > 0) {
            if (num == complement) {
                pairCount += numCount[num] / 2;
                numCount[num] = 0;
            } else {
                int pairsFormed = min(numCount[num], numCount[complement]);
                pairCount += pairsFormed;
                numCount[num] = 0;
                numCount[complement] = 0;
            }
        }
    }

    return pairCount;
}

int main() {
    
    return 0;
}