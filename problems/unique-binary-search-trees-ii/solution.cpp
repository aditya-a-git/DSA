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
    vector<TreeNode*> solve(int st, int end) {
        if (st > end) {
            return {nullptr};
        }

        vector<TreeNode*> sol;

        for (int i = st; i <= end; i++) {
            vector<TreeNode*> left = solve(st, i - 1);
            vector<TreeNode*> right = solve(i + 1, end);

            for (const auto l : left) {
                for (const auto r : right) {
                    TreeNode* node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    sol.push_back(node);
                }
            }
        }

        return sol;
    }

public:
    vector<TreeNode*> generateTrees(int n) { return solve(1, n); }
};