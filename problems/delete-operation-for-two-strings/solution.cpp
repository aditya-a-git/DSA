class Solution {
    int del(string& w1, string& w2, int i, int j, vector<vector<int>>& dp) {
        if (i == w1.size()) {
            return w2.size() - j;
        }

        if (j == w2.size()) {
            return w1.size() - i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if (w1[i] == w2[j]) {
            return dp[i][j] = del(w1, w2, i + 1, j + 1, dp);
        }

        return dp[i][j] = 1 + min(del(w1, w2, i + 1, j, dp), del(w1, w2, i, j + 1, dp));
    }

public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return del(word1, word2, 0, 0, dp);
    }
};