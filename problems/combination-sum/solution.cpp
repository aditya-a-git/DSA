class Solution {
    void solve(vector<int>& nums, int i, vector<int>& ans,
               vector<vector<int>>& sol, int target) {
        if (target == 0) {
            sol.push_back(ans);
            return;
        }

        if (i >= nums.size() || target < 0) {
            return;
        }

        solve(nums, i + 1, ans, sol, target);
        ans.push_back(nums[i]);
        solve(nums, i, ans, sol, target - nums[i]);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> sol;
        solve(candidates, 0, {}, sol, target);
        return sol;
    }
};