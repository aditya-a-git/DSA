class Solution {
    void solve(vector<int>& nums, int t, int i, vector<int> ans,
               unordered_set<int> dup, set<vector<int>>& sol) {
        if (t == 0) {
            sort(ans.begin(), ans.end());
            sol.emplace(ans);
            return;
        }

        if (i >= nums.size() || t < 0) {
            return;
        }

        if (dup.find(nums[i]) != dup.end()) {
            solve(nums, t, i + 1, ans, dup, sol);
            return;
        }

        ans.push_back(nums[i]);
        solve(nums, t - nums[i], i + 1, ans, dup, sol);
        ans.pop_back();
        dup.insert(nums[i]);
        solve(nums, t, i + 1, ans, dup, sol);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> sol;
        solve(candidates, target, 0, {}, {}, sol);
        vector<vector<int>> res;

        for (const auto& s : sol) {
            res.push_back(s);
        }

        return res;
    }
};