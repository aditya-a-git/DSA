class Solution {
    int dfs(vector<vector<int>>& adj, int i, vector<bool>& vis) {
        int count = 0;
        vis[i] = true;

        for (const int j : adj[i]) {
            if (!vis[j]) {
                count += dfs(adj, j, vis);
            }
        }

        return 1 + count;
    }

public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;       
                }

                long long dist = pow(bombs[i][0] - bombs[j][0], 2) +
                                 pow(bombs[i][1] - bombs[j][1], 2);

                if (dist <= 1LL * bombs[i][2] * bombs[i][2]) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> vis(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            count = max(count, dfs(adj, i, vis));
            vis.assign(n, false);
        }

        return count;
    }
};