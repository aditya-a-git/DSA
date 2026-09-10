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
    int count = 0;

    pair<int, int> solve(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        auto [lno, lsum] = solve(root->left);
        auto [rno, rsum] = solve(root->right);

        if ((lsum + rsum + root->val) / (lno + rno + 1) == root->val) {
            count++;
        }

        return {lno + rno + 1, lsum + rsum + root->val};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return count;
    }
};