class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> num;
        int sum = nums[0];
        num.insert(nums[0]);
        int largest_sum = INT_MIN;

        for (int i = 1; i < nums.size(); i++) {
            num.insert(nums[i]);
        }

        for(int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                largest_sum = max(largest_sum, sum);
                break;
            }

        }

        largest_sum = max(largest_sum, sum);

        for (int i = largest_sum; i < INT_MAX; i++) {
            if (num.find(i) == num.end()) {
                return i;
            }
        }

        return 0;
    }
};