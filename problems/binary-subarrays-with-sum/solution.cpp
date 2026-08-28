class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (i - 1 < 0) {
                    if (prefix[j] == goal) {
                        count++;
                    }
                } else {
                    int sum = prefix[j] - prefix[i - 1];

                    if (sum == goal) {
                        count++;
                    }

                    if (sum > goal) {
                        break;
                    }
                }
            }
        }

        return count;
    }
};