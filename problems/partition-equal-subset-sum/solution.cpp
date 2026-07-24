class Solution {
    bool solve(vector<int>& nums, int prev, int sum, vector<vector<int>>& dp) {
        if (sum == 0) {
            return true;
        }

        if (sum < 0) {
            return false;
        }

        if (prev != -1 && dp[prev][sum] != -1) {
            return dp[prev][sum];
        }

        for (int i = prev + 1; i < nums.size(); i++) {
            if (dp[i][sum] = solve(nums, i, sum - nums[i], dp)) {
                return true;
            }
        }

        return false;
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) {
            return false;
        }

        vector<vector<int>> dp(nums.size(), vector<int>(sum / 2 + 1, -1));
        return solve(nums, -1, sum / 2, dp);
    }
};