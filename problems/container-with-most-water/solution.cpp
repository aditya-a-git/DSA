class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int st = 0, end = n - 1;

        int area = INT_MIN;

        while (st <= end) {
            area = max(area, min(height[st], height[end]) * (end - st));

            if (height[st] < height[end]) {
                st++;
            } else {
                end--;
            }
        }

        return area;
    }
};