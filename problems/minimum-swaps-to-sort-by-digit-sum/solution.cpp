class Solution {
    int digSum(int n) {
        int sum = 0;

        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        // unordered_map<int, int> map;

        for (int i = 0; i < n; i++) {
            arr.push_back({digSum(nums[i]), i});
        }

        sort(arr.begin(), arr.end(), [&nums](const auto& a, const auto& b) {
            if (a.first == b.first) {
                return nums[a.second] < nums[b.second];
            }

            return a.first < b.first;
        });

        vector<bool> visited(n, false);
        int minswaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || arr[i].second == i) {
                continue;
            }

            int j = i;
            int cycles = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second;
                cycles++;
            }

            minswaps += cycles - 1;
        }

        return minswaps;
    }
};