class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[j][0] - points[i][0]) +
                           abs(points[j][1] - points[i][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        vector<bool> vis(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 0});
        int mincost = 0;

        while (!q.empty()) {
            auto [cost, u] = q.top();
            q.pop();

            if (vis[u]) {
                continue;
            }

            vis[u] = true;
            mincost += cost;

            for (const auto& p : adj[u]) {
                if (!vis[p.first]) {
                    q.push({p.second, p.first});
                }
            }
        }

        return mincost;
    }
};