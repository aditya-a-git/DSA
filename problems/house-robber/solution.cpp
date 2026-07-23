class Solution {
    int maxLoot(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size()) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        return dp[i] = max(nums[i] + maxLoot(nums, i + 2, dp), maxLoot(nums, i + 1, dp));
    }

public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return maxLoot(nums, 0, dp);
    }
};