class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 || vis[i][j]) {
                    continue;
                }

                queue<pair<int, int>> q;
                q.push({i, j});
                long long sum = 0;

                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();

                    if (vis[r][c]) {
                        continue;
                    }

                    vis[r][c] = true;
                    sum += grid[r][c];

                    if (r + 1 < m && grid[r + 1][c] != 0 && !vis[r + 1][c]) {
                        q.push({r + 1, c});
                    }

                    if (c + 1 < n && grid[r][c + 1] != 0 && !vis[r][c + 1]) {
                        q.push({r, c + 1});
                    }

                    if (r - 1 >= 0 && grid[r - 1][c] != 0 && !vis[r - 1][c]) {
                        q.push({r - 1, c});
                    }

                    if (c - 1 >= 0 && grid[r][c - 1] != 0 && !vis[r][c - 1]) {
                        q.push({r, c - 1});
                    }
                }

                if (sum % k == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};