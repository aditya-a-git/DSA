class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (const int i : nums) {
            freq[i]++;
        }

        for (const auto& p : freq) {
            if (p.second % 2 == 1) {
                return false;
            }
        }

        return true;
    }
};