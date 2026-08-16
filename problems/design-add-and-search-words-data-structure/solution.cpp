class Node {
public:
    vector<Node*> links{26, nullptr};
    bool end = false;
};

class WordDictionary {
    Node* root;

    bool dfs(string& word, int i, Node* node) {
        if(i == word.size()){
            return node->end;
        }

        if (word[i] == '.') {
            for (const auto link : node->links) {
                if (link) {
                    if (dfs(word, i + 1, link)) {
                        return true;
                    }
                }
            }

            return false;
        } else if (!node->links[word[i] - 'a']) {
            return false;
        }

        return dfs(word, i + 1, node->links[word[i] - 'a']);
    }

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* node = root;

        for (const char c : word) {
            if (!node->links[c - 'a']) {
                node->links[c - 'a'] = new Node();
            }

            node = node->links[c - 'a'];
        }

        node->end = true;
    }

    bool search(string word) { return dfs(word, 0, root); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */