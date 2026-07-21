/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int, Node*> map;

public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return node;
        }

        if (map.find(node->val) != map.end()) {
            return map[node->val];
        }

        Node* newnode = new Node(node->val);
        map[node->val] = newnode;

        for (const auto p : node->neighbors) {
            newnode->neighbors.push_back(cloneGraph(p));
        }

        return newnode;
    }
};