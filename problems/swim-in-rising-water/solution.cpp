class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({grid[0][0], 0, 0});

        while (!q.empty()) {
            auto vec = q.top();
            int t = vec[0], r = vec[1], c = vec[2];
            q.pop();

            if (r == n - 1 && c == n - 1) {
                return t;
            }

            if (vis[r][c]) {
                continue;
            }

            vis[r][c] = true;

            if (r + 1 < n && !vis[r + 1][c]) {
                if (grid[r + 1][c] > t) {
                    q.push({grid[r + 1][c], r + 1, c});
                } else {
                    q.push({t, r + 1, c});
                }
            }

            if (c + 1 < n && !vis[r][c + 1]) {
                if (grid[r][c + 1] > t) {
                    q.push({grid[r][c + 1], r, c + 1});
                } else {
                    q.push({t, r, c + 1});
                }
            }

            if (r - 1 >= 0 && !vis[r - 1][c]) {
                if (grid[r - 1][c] > t) {
                    q.push({grid[r - 1][c], r - 1, c});
                } else {
                    q.push({t, r - 1, c});
                }
            }

            if (c - 1 >= 0 && !vis[r][c - 1]) {
                if (grid[r][c - 1] > t) {
                    q.push({grid[r][c - 1], r, c - 1});
                } else {
                    q.push({t, r, c - 1});
                }
            }
        }

        return -1;
    }
};