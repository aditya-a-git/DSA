class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[left] <= nums[mid] && nums[mid] <= nums[right]) {
                return nums[left];
            }

            if ((mid - 1 < 0  || nums[mid] <= nums[mid - 1]) && (mid + 1 >= nums.size() || nums[mid] <= nums[mid + 1])) {
                return nums[mid];
            } else if (nums[left] > nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};