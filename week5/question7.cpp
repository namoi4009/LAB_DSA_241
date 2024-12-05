#include <bits/stdc++.h>

using namespace std;

int numberOfFriendGroups(vector<vector<int>>& friends) {
    // STUDENT ANSWER
    int n = friends.size();
    if (!n) return 0;
    vector<bool> visited(n, false);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            res++;
            queue<int> q;
            visited[i] = true;
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : friends[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    return res;
}

int main() {
    vector<vector<int>> graph {
        {1},
        {0, 2},
        {1},
        {4},
        {3},
        {}
    };
    cout << numberOfFriendGroups(graph);
    return 0;
}