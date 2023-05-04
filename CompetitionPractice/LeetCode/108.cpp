#include <vector>

using namespace std;

/*
Binary search the vector to repeatedly find the
middle value of a subvector and add it to the BST

1. Return a binary search function that starts with the subvector including all values
	- Make the root's value be the middle value in the sub vector
	- Recursively call the function on the left and right
	  subvectors to find the left and right children of root
	- Return root
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
	
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }
};