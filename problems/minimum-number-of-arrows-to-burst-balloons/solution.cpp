class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [](const auto& a, const auto& b) { return a[1] < b[1]; });
        int arrow = 0, ans = 0;

        for (const auto& vec : points) {
            if (ans == 0) {
                arrow = vec[1];
                ans++;
            } else if (arrow < vec[0] || arrow > vec[1]) {
                arrow = vec[1];
                ans++;
            }
        }

        return ans;
    }
};