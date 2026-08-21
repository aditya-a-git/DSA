class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // int n = nums.size();
        // int idx;

        // for(int i = n - 2; i >= 0; i--){
        //     if(nums[i] < nums[i + 1]){
        //         idx = i;
        //         break;
        //     }
        // }

        next_permutation(nums.begin(), nums.end());
    }
};