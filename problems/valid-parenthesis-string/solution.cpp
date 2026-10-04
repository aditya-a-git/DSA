class Solution {
    bool solve(string s, int i, int p, vector<vector<int>>& dp) {
        if (i >= s.size()) {
            return p == 0;
        }

        if (p < 0) {
            return false;
        }

        if (dp[i][p] != -1) {
            return dp[i][p];
        }

        if (s[i] == ')') {
            if (p == 0) {
                return false;
            }

            return dp[i][p] = solve(s, i + 1, p - 1, dp);
        }

        if (s[i] == '(') {
            return dp[i][p] = solve(s, i + 1, p + 1, dp);
        }

        bool op1 = solve(s, i + 1, p, dp);
        bool op2 = solve(s, i + 1, p + 1, dp);
        bool op3 = solve(s, i + 1, p - 1, dp);

        return dp[i][p] = op1 || op2 || op3;
    }

public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(s, 0, 0, dp);
    }
};