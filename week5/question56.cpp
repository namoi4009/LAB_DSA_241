#include <iostream>
#include <list>
using namespace std;

class Adjacency
{
private:
    list<int> adjList;
    int size;

public:
    Adjacency() { size = 0; }
    Adjacency(int V) { size = V; }
    void push(int data)
    {
        adjList.push_back(data);
        size++;
    }
    void print()
    {
        for (auto const &i : adjList)
            cout << " -> " << i;
    }
    void printArray()
    {
        for (auto const &i : adjList)
            cout << i << " ";
    }
    int getSize() { return adjList.size(); }
    int getElement(int idx)
    {
        auto it = adjList.begin();
        advance(it, idx);
        return *it;
    }
};

class Graph
{
private:
	int V;
	Adjacency *adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new Adjacency[V];
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push(w);
		adj[w].push(v);
	}
	
    void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
	
	Adjacency *BFS(int v) // Code Cau 5
    {
        // v is a vertex we start BFS
        Adjacency* res = new Adjacency(this->V);
        bool* visited = new bool[this->V]{false};

        list<int> queue;

        visited[v] = true;
        queue.push_back(v);
        res->push(v);

        while (!queue.empty()) {
            int current = queue.front();
            queue.pop_front();

            for (int i = 0; i < adj[current].getSize(); ++i) {
                int neighbor = adj[current].getElement(i);
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.push_back(neighbor);
                    res->push(neighbor);
                }
            }
        }
        delete[] visited;
        return res;
	}

    // ===== Code Cau 6: Start =====
    void helpDFS(int v, bool* visited, Adjacency* res, int& size) {
        if (size == V) 
            return;
        if (!visited[v]) {
            visited[v] = true;
            size++;
            res->push(v);
        }
        for (int i = 0; i < adj[v].getSize(); ++i) {
            int a = adj[v].getElement(i);
            if (!visited[a]) helpDFS(a, visited, res, size);
        }
    }

    Adjacency *DFS(int v) // Code Cau 6
    {
        // v is a vertex we start DFS
        Adjacency* res = new Adjacency();
        bool* visited = new bool[this->V]{false};
        int size = 0;
        helpDFS(v, visited, res, size);
        return res;
    }
    // ===== Code Cau 6: End =====

    // ===== Code Cau 9: Start ====
    void helpTop(int v, Adjacency* adj, list<bool>& visited, list<int>& stack) {
        auto item = visited.begin(); advance(item, v);
        *item = true; // set the node as "visited"
        for (int i = 0; i < adj[v].getSize(); ++i) {
            auto vertex = adj[v].getElement(i);
            item = visited.begin(); advance(item, vertex);
            if (!*item) 
                helpTop(vertex, adj, visited, stack);
        }
        stack.push_front(v);
    }

    void topologicalSort(){
        //TODO
        list<int> stack;
        list<bool> visited(this->V, false);

        for (int i = 0; i < this->V; ++i) {
            auto item = visited.begin(); advance(item, i);
            if (!*item) 
                helpTop(i, adj, visited, stack);
        }

        for (auto it : stack) {
            cout << it << " ";
        }
    }
    // ===== Code Cau 9: End =====
};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    // g.topologicalSort();
    g.printGraph();
    return 0;
}