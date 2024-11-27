#include <iostream>
#include <stack>
#include <queue>
#include <utility>

using namespace std;

class BTNode {
    public: 
        int val; 
        BTNode *left; 
        BTNode *right; 
        BTNode() {
            this->left = this->right = NULL;
        } 
        BTNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        } 
        BTNode(int val, BTNode*& left, BTNode*& right) {
            this->val = val;
            this->left = left;
            this->right = right;
        } 
};

int main() {
    int value[] = {1167,2381,577,2568,124,1519,234,1679,2696,2359};
    int lo = 500, hi = 2000;
    BTNode* root = BTNode::createBSTree(value, value + sizeof(value)/sizeof(int));
    cout << rangeCount(root, lo, hi);
    return 0;
}