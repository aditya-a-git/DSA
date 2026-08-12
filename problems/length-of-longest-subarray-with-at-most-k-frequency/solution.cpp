class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int l = 0, r = 0;
        int maxlen = INT_MIN;

        while (l <= r && r < n) {

            if (freq[nums[r]] == k) {
                freq[nums[l]]--;
                l++;
            } else {
                freq[nums[r]]++;
                maxlen = max(maxlen, r - l + 1);
                r++;
            }
        }

        return maxlen;
    }
};