#include <vector>

using namespace std;

/*
Binary Tree Inorder Traversal:
1) Left Branch
2) Current Node
3) Right Branch
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
    vector<int> nums;

    void inorderTraverse(TreeNode * root) {
        if (root == nullptr) return;

        // Left Branch
        inorderTraverse(root->left);

        // Current Node
        nums.push_back(root->val);

        // Right Branch
        inorderTraverse(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        inorderTraverse(root);
        return nums;
    }
};