#include <iostream>
#include <vector>

using namespace std;

int longestSublist(vector<string>& words) {
    // STUDENT ANSWER
    if (words.empty()) return 0;
    int max = 1;
    int curr = 1;
    int len = words.size();

    for (int i = 1; i < len; i++) {
        if (words[i][0] == words[i - 1][0]) {
            curr++;
        } else {
            if (curr > max) max = curr;
            curr = 1;
        }
    }

    if (curr > max) max = curr;
    return max;
}

int main() {
    vector<string> words = {"Apple", "ant", "Anchor", "banana", "Ball", "bat"};
    cout << longestSublist(words);
    return 0;
}