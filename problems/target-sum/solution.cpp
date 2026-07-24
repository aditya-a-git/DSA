class Solution {
    int solve(vector<int>& nums, int i, vector<vector<int>>& dp, int sum, int& total, int& tar) {
        if (i == nums.size()) {
            return sum == tar;
        }

        if (dp[i][total + sum] != -1) {
            return dp[i][total + sum];
        }

        return dp[i][total + sum] = solve(nums, i + 1, dp, sum + nums[i], total, tar) +
                            solve(nums, i + 1, dp, sum - nums[i], total, tar);
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size(), vector<int>(2 * sum + 1, -1));
        return solve(nums, 0, dp, 0, sum, target);
    }
};