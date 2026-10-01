class Solution {
    void solve(vector<int>& nums, vector<int> ans, set<vector<int>>& sol,
               int i, int n) {
        if (i >= nums.size()) {
            if (ans.size() >= 2) {
                sol.emplace(ans);
            }

            return;
        }

        solve(nums, ans, sol, i + 1, n);

        if (nums[i] >= n) {
            ans.push_back(nums[i]);
            solve(nums, ans, sol, i + 1, nums[i]);
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> sol;
        solve(nums, {}, sol, 0, INT_MIN);
        vector<vector<int>> res(sol.begin(), sol.end());
        return res;
    }
};