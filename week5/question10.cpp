#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int Dijkstra(int** graph, int src, int dst) {
	// TODO: return the length of shortest path from src to dst.


}

int main() {
    int n = 6;
    int init[6][6] = {
        {0, 10, 20, 0, 0, 0},
        {10, 0, 0, 50, 10, 0},
        {20, 0, 0, 20, 33, 0},
        {0, 50, 20, 0, 20, 2},
        {0, 10, 33, 20, 0, 1},
        {0, 0, 0, 2, 1, 0} };

    int** graph = new int*[n];
    for (int i = 0; i < n; ++i) {
        graph[i] = init[i];
    }

    cout << Dijkstra(graph, 0, 1);

    return 0;
}