#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template<class T>
class BinarySearchTree
{
public:
    class Node;
private:
    Node* root;
public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    // ===== Code Cau 1: Start =====
    void addNode(Node*& node, T value) {
        if (!node) node = new Node(value);
        else {
            if (value <= node->value) addNode(node->pLeft, value);
            else addNode(node->pRight, value);
        }
    }

    void add(T value){
        //TODO
        addNode(this->root, value);
    }

    Node* findMin(Node* node) {
        while (node->pLeft) node = node->pLeft;
        return node;
    }

    Node* helpDel(Node* node, T value) {
        if (!node) return nullptr;
        if (value < node->value) 
            node->pLeft = helpDel(node->pLeft, value);
        else if (value > node->value) 
            node->pRight = helpDel(node->pRight, value);
        else {
            if (!node->pLeft && !node->pRight) {
                delete node;
                node = nullptr;
            } else if (!node->pLeft) {
                Node* temp = node;
                node = node->pRight;
                delete temp;
            } else if (!node->pRight) {
                Node* temp = node;
                node = node->pLeft;
                delete temp;
            } else {
                Node* minOfRight = findMin(node->pRight);
                node->value = minOfRight->value;
                node->pRight = helpDel(node->pRight, minOfRight->value);
            }
        }
        return node;
    }

    void deleteNode(T value){
        //TODO
        this->root = helpDel(this->root, value);
    }
    // ===== Code Cau 1: End =====

    // ===== Code Cau 2: Start =====
    T getMin() {
        //TODO: return the minimum values of nodes in the tree.
        Node* min = root;
        while (min->pLeft) min = min->pLeft;
        return min->value;
    }

    T getMax() {
        //TODO: return the maximum values of nodes in the tree.
        Node* max = root;
        while (max->pRight) max = max->pRight;
        return max->value;
    }
    // ===== Code Cau 2: End =====

    // ===== Code Cau 3: Start =====
    bool find(T i) {
        // TODO: return true if value i is in the tree; otherwise, return false.
        Node* temp = this->root;
        while (temp) {
            if (i < temp->value) temp = temp->pLeft;
            else if (i > temp->value) temp = temp->pRight;
            else return true;
        }
        return false;
    }

    T helpSum(Node* node, T l, T r) {
        if (!node) return 0;

        T total = 0;
        if (node->value >= l && node->value <= r) total += node->value;
        if (node->value > l) total += helpSum(node->pLeft, l, r);
        if (node->value < r) total += helpSum(node->pRight, l, r);

        return total;
    }

    T sum(T l, T r) {
        // TODO: return the sum of all element in the tree has value in range [l,r].
        return helpSum(this->root, l, r);
    }
    // ===== Code Cau 3: End =====

    string inOrderRec(Node* root) {
        stringstream ss;
        if (root != nullptr) {
            ss << inOrderRec(root->pLeft);
            ss << root->value << " ";
            ss << inOrderRec(root->pRight);
        }
        return ss.str();
    }
    
    string inOrder(){
        return inOrderRec(this->root);
    }
    
    class Node
    {
    private:
        T value;
        Node* pLeft, * pRight;
        friend class BinarySearchTree<T>;
    public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
};

int main() {
    BinarySearchTree<int> bst;
    bst.add(9);
    bst.add(2);
    bst.add(10);
    bst.deleteNode(9);
    cout << bst.inOrder();
    return 0;
}