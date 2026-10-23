class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr_max = 1, curr_min = 1;
        int ans = INT_MIN;

        for(const int i : nums){
            int prev_max = curr_max, prev_min = curr_min;
            curr_max = max({i, i * prev_max, i * prev_min});
            curr_min = min({i, i * prev_max, i * prev_min});
            ans = max({ans, curr_max, curr_min});
        }

        return ans;
    }
};