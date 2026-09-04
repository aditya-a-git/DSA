class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n), suffix(n);
        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            if (nums[i] > prefix[i - 1]) {
                prefix[i] = nums[i];
            } else {
                prefix[i] = prefix[i - 1];
            }

            if (nums[n - 1 - i] < suffix[n - i]) {
                suffix[n - 1 - i] = nums[n - 1 - i];
            } else {
                suffix[n - 1 - i] = suffix[n - i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (prefix[i] - suffix[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};