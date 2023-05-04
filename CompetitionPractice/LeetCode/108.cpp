#include <vector>

using namespace std;

/*
Repeatedly add middle value in vector to BST in correct spot
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
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int begin, int end) {
      // If subvector is empty
      if (begin > end) return nullptr;

      // Add middle value from subvector to current node in BST
      int mid = (begin + end) / 2;
      TreeNode* root = new TreeNode(nums[mid]);

      // Add nodes in left and right branches of current node
      root->left = sortedArrayToBSTHelper(nums, begin, mid - 1);
      root->right = sortedArrayToBSTHelper(nums, mid + 1, end);
        
      return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }
};