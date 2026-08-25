class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;

        for (const int i : nums) {
            if (i % k == 0) {
                s.insert(i);
            }
        }

        int i = 1;

        while (true) {
            if (s.find(k * i) == s.end()) {
                return k * i;
            }

            i++;
        }

        return -1;
    }
};