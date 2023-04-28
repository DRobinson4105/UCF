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
    void postorderTraversalHelper(vector<int>& nums, TreeNode* root) {
        if (root == nullptr) return;

        postorderTraversalHelper(nums, root->left);

        postorderTraversalHelper(nums, root->right);

        nums.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nums;
        postorderTraversalHelper(nums, root);
        return nums;
    }
};