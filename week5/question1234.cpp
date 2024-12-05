#include <iostream>

using namespace std;

template <class T>
class DGraph
{
public:
    class VertexNode; // Forward declaration
    class Edge;       // Forward declaration
protected:
    VertexNode *nodeList; // list of vertexNode of DGraph
    int countVertex;
    int countEdge;

public:
    DGraph()
    {
        this->nodeList = nullptr;
        this->countEdge = 0;
        this->countVertex = 0;
    }
    ~DGraph() {};
    VertexNode *getVertexNode(T vertex);
    void add(T vertex);

    void connect(T from, T to, float weight = 0);

    void removeVertex(T removeVertex);
    bool removeEdge(T from, T to);
    string shape();
    bool empty();
    void clear();
    void printGraph();

public:
    class VertexNode
    {
    private:
        T vertex;
        Edge *adList; // list of adjacent edge of this vertex
        VertexNode *next;

        friend class Edge;
        friend class DGraph;

    public:
        VertexNode(T vertex, Edge *adList = nullptr, VertexNode *next = nullptr)
        {
            this->vertex = vertex;
            this->adList = adList;
            this->next = next;
        }
        string toString();
        void addAdjacentEdge(Edge *newEdge);
        bool connectTo(VertexNode *toNode, float weight = 0);
        bool removeTo(VertexNode *toNode);
        Edge *getEdge(VertexNode *toNode);
    };

    class Edge
    {
    private:
        VertexNode *fromNode;
        VertexNode *toNode;
        float weight;
        Edge *next;

        friend class VertexNode;
        friend class DGraph;

    public:
        Edge(VertexNode *fromNode, VertexNode *toNode, float weight = 0.0, Edge *next = nullptr)
        {
            this->fromNode = fromNode;
            this->toNode = toNode;
            this->weight = weight;
            this->next = next;
        }
        string toString();
    };
};

// ===== Code Cau 1: Start =====
template<class T>
typename DGraph<T>::Edge* DGraph<T>::VertexNode::getEdge(VertexNode* toNode) {
    //TODO: Iterate through the adjacency list of this vertex
    //      checking if there exists an edge with this vertex as the starting vertex 
    //      and "toNode" as the ending vertex. 
    //      If not return nullptr, else return that edge.
    Edge* temp = this->adList;
    while(temp) {
        if (temp->toNode == toNode) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

template<class T>
void DGraph<T>::VertexNode::addAdjacentEdge(Edge* newEdge) {
    //TODO: add newEdge to adjacency list of this vertex.
    newEdge->next = this->adList;
    this->adList = newEdge;
}

template<class T>
bool DGraph<T>::VertexNode::connectTo(VertexNode* toNode, float weight) {
    //TODO: get edge from this node to "toNode".
    //TODO: If the edge is not existed, create a new Edge and add it to the adjacency list. 
    //      If the edge is existed, update its weight.
    //TODO: Return true if a new Edge is created; otherwise, return false.
    Edge* e = getEdge(toNode);
    if (!e) {
        e = new Edge(this, toNode, weight);
        addAdjacentEdge(e);
        return true;
    }

    e->weight = weight;
    return false; 
}

template<class T>
bool DGraph<T>::VertexNode::removeTo(VertexNode *toNode) {
    //TODO: remove the edge with "toNode" as the ending vertex from this node's adjacency list.
    //TODO: return true if success; otherwise, return false.
    Edge* delNode = getEdge(toNode);
    Edge* temp = this->adList;
    Edge* prev = nullptr;
    while (temp) {
        if (temp == delNode) {
            if (prev) prev->next = temp->next;
            delete delNode;
            return true;
        }
        prev = temp;
        temp = temp->next;
    }

    return false;
}
// ===== Code Cau 1: End =====

// ===== Code Cau 2: Start =====
template<class T>
typename DGraph<T>::VertexNode* DGraph<T>::getVertexNode(T vertex) {
    //TODO: Iterate through the Node list of the graph 
    //      check if any vertexNode contains vertex. 
    //      If such a vertexNode exists, return it; otherwise, return nullptr.
    VertexNode* temp = nodeList;
    while (temp) {
        if (temp->vertex == vertex) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

template<class T>
void DGraph<T>::add(T vertex) {
    //TODO: create a new vertexNode with vertex.
    //TODO: add new vertexNode to the end of Node list of the graph.
    //TODO: increase the countVertex.
    VertexNode* newNode = new VertexNode(vertex);
    countVertex++;

    if (nodeList) {
        VertexNode* temp = this->nodeList;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    } else {
        nodeList = newNode;
    }
}

template <class T>
void DGraph<T>::connect(T from, T to, float weight) {
    //TODO: get vertexNode with "from" and vertexNode with "to".
    //TODO: If either of the two vertexNode objects does not exist, 
    //      throw an exception: VertexNotFoundException("Vertex doesn't exist!").
    //TODO: connect "from" vertexNode to "to" vertexNode. 
    //      If a new edge is created, increase the countEdge.
    VertexNode* f = getVertexNode(from);
    VertexNode* t = getVertexNode(to);
    if (!(t && f)) {
        throw VertexNotFoundException("Vertex doesn't exist!");
    }
    if (f->connectTo(t, weight)) countEdge++;
}
// ===== Code Cau 2: End =====

// ===== Code Cau 3: Start =====
template <class T>
bool DGraph<T>::removeEdge(T from, T to) {
    //TODO: get vertexNode with "from" and vertexNode with "to".
    //TODO: If either of the two vertexNode objects does not exist, 
    //      throw an exception: VertexNotFoundException("Vertex doesn't exist!").
    //TODO: Delete the edge between the "from" vertexNode and the "to" vertexNode. (use removeTo method)
    //      If success return true and decrement the countEdge; otherwise, return false; 
    VertexNode* f = getVertexNode(from);
    VertexNode* t = getVertexNode(to);
    if (!(t && f)) {
        throw VertexNotFoundException("Vertex doesn't exist!");
    }
    if (f->removeTo(t)) {
        countEdge--;
        return true;
    }
    return false;
}

template <class T>
void DGraph<T>::removeVertex(T removeVertex) {
    //TODO: get vertexNode with "removeVertex"
    //TODO: If this vertexNode isn't existed,
    //      throw an exception: VertexNotFoundException("Vertex doesn't exist!").
    //TODO: Iterate through all the vertexNode in the graph's Node list. For each vertexNode:
    //      - Check for an edge from the current vertex to the "removeVertex". 
    //      If such an edge exists, delete it (use removeTo method) and decrement the countEdge. 
    //      - Check for an edge from the "removeVertex" to the current vertex. 
    //      If such an edge exists, delete it (use removeTo method) and decrement the countEdge.
    //TODO: Delete the vertexNode containing removeVertex from the Node list of the graph
    //      Decrement the countVertex.
    VertexNode* delVertex = getVertexNode(removeVertex);
    if (!delVertex) throw VertexNotFoundException("Vertex doesn't exist!");
    
    VertexNode* temp = this->nodeList;
    while (temp) {
        if (temp->removeTo(delVertex)) countEdge--;
        if (delVertex->removeTo(temp)) countEdge--;
        temp = temp->next;
    }

    temp = this->nodeList;
    VertexNode* prev = nullptr;
    while (temp) {
        if (temp->vertex == delVertex->vertex) {
            if (prev) prev->next = delVertex->next;
            delete delVertex;
            countVertex--;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}
// ===== Code Cau 3: End =====

// ==== Code Cau 4: Start =====
template<class T>
string DGraph<T>::shape() {
    //TODO: return the string with format: [Vertices: <numOfVertex>, Edges: <numOfEdge>]
    return "[Vertices: " +  to_string(this->countVertex) + ", Edges: " + to_string(this->countEdge) + "]";
}

template<class T>
bool DGraph<T>::empty() {
    //TODO: return if graph is empty (it doesn't have any vertex and edge)
    return countVertex == 0;
}

template<class T>
void DGraph<T>::clear() {
    //TODO: remove all edges and vertices of graph.
    while (this->nodeList != nullptr) {
        this->removeVertex(this->nodeList->vertex);
    }
    countEdge = 0;
    countVertex = 0;
}
// ==== Code Cau 4: End =====

int main() {

    return 0;
}