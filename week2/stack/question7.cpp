#include <iostream>
#include <vector>

using namespace std;

vector<int> stock_span(const vector<int>& ns) {
    // STUDENT ANSWER
    vector<int> output;
    int n = ns.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = i - 1; j >= 0; j--)
            if (ns[j] < ns[i])
                count++;
            else break;
        output.push_back(count + 1);
        count = 0;
    }
    return output;
}

int main() {
    vector<int> sample = {100, 80, 60, 70, 60, 75, 85};
    vector<int> res = stock_span(sample);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}