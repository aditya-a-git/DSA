class Solution {
    int minsum(vector<vector<int>>& grid, int i, int j,
               vector<vector<int>>& dp) {
        if (i >= grid.size() || j >= grid[0].size()) {
            return INT_MAX;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int res = min(minsum(grid, i + 1, j, dp), minsum(grid, i, j + 1, dp));
        return dp[i][j] = res == INT_MAX ? grid[i][j] : res + grid[i][j];
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return minsum(grid, 0, 0, dp);
    }
};