class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;

        while (st <= end) {
            if (nums[st] == target && nums[end] == target) {
                return {st, end};
            }

            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                if (nums[st] != target) {
                    st++;
                }

                if (nums[end] != target) {
                    end--;
                }
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return {-1, -1};
    }
};