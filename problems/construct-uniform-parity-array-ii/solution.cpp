class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool oddExists = false;

        for (const int i : nums1) {
            if (i % 2 == 1) {
                oddExists = true;
                break;
            }
        }

        if (!oddExists) {
            return true;
        }

        sort(nums1.begin(), nums1.end());

        if (nums1[0] % 2 == 1) {
            return true;
        }

        return false;
    }
};