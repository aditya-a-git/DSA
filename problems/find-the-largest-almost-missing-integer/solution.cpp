class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if (n == k) {
            return *max_element(nums.begin(), nums.end());
        }

        unordered_set<int> s;

        if (k == 1) {
            unordered_set<int> except;

            for (const int i : nums) {
                if (s.find(i) != s.end() || except.find(i) != except.end()) {
                    s.erase(i);
                    except.insert(i);
                } else {
                    s.insert(i);
                }
            }

            return s.size() == 0 ? -1 : *max_element(s.begin(), s.end());
        }

        if (nums[0] == nums[n - 1]) {
            return -1;
        }

        for (int i = 1; i < n - 1; i++) {
            s.insert(nums[i]);
        }

        bool l = s.find(nums[0]) != s.end();
        bool r = s.find(nums[n - 1]) != s.end();

        if (l && r) {
            return -1;
        }

        if (l || r) {
            return l ? nums[n - 1] : nums[0];
        }

        return nums[0] > nums[n - 1] ? nums[0] : nums[n - 1];
    }
};