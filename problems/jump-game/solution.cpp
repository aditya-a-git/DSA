class Solution {
    bool jump(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size()) {
            return false;
        }

        if (i == nums.size() - 1) {
            return true;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        for (int j = 1; j <= nums[i]; j++) {
            if (jump(nums, i + j, dp)) {
                return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return jump(nums, 0, dp);
    }
};