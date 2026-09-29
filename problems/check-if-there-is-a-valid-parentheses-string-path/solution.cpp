class Solution {
    bool solve(vector<vector<char>>& grid, int i, int j, int m, int n, int p,
               vector<vector<vector<int>>>& dp) {
        if (i >= m || j >= n) {
            return false;
        }

        if (dp[i][j][p] != -1) {
            return dp[i][j][p];
        }

        int newp;
        if (grid[i][j] == '(') {
            newp = p + 1;
        } else {
            newp = p - 1;
        }

        if (newp < 0) {
            return false;
        }

        if (i == m - 1 && j == n - 1) {
            return newp == 0;
        }

        return dp[i][j][p] = solve(grid, i + 1, j, m, n, newp, dp) || solve(grid, i, j + 1, m, n, newp, dp);
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(m + n, -1)));
        return solve(grid, 0, 0, m, n, 0, dp);
    }
};