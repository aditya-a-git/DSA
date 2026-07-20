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
    TreeNode* flat(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        TreeNode* l = flat(root->left);
        TreeNode* r = flat(root->right);
        TreeNode* temp = r;

        if (!l) {
            return root;
        }

        root->right = l;
        root->left = nullptr;
        TreeNode* curr = root;

        while (curr->right) {
            curr = curr->right;
        }

        curr->right = r;
        return root;
    }

public:
    void flatten(TreeNode* root) { flat(root); }
};