class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0;
        int prefix = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            int rem = prefix % k;

            if(rem < 0){
                rem += k;
            }

            count += mp[rem];
            mp[rem]++;
        }

        return count;
    }
};