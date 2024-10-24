#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> adj;
    
    adj.push(start);
    visited[start] = true;

    while (!adj.empty()) {
        int node = adj.front();
        adj.pop();

        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                adj.push(neighbor);
            }
        }
    }
}

int main() {
    int init_graph[10][10] = {  {0, 1, 1, 0, 1, 0, 1, 0, 1, 0},
				                {0, 0, 1, 1, 0, 0, 0, 1, 0, 0},
				                {0, 1, 0, 0, 0, 1, 1, 0, 1, 1},
				                {1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
				                {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
				                {1, 0, 1, 0, 1, 0, 0, 0, 1, 0},
				                {0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
				                {1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
                                {0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
                                {1, 0, 1, 0, 1, 0, 0, 0, 1, 0}  };
	int n = 10;
	vector<vector<int>> graph(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (init_graph[i][j]) graph[i].push_back(j);
		}
	}

	bfs(graph, 0);
    return 0;
}