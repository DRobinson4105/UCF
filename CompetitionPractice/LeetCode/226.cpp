/*
Swap left and right children for each node

1. If root is null, return null
2. Recursively call function on left and right branches
3. Swap left and right children
4. Return root
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        // Invert left and right branches
        invertTree(root->left);
        invertTree(root->right);

        // Swap left and right children
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
};