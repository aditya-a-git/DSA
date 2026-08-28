class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for (int& i : nums) {
            i = i % 2 == 0 ? 0 : 1;
        }

        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefix = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];

            if (mp.find(prefix - k) != mp.end()) {
                count += mp[prefix - k];
            }

            mp[prefix]++;
        }

        return count;
    }
};