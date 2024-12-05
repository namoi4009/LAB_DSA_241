#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Adjacency
{
private:
	list<int> adjList;
	int size;
public:
	Adjacency() {}
	Adjacency(int V) {}
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

class Graph {

    int V;
    Adjacency* adj;

public:
    Graph(int V){
        this->V = V;
        adj = new Adjacency[V];
    }
    void addEdge(int v, int w){
        adj[v].push(w);
    }

	void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
    
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
};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();
    return 0;
}