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
    bool hasPathSumHelper(TreeNode* root, int targetSum, int currSum) {
        if (root == NULL) return false;

        currSum += root->val;

        if (currSum == targetSum && root->left == NULL && root->right == NULL)
            return true;
            
        return hasPathSumHelper(root->left, targetSum, currSum) || 
                hasPathSumHelper(root->right, targetSum, currSum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasPathSumHelper(root, targetSum, 0);
    }
};