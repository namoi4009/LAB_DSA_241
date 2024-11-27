#include <iostream>
#include <utility>
#include <queue>
#include <stack>

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

// ===== Code Cau 4: Start =====
pair<int, int> dfs(BTNode* node) {
    if (node == NULL) {
        return make_pair(0, 0); // Length 0, sum 0
    }

    pair<int, int> leftResult = dfs(node->left);
    pair<int, int> rightResult = dfs(node->right);

    int leftLength = leftResult.first;
    int leftSum = leftResult.second;

    int rightLength = rightResult.first;
    int rightSum = rightResult.second;

    int maxLength, maxSum;

    if (leftLength > rightLength) {
        maxLength = leftLength + 1;
        maxSum = leftSum + node->val;
    } else if (rightLength > leftLength) {
        maxLength = rightLength + 1;
        maxSum = rightSum + node->val;
    } else { // lengths are equal
        maxLength = leftLength + 1; // or rightLength + 1
        maxSum = max(leftSum, rightSum) + node->val;
    }

    return make_pair(maxLength, maxSum);
}

int longestPathSum(BTNode* root) {
    if (root == NULL) return 0;
    pair<int, int> result = dfs(root);
    return result.second;
}
// Code Cau 4: End =====

// Code Cau 6: Start =====
int sumDigitPath(BTNode* root) {
    if (!root) return 0;
    
    const int MOD = 27022001;
    int total = 0;
    
    stack<pair<BTNode*, int>> s;
    s.push(make_pair(root, root->val % MOD));
    
    while (!s.empty()) {
        auto temp = s.top();
        BTNode* currNode = temp.first;
        int currSum = temp.second;
        s.pop();
        
        if (!currNode->left && !currNode->right)  total = (total + currSum) % MOD;
        if (currNode->left) s.push(make_pair(currNode->left, (currSum*10 + currNode->left->val) % MOD));
        if (currNode->right) s.push(make_pair(currNode->right, (currSum*10 + currNode->right->val) % MOD));
    }
    
    return total;
}
// ===== Code Cau 6: End =====

// ===== Code Cau 7: Start =====
BTNode* helper(BTNode* root, int a, int b) {
    if (!root) return nullptr;
    
    if (root->val == a || root->val == b) return root;
    
    BTNode* lt = helper(root->left, a, b);
    BTNode* rt = helper(root->right, a, b);
    
    if (lt && rt) return root;
    
    return lt != nullptr ? lt : rt;
}

int lowestAncestor(BTNode* root, int a, int b) {
    BTNode* ans = helper(root, a, b);
    return ans != nullptr ? ans->val : -1;
}
// ===== Code Cau 7: End =====

int main() {

    return 0;
}