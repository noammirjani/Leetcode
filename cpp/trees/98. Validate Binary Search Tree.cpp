#include <limits>

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
    bool isValidBST(TreeNode* root, long minBound = LONG_MIN, long maxBound = LONG_MAX) {
        if (!root) return true;

        // Check if the current node's value is within valid bounds
        if (root->val <= minBound || root->val >= maxBound)
            return false;

        // Recursively validate left and right subtrees
        return isValidBST(root->left, minBound, root->val) &&
               isValidBST(root->right, root->val, maxBound);
    }
};