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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& preIdx,
                    int st, int end, unordered_map<int, int>& index) {
        if (st > end) {
            return nullptr;
        }

        TreeNode* newnode = new TreeNode(preorder[preIdx]);
        int inIdx = index[preorder[preIdx]];
        preIdx++;

        newnode->left = build(preorder, inorder, preIdx, st, inIdx - 1, index);
        newnode->right = build(preorder, inorder, preIdx, inIdx + 1, end, index);

        return newnode;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> index;

        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }

        int preIdx = 0;
        return build(preorder, inorder, preIdx, 0, preorder.size() - 1, index);
    }
};