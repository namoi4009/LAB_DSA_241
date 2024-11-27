#include<iostream>
#include<string>
using namespace std;

template<class K, class V>
class BinaryTree
{
public:
    class Node;

private:
    Node *root;

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    class Node
    {
    private:
        K key;
        V value;
        Node *pLeft, *pRight;
        friend class BinaryTree<K, V>;

    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };

    void addNode(string posFromRoot, K key, V value)
    {
        if(posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }

        Node* walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l-1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if(posFromRoot[l-1] == 'L')
            walker->pLeft = new Node(key, value);
        if(posFromRoot[l-1] == 'R')
            walker->pRight = new Node(key, value);
    }

    // STUDENT ANSWER BEGIN
    // ===== Code Cau 1: Start =====
    int count(Node* root) {
        if (!root) return 0;
        if (root->pLeft && root->pRight) return 1 + count(root->pLeft) + count(root->pRight);
        return count(root->pLeft) + count(root->pRight);
    }

    int countTwoChildrenNode()
    {
        return count(this->root);
    }
    // ===== Code Cau 1: End ==============================

    // ===== Code Cau 2: Start =====
    int countHeight(Node* root) {
        if (!root) return 0;
        return 1 + max(countHeight(root->pLeft), countHeight(root->pRight));
    }

    int getHeight() {
        // TODO: return height of the binary tree.
        return countHeight(this->root);
    }

    void NLR(Node* root, string& res) {
        if (!root) return;
        
        res = res + to_string(root->value) + " ";
        NLR(root->pLeft, res);
        NLR(root->pRight, res);
    }

    string preOrder() {
        // TODO: return the sequence of values of nodes in pre-order.
        string res = "";
        NLR(this->root, res);
        return res;
    }

    void LNR(Node* root, string& res) {
        if (!root) return;
        
        LNR(root->pLeft, res);
        res = res + to_string(root->value) + " ";
        LNR(root->pRight, res);
    }

    string inOrder() {
        // TODO: return the sequence of values of nodes in in-order.
        string res = "";
        LNR(this->root, res);
        return res;
    }

    void LRN(Node* root, string& res) {
        if (!root) return;

        LRN(root->pLeft, res);
        LRN(root->pRight, res);
        res = res + to_string(root->value) + " ";
    }

    string postOrder() {
        // TODO: return the sequence of values of nodes in post-order.
        string res = "";
        LRN(this->root, res);
        return res;
    }
    // ===== Code Cau 2: End ==============================

    // ===== Code Cau 3: Start =====
    void count(Node* root, int& sum) {
        if (!root) return;
        if (root->pLeft) count(root->pLeft, sum);
        if (root->pRight) count(root->pRight, sum);
        if (!root->pLeft && !root->pRight) {
            sum += root->value;
            return;
        }
    }

    int sumOfLeafs(){
        //TODO
        int sum = 0;
        count(this->root, sum);
        return sum;
    }
    // ===== Code Cau 3: End ==============================

    // ===== Code Cau 5: Start =====
    void BFS()
    {
        if (this->root == nullptr) return;
        queue<Node*> q;
        q.push(this->root);
        
        while (!q.empty()) {
            Node* temp = q.front();
            cout << temp->value << " ";
            q.pop();
            
            if (temp->pLeft) q.push(temp->pLeft);
            if (temp->pRight) q.push(temp->pRight);
        }
    }
    // ===== Code Cau 5: End ==============================
    
    // STUDENT ANSWER END
};

int main() {

    return 0;
}