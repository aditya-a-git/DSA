class Node {
public:
    vector<Node*> links{26, nullptr};
    bool end = false;
    int idx = -1;
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }

        Node* root = new Node();
        Node* node = root;
        string ans;

        for (const string& s : strs) {
            node = root;

            for (const char c : s) {
                if (node->end) {
                    break;
                }

                if (node->idx != -1 && c - 'a' != node->idx) {
                    node->end = true;
                    break;
                }

                if (!node->links[c - 'a']) {
                    node->idx = c - 'a';
                    node->links[c - 'a'] = new Node();
                }

                node = node->links[c - 'a'];
            }

            node->end = true;
        }

        node = root;

        while (!node->end) {
            ans += node->idx + 'a';
            node = node->links[node->idx];
        }

        return ans;
    }
};