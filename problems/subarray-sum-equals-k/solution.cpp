class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preSum(n);
        preSum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            preSum[i] = preSum[i - 1] + nums[i];
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (i - 1 < 0 && preSum[j] == k) {
                    count++;
                }

                if (i - 1 >= 0 && preSum[j] - preSum[i - 1] == k) {
                    count++;
                }
            }
        }

        return count;
    }
};