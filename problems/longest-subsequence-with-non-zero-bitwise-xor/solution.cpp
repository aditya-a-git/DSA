class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = nums[0];
        bool allZeros = nums[0] == 0;

        for (int i = 1; i < n; i++) {
            xr ^= nums[i];

            if (nums[i] != 0) {
                allZeros = false;
            }
        }

        if (xr > 0) {
            return n;
        }

        return allZeros ? 0 : n - 1;
    }
};