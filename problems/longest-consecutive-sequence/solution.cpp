class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int best = 0;

        for (int i : set) {
            if (set.find(i - 1) == set.end()) {
                int curr = 0;

                while (set.find(i) != set.end()) {
                    curr++;
                    i++;
                }

                best = max(best, curr);
            }
        }

        return best;
    }
};