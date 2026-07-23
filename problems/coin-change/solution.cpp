class Solution {
    int coin(vector<int>& coins, int amt, int i, vector<vector<int>>& dp) {
        if (amt == 0) {
            return 0;
        }

        if (i >= coins.size() || amt < 0) {
            return 1e8;
        }

        if (dp[i][amt] != -1) {
            return dp[i][amt];
        }

        return dp[i][amt] = min({1 + coin(coins, amt - coins[i], i, dp),
                                 1 + coin(coins, amt - coins[i], i + 1, dp),
                                 coin(coins, amt, i + 1, dp)});
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int res = coin(coins, amount, 0, dp);
        return res >= 1e8 ? -1 : res;
    }
};