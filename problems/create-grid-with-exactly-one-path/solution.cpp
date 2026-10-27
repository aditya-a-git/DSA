class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '-'));
        queue<pair<int, int>> q;
        q.push({0, 0});

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            grid[r][c] = '.';

            if (r == m - 1 && c == n - 1) {
                break;
            }

            if (r + 1 < m) {
                q.push({r + 1, c});
            }else if (c + 1 < n) {
                q.push({r, c + 1});
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '-') {
                    grid[i][j] = '#';
                }
            }
        }

        return grid;
    }
};