class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ilen = INT_MIN, dlen = INT_MIN;
        int st = 0;

        for(int i = 1; i < n; i++){
            if(nums[i] <= nums[i - 1]){
                ilen = max(ilen, i - st);
                st = i;
            }
        }

        ilen = max(ilen, n - st);
        st = 0;

        for(int i = 1; i < n; i++){
            if(nums[i] >= nums[i - 1]){
                dlen = max(dlen, i - st);
                st = i;
            }
        }

        dlen = max(dlen, n - st);
        return max(ilen, dlen);
    }
};