/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int psum(TreeNode* root, long long tar) {
        if (!root) {
            return 0;
        }

        int count = (tar - root->val == 0) ? 1 : 0;

        return psum(root->left, tar - root->val) +
               psum(root->right, tar - root->val) + count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return 0;
        }

        return psum(root, targetSum) + pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum);
    }
};