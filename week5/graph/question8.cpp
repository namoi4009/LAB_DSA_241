#include <iostream>
#include <vector>
#include <list>

using namespace std;

class DirectedGraph 
{ 
	int V;
	vector<list<int>> adj;
public:
	DirectedGraph(int V)
	{
		this->V = V; 
		adj = vector<list<int>>(V, list<int>());
	}
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
	}

    void printAdj() {
        int n = this->adj.size();
        int m = this->adj[0].size();
        for (int i = 0; i < n; ++i) {
            cout << i << ": ";
            for (auto it : adj[i]) {
                cout << to_string(it) << " ";
            }
            cout << endl;
        }
    }

	bool isCyclic()
	{
	    // Student answer
	    vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i] && isCyclicUtil(adj, i, visited, recStack))
                return true;
        }

        return false;
	}
private:
    bool isCyclicUtil(vector<list<int>>& adj, int u, vector<bool>& visited, vector<bool>& recStack) {
        if (!visited[u]) {
            visited[u] = true;
            recStack[u] = true;
            for (int x : adj[u]) {
                if (!visited[x] && isCyclicUtil(adj, x, visited, recStack))
                    return true;
                else if (recStack[x])
                    return true;
            }
        }
        recStack[u] = false;
        return false;
    }
};

int main() {
    DirectedGraph g(8); 
    int edege[][2] = {{0,6}, {1,2}, {1,4}, {1,6}, {3,0}, {3,4}, {5,1}, {7,0}, {7,1}};

    for(int i = 0; i < 9; i++)
        g.addEdge(edege[i][0], edege[i][1]);

    return 0;
}