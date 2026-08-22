class Solution {
    void solve(int k, int i, int n, vector<int>& ans,
               vector<vector<int>>& sol) {
        if (k == 0) {
            sol.push_back(ans);
            return;
        }

        if (i > n) {
            return;
        }

        solve(k, i + 1, n, ans, sol);
        ans.push_back(i);
        solve(k - 1, i + 1, n, ans, sol);
        ans.pop_back();
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;
        vector<vector<int>> sol;
        solve(k, 1, n, ans, sol);
        return sol;
    }
};