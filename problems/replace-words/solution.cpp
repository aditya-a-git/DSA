class Node {
public:
    vector<Node*> links{26, nullptr};
    bool end = false;
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string s) {
        Node* root = new Node();
        Node* node;

        for (const string& word : dictionary) {
            node = root;

            for (const char c : word) {
                if (!node->links[c - 'a']) {
                    node->links[c - 'a'] = new Node();
                }

                node = node->links[c - 'a'];
            }

            node->end = true;
        }

        int i = 0;
        node = root;
        string ans;

        while (i < s.size()) {
            if (s[i] == ' ') {
                ans += ' ';
                node = root;
                i++;
                continue;
            }

            if (node->end) {
                while (i < s.size() && s[i] != ' ') {
                    i++;
                }

                continue;
            }

            if (node->links[s[i] - 'a']) {
                node = node->links[s[i] - 'a'];
                ans += s[i];
                i++;
                continue;
            } else {
                node = root;

                while (i < s.size() && s[i] != ' ') {
                    ans += s[i];
                    i++;
                }
            }
        }

        return ans;
    }
};