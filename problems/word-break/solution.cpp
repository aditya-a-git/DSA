class Solution {
    bool solve(string& s, unordered_map<string, bool>& prefix, int i, int j,
               vector<vector<int>>& dp) {
        if (j == s.size()) {
            return i == s.size();
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        string sub = s.substr(i, j - i + 1);

        if (prefix.find(sub) == prefix.end()) {
            return false;
        }

        if (!prefix[sub]) {
            return dp[i][j] = solve(s, prefix, i, j + 1, dp);
        }

        return dp[i][j] = solve(s, prefix, j + 1, j + 1, dp) ||
                          solve(s, prefix, i, j + 1, dp);
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> prefix;

        for (const string& str : wordDict) {
            for (int i = 0; i < str.size(); i++) {
                prefix[str.substr(0, i + 1)] = false;
            }
        }

        for (const string& str : wordDict) {
            prefix[str] = true;
        }

        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return solve(s, prefix, 0, 0, dp);
    }
};