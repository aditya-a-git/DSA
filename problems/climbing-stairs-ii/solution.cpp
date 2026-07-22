class Solution {
    int climb(int n, vector<int>& costs, int i, vector<int>& dp) {
        if (i == n)
            return 0;

        if (i > n)
            return INT_MAX;

        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MAX;

        if (i + 1 <= n)
            ans = min(ans, costs[i] + 1 + climb(n, costs, i + 1, dp));

        if (i + 2 <= n)
            ans = min(ans, costs[i + 1] + 4 + climb(n, costs, i + 2, dp));

        if (i + 3 <= n)
            ans = min(ans, costs[i + 2] + 9 + climb(n, costs, i + 3, dp));

        return dp[i] = ans;
    }

public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, -1);
        return climb(n, costs, 0, dp);
    }
};