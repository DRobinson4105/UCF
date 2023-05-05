#include <vector>

using namespace std;

/*
Recursive binary tree postorder traversal

1. Recursively call function on left branch (add all values in left branch to vector)
2. Recursively call function on right branch (add all values in right branch to vector)
3. Add root value to vector
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
    void postorderTraversalHelper(vector<int>& nums, TreeNode* root) {
        if (root == nullptr) return;

        // Left Branch
        postorderTraversalHelper(nums, root->left);

        // Right Branch
        postorderTraversalHelper(nums, root->right);

        // Current Node
        nums.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nums;
        postorderTraversalHelper(nums, root);
        return nums;
    }
};