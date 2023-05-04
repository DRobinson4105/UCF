#include <iostream>

using namespace std;

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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;

        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        
        if (leftDepth >= 1 && (leftDepth <= rightDepth || rightDepth == 0))
            return 1 + leftDepth;
        if (rightDepth >= 1 && (rightDepth < leftDepth || leftDepth == 0))
            return 1 + rightDepth;

        return 0;
    }
};