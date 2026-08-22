class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& prereq) {
        vector<int> sol;
        vector<vector<int>> adj(num);
        vector<int> indeg(num, 0);

        for (const auto& vec : prereq) {
            adj[vec[1]].push_back(vec[0]);
            indeg[vec[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < num; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            sol.push_back(u);

            for (const int v : adj[u]) {
                indeg[v]--;

                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (sol.size() != num) {
            return {};
        }

        return sol;
    }
};