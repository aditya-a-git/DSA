class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end(),
             [](const auto& a, const auto& b) { return a[1] < b[1]; });
        int ans = 0, prevEnd = INT_MIN;

        for (const auto& vec : inter) {
            if (prevEnd == INT_MIN) {
                prevEnd = vec[1];
            } else if (vec[0] < prevEnd) {
                ans++;
            } else {
                prevEnd = vec[1];
            }
        }

        return ans;
    }
};