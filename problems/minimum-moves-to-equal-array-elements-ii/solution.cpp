class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int tar = nums[n / 2];
        int count = 0;

        for(const int i : nums){
            count += abs(tar - i);
        }

        return count;
    }
};