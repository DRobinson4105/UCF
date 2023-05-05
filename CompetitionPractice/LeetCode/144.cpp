#include <vector>

using namespace std;

/*
Recursive binary tree preorder traversal

1. Add root value to vector
2. Recursively call function on left branch (add all values in left branch to vector)
3. Recursively call function on right branch (add all values in right branch to vector)
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
    void preorderTraversalHelper(vector<int>& nums, TreeNode* root) {
        if (root == nullptr) return;

        // Current Node
        nums.push_back(root->val);

        // Left Branch
        preorderTraversalHelper(nums, root->left);

        // Right Branch
        preorderTraversalHelper(nums, root->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nums;
        preorderTraversalHelper(nums, root);
        return nums;
    }
};