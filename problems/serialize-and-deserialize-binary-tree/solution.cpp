/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    string ser(TreeNode* root) {
        if (!root) {
            return "n";
        }

        return to_string(root->val) + 'e' + ser(root->left) + ser(root->right);
    }

    TreeNode* deser(string& data, int& idx) {
        if (data[idx] == 'n') {
            idx++;
            return nullptr;
        }

        int count = 0;

        while (data[idx] != 'e') {
            count++;
            idx++;
        }

        int num = stoi(data.substr(idx - count, count));
        TreeNode* newnode = new TreeNode(num);
        idx++;

        newnode->left = deser(data, idx);
        newnode->right = deser(data, idx);

        return newnode;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) { return ser(root); }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return deser(data, idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));