#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class BSTNode {
public: 
    int val; 
    BSTNode *left; 
    BSTNode *right; 
    BSTNode() {
        this->left = this->right = nullptr;
    } 
    BSTNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    } 
    BSTNode(int val, BSTNode*& left, BSTNode*& right) {
        this->val = val;
        this->left = left;
        this->right = right;
    } 
};

// Code Cau 4
vector<int> levelAlterTraverse(BSTNode* root) {
    // STUDENT ANSWER
    if (!root) return {};

    vector<int> result;
    queue<BSTNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> currentLevel(levelSize);
        
        for (int i = 0; i < levelSize; ++i) {
            BSTNode* currentNode = q.front();
            q.pop();
            
            int index = leftToRight ? i : (levelSize - 1 - i);
            currentLevel[index] = currentNode->val;

            if (currentNode->left) q.push(currentNode->left);
            if (currentNode->right) q.push(currentNode->right);
        }

        result.insert(result.end(), currentLevel.begin(), currentLevel.end());
        leftToRight = !leftToRight;
    }

    return result;
}

// Code Cau 6
int singleChild(BSTNode* root) {
    if (!root) return 0;

    const int MAX_NODES = 100000;
    BSTNode* nodeStack[MAX_NODES];
    BSTNode* parentStack[MAX_NODES];
    int stackTop = 0;

    int count = 0;

    nodeStack[stackTop] = root;
    parentStack[stackTop] = nullptr;
    stackTop++;

    while (stackTop > 0) {
        stackTop--;
        BSTNode* node = nodeStack[stackTop];
        BSTNode* parent = parentStack[stackTop];

        if (node != nullptr) {
            if (parent != nullptr) {
                if ((parent->left == nullptr && parent->right != nullptr) ||
                    (parent->left != nullptr && parent->right == nullptr)) {
                    count++;
                }
            }
            if (node->right != nullptr) {
                nodeStack[stackTop] = node->right;
                parentStack[stackTop] = node;
                stackTop++;
            }
            if (node->left != nullptr) {
                nodeStack[stackTop] = node->left;
                parentStack[stackTop] = node;
                stackTop++;
            }
        }
    }

    return count;
}

// Code Cau 7
int kthSmallest(BSTNode* root, int k) {
    // STUDENT ANSWER
    stack<BSTNode*> s;
    BSTNode* current = root;
    int count = 0;

    while (!s.empty() || current != nullptr) {
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        count++;
        if (count == k) {
            return current->val;
        }

        current = current->right;
    }

    return 0;
}

// Code Cau 8
BSTNode* subtreeWithRange(BSTNode* root, int lo, int hi) {
    // STUDENT ANSWER
    if (root == nullptr) {
        return nullptr;
    }
    
    if (root->val < lo) {
        return subtreeWithRange(root->right, lo, hi);
    }

    if (root->val > hi) {
        return subtreeWithRange(root->left, lo, hi);
    }

    root->left = subtreeWithRange(root->left, lo, hi);
    root->right = subtreeWithRange(root->right, lo, hi);
    return root;
}

int main() {

    return 0;
}