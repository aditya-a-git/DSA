class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;

        if(target == 0){
            return n;
        }

        if(target < 0){
            return -1;
        } 

        int st = 0, end = 0;
        int sum = 0;
        int minop = INT_MAX;

        while (end < n) {
            sum += nums[end];

            while(sum > target && st <= end){
                sum -= nums[st++];
            }

            if (sum == target) {
                minop = min(minop, n - (end - st + 1));
            }

            end++;
        }

        return minop == INT_MAX ? -1 : minop;
    }
};