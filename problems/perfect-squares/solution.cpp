class Solution {
    int solve(int n, int i, vector<vector<int>>& dp) {
        if (n == 0) {
            return 0;
        }

        if (n < 0 || i > sqrt(n)) {
            return INT_MAX;
        }

        if (dp[n][i] != -1) {
            return dp[n][i];
        }

        int take = solve(n - i * i, i, dp);
        take = take == INT_MAX ? INT_MAX : take + 1;
        int skip = solve(n, i + 1, dp);

        return dp[n][i] = min(skip, take);
    }

public:
    int numSquares(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(sqrt(n) + 1, -1));
        return solve(n, 1, dp);
    }
};