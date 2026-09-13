class Solution {
    void solve(vector<int>& nums, set<vector<int>>& sol, int i){
        if(i == nums.size()){
            sol.emplace(nums);
            return;
        }

        for(int j = i; j < nums.size(); j++){
            swap(nums[i], nums[j]);
            solve(nums, sol, i + 1);
            swap(nums[i], nums[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> sol;
        solve(nums, sol, 0);
        vector<vector<int>> res(sol.begin(), sol.end());
        return res;
    }
};