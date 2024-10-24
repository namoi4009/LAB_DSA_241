#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool check(vector<vector<int>> graph, int start, vector<int>& color) {
    queue<int> adj;
    adj.push(start);
    color[start] = 0;

    while (!adj.empty()) {
        int node = adj.front();
        adj.pop();
        for (int neighbor : graph[node]) {
            if (color[neighbor] == -1) { // node has been not color yet
                color[neighbor] = 1 - color[node];
                adj.push(neighbor);
            } else if (color[neighbor] == color[node]) // node already has color
                return false;
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>> graph) {
    int n = graph.size();
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!check(graph, i, color))
                return false;
        }
    }

    return true;
}

int main() {
    int G[6][6] = { {0, 1, 0, 0, 0, 1},
                    {1, 0, 1, 0, 0, 0},
                    {0, 1, 0, 1, 0, 0},
                    {0, 0, 1, 0, 1, 0},
                    {0, 0, 0, 1, 0, 1},
                    {1, 0, 0, 0, 1, 0} };
    int n = 6;

    vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (G[i][j]) graph[i].push_back(j);
            }
        }

    isBipartite(graph) ? cout << "Yes" : cout << "No";
    return 0;
}