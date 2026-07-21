class Solution {
    int find(vector<int>& par, int u) {
        if (par[u] == u) {
            return u;
        }

        return par[u] = find(par, par[u]);
    }

    bool unite(int a, int b, vector<int>& rank, vector<int>& par) {
        int pa = find(par, a);
        int pb = find(par, b);

        if (pa == pb) {
            return true;
        }

        if (rank[pa] > rank[pb]) {
            par[pb] = pa;
        } else if (rank[pb] > rank[pa]) {
            par[pa] = pb;
        } else {
            par[pb] = pa;
            rank[pa]++;
        }

        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> rank(n + 1, 0);
        vector<int> parent(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        for (const auto vec : edges) {
            if (unite(vec[0], vec[1], rank, parent)) {
                return {vec[0], vec[1]};
            }
        }

        return {};
    }
};