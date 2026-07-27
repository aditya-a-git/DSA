class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int diff = INT_MAX, minsum = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1, k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (abs(sum - target) < diff) {
                    diff = abs(sum - target);
                    minsum = sum;
                }

                if (sum == target) {
                    return target;
                } else if (sum > target) {
                    k--;

                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                } else {
                    j++;

                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                }
            }
        }

        return minsum;
    }
};