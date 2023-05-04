#include <iostream>

using namespace std;

/*
Get depth of root by finding farthest node and 
adding one for every node from root to that leaf node
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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        
        // Find max depth of left and right branches
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // Current depth is 1 + higher branch depth
        return 1 + ((leftDepth > rightDepth) ? leftDepth : rightDepth);
    }
};