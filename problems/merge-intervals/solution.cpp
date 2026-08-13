class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end(), [](const auto& a, const auto& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }

            return a[0] < b[0];
        });

        int l = -1, r = 0;
        vector<vector<int>> sol;

        for (const auto& vec : inter) {
            if (l == -1) {
                l = vec[0];
                r = vec[1];
            } else if (vec[0] > r) {
                sol.push_back({l, r});
                l = vec[0];
                r = vec[1];
            } else {
                r = max(r, vec[1]);
            }
        }

        sol.push_back({l, r});
        return sol;
    }
};