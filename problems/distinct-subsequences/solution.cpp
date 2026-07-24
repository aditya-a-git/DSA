class Solution {
    int solve(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        if (j >= t.size()) {
            return 1;
        }

        if (i >= s.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int skip = solve(s, t, i + 1, j, dp);
        int take = 0;
        if (s[i] == t[j]) {
            take = solve(s, t, i + 1, j + 1, dp);
        }

        return dp[i][j] = skip + take;
    }

public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size() + 1, -1));
        return solve(s, t, 0, 0, dp);
    }
};