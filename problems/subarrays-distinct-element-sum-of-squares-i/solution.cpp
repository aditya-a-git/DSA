class Solution {
public:
    int sumCounts(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            int count = 0;

            for (int j = i; j < n; j++) {
                if (map[nums[j]] == 0) {
                    count++;
                }

                map[nums[j]]++;
                sum += count * count;
            }

            map.clear();
        }

        return sum;
    }
};