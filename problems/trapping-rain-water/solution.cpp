class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n), rmax(n);

        lmax[0] = height[0];
        rmax[n - 1] = height[n - 1];

        for (int i = 1; i < n; i++) {
            lmax[i] = max(lmax[i - 1], height[i]);
            rmax[n - 1 - i] = max(rmax[n - i], height[n - 1 - i]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += min(lmax[i], rmax[i]) - height[i];
        }

        return ans;
    }
};