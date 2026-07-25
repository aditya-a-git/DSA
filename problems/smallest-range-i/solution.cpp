class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxe = *max_element(nums.begin(), nums.end());
        int mine = *min_element(nums.begin(), nums.end());
        
        if(maxe == mine){
            return 0;
        }

        mine += k;
        maxe -= k;
        int res = maxe - mine;
        return res < 0 ? 0 : res;
    }
};