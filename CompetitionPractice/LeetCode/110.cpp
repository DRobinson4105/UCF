#include <algorithm>

/*
Find balance factor of each node by subtracting the max depth of the
right child from the max depth of the left child and return false  
if any of the nodes have an absolute balance factor greater than 1

1. Get balance factor of current node by getting the difference of the max depth function on left and right children
2. Return false if absolute balance factor is greater than 1 (current node is unbalanced)
3. Recursively call function to find balance factors of children and return false if either one is unbalanced
4. Otherwise, return true

Max Depth Function:
1. Recursively call function to get depths of left and right branch
2. Return 1 + the higher depth
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
        if (root == nullptr) return 0;
        
        // Find max depth of left and right branches
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // Current depth is 1 + higher branch depth
        return 1 + ((leftDepth > rightDepth) ? leftDepth : rightDepth);
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;

        // Get balance factor using depths of left and right children
        int balanceFactor = maxDepth(root->left) - maxDepth(root->right);
        
        // Return false if current root or any children of root are unbalanced
        if (abs(balanceFactor) > 1 || !isBalanced(root->left) || !isBalanced(root->right))
            return false;

        // Return true if current tree is balanced
        return true;
    }
};