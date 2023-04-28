#include <iostream>

using namespace std;

/*
Recursively compare each node in p and q
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null
        if (p == NULL && q == NULL) return true;

        // If one node is null and one is not
        if (p == NULL || q == NULL) return false;

        // If the two current nodes are not the same
        if (p->val != q->val) return false;

        // If the two branches in the two trees are the same
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};