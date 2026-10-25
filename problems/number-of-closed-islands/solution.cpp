class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 || vis[i][j]) {
                    continue;
                }

                queue<pair<int, int>> q;
                q.push({i, j});
                bool edge = false;

                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();
                    vis[r][c] = true;

                    if (r == 0 || c == 0 || r == m - 1 || c == n - 1) {
                        edge = true;
                    }

                    if (r + 1 < m && grid[r + 1][c] == 0 && !vis[r + 1][c]) {
                        q.push({r + 1, c});
                    }

                    if (c + 1 < n && grid[r][c + 1] == 0 && !vis[r][c + 1]) {
                        q.push({r, c + 1});
                    }

                    if (r - 1 >= 0 && grid[r - 1][c] == 0 && !vis[r - 1][c]) {
                        q.push({r - 1, c});
                    }

                    if (c - 1 >= 0 && grid[r][c - 1] == 0 && !vis[r][c - 1]) {
                        q.push({r, c - 1});
                    }
                }

                if (!edge) {
                    count++;
                }
            }
        }

        return count;
    }
};