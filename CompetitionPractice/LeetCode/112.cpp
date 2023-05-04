/*
Recursively traverse down each branch of root subtracting the current value from
the target sum and return true if a leaf node ends up with a target sum of 0

1. Subtract root value from target sum
2. If root is a leaf node and target sum is 0, return true
3. Otherwise, return true if the recursive call of the left or right child is true
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
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;

        targetSum -= root->val;

        // If current node is a leaf and target sum has been reached
        if (targetSum == 0 && root->left == nullptr && root->right == nullptr)
            return true;
        
        // If either of the children have the path sum
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};