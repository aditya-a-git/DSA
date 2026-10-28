class Solution {
    int solve(vector<vector<int>>& grid, int i, int j, int xorval,
              vector<vector<vector<int>>>& dp) {
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return grid[i][j] ^ xorval;
        }

        if (i >= grid.size() || j >= grid[0].size()) {
            return INT_MAX;
        }

        if (dp[i][j][xorval] != -1) {
            return dp[i][j][xorval];
        }

        return dp[i][j][xorval] =
                   min(solve(grid, i, j + 1, grid[i][j] ^ xorval, dp),
                       solve(grid, i + 1, j, grid[i][j] ^ xorval, dp));
    }

public:
    int minCost(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(
            grid.size(),
            vector<vector<int>>(grid[0].size(), vector<int>(1024, -1)));
        return solve(grid, 0, 0, 0, dp);
    }
};