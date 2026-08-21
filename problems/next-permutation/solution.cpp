class Solution {
public:
    void nextPermutation(vector<int>& nums) { // next_permutation(nums.begin(),
                                              // nums.end()); obv works!
        int n = nums.size();
        int idx = -1;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        if (idx == -1) {
            sort(nums.begin(), nums.end());
            return;
        }

        int swapidx = -1;

        for (int i = idx + 1; i < n; i++) {
            if (nums[i] > nums[idx]) {
                if (swapidx == -1) {
                    swapidx = i;
                    continue;
                }

                if (nums[i] < nums[swapidx]) {
                    swapidx = i;
                }
            }
        }

        swap(nums[idx], nums[swapidx]);
        sort(nums.begin() + idx + 1, nums.end());
    }
};