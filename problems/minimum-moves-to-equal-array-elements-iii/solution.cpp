class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxele = *max_element(nums.begin(), nums.end());
        int count = 0;

        for(const int i : nums){
            count += maxele - i;
        }

        return count;
    }
};