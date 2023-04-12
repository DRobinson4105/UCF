#include <vector>

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
    vector<int> nums;

    void inorderTraverse(TreeNode * root){
        if (root == NULL) return;

        inorderTraverse(root->left);

        nums.push_back(root->val);

        inorderTraverse(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        inorderTraverse(root);
        return nums;
    }
};