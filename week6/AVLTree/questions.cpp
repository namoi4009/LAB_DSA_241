#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template <class T>
class AVLTree
{
public:
    class Node;

private:
    Node *root;

protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL) return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }

public:
    AVLTree() : root(nullptr) {}
    ~AVLTree() {}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }

    // ===== Code Cau 1: Start =====
    Node *rotateRight(Node *root) {
        // TODO: Rotate and return new root after rotate
        Node* bNode = root->pLeft;
        root->pLeft = bNode->pRight;
        bNode->pRight = root;
        return bNode;
    }

    Node *rotateLeft(Node *root) {
        // TODO: Rotate and return new root after rotate
        Node* bNode = root->pRight;
        root->pRight = bNode->pLeft;
        bNode->pLeft = root;
        return bNode;
    }
    // ===== Code Cau 1: End =====

    // ===== Code Cau 2: Start =====
    int getBalance(Node *subroot) {
        if (!subroot) return 0;
        return getHeightRec(subroot->pLeft) - getHeightRec(subroot->pRight);
    }

    Node* helpAdd(Node* node, T value) {
        if (!node) 
            return new Node(value);
        if (value < node->data) 
            node->pLeft = helpAdd(node->pLeft, value);
        else if (value > node->data) 
            node->pRight = helpAdd(node->pRight, value);
        else 
            return node;

        // Block of code for question 3 and 4 (add existing value to the right sub tree)
        // if (!node) 
        //     return new Node(value);
        // if (value < node->data) 
        //     node->pLeft = helpAdd(node->pLeft, value);
        // else if (value > node->data) 
        //     node->pRight = helpAdd(node->pRight, value);
        // else 
        //     return node;

        int h = getBalance(node);
        if (node->pLeft) {
            if (h > 1 && value < node->pLeft->data) // R-rotate
                return rotateRight(node);
            if (h > 1 && value > node->pLeft->data) { // LR-rotate
                node->pLeft = rotateLeft(node->pLeft);
                return rotateRight(node);
            }
        }

        if (node->pRight) {
            if (h < -1 && value > node->pRight->data) // L-rotate
                return rotateLeft(node);
            if (h < -1 && value < node->pRight->data) { // RL-rotate
                node->pRight = rotateRight(node->pRight);
                return rotateLeft(node);
            }
        }
        return node; // no rotate require
    }

    void insert(const T &value) {
        this->root = helpAdd(this->root, value);
    }
    // ===== Code Cau 2: End =====

    // ===== Code Cau 5, 6: Start =====
    int getNodeHeight(Node* node) {
        return node ? getHeightRec(node) : 0;
    }

    int getBalanceFactor(Node* node) {
        if (!node) return 0;
        return getNodeHeight(node->pLeft) - getNodeHeight(node->pRight);
    }

    Node* findMin(Node* node) {
        if (!node) return nullptr;
        while (node->pLeft) {
            node = node->pLeft;
        }
        return node;
    }

    Node* findMax(Node* node) {
        if (!node) return nullptr;
        while (node->pRight) {
            node = node->pRight;
        }
        return node;
    }

    Node* rebalance(Node* node) {
        if (!node) return nullptr;

        int balance = getBalanceFactor(node);
        if (balance > 1) {
            int leftBalance = getBalanceFactor(node->pLeft);
            if (leftBalance >= 0) {
                return rotateRight(node);
            } else {
                node->pLeft = rotateLeft(node->pLeft);
                return rotateRight(node);
            }
        }
        
        if (balance < -1) {
            int rightBalance = getBalanceFactor(node->pRight);
            if (rightBalance <= 0) {
                return rotateLeft(node);
            } else {
                node->pRight = rotateRight(node->pRight);
                return rotateLeft(node);
            }
        }

        return node;
    }

    Node* helpDel(Node* node, const T& value) {
        if (!node) return nullptr;

        if (value < node->data) {
            node->pLeft = helpDel(node->pLeft, value);
        }
        else if (value > node->data) {
            node->pRight = helpDel(node->pRight, value);
        }
        else {
            if (!node->pLeft && !node->pRight) {
                delete node;
                return nullptr;
            }
            
            if (!node->pLeft || !node->pRight) {
                Node* child = node->pLeft ? node->pLeft : node->pRight;
                delete node;
                return child;
            }
            
            Node* pred = findMax(node->pLeft);
            node->data = pred->data;
            node->pLeft = helpDel(node->pLeft, pred->data);
        }
        
        return rebalance(node);
    }

    void remove(const T& value) {
        if (!root) return;
        root = helpDel(root, value);
    }
    // ===== Code Cau 5, 6: End =====

    // ===== Code Cau 7: Start =====
    void helpPrint(Node* node) {
        if (!node) return;

        helpPrint(node->pLeft);
        cout << node->data << " ";
        helpPrint(node->pRight);
    }

    void printInorder() {
        //TODO
        helpPrint(root);
    }

    bool helpSearch(Node* node, T value) {
        if (!node) return false;

        if (value < node->data) return helpSearch(node->pLeft, value);
        else if (value > node->data) return helpSearch(node->pRight, value);
        else return true;
    }

    bool search(const T &value) {
        //TODO
        return helpSearch(root, value);
    }
    // ===== Code Cau 7: End ======

    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};

int main() {
	AVLTree<int> avl;
    int arr[] = {10, 5, 15, 3};
    for (int i = 0; i < 4; i++)
        avl.insert(arr[i]);
    
    avl.remove(15);
    avl.printTreeStructure();

    return 0;
}
