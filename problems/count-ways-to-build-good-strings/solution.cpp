class Solution {
    int mod = 1e9 + 7;

    long long solve(int low, int high, int zero, int one, int size, vector<int>& dp){
        if(size > high){
            return 0;
        }

        if(dp[size] != -1){
            return dp[size];
        }

        long long op = solve(low, high, zero, one, size + zero, dp) + solve(low, high, zero, one, size + one, dp);
        return dp[size] = (size >= low ? 1 + op : op) % mod;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return solve(low, high, zero, one, 0, dp) % mod;
    }
};