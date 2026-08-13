class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        unordered_map<int, int> map;
        vector<int> sol;

        for (const int i : nums) {
            map[i]++;
            q.push({map[i], i});
        }

        while (!q.empty() && k != 0) {
            int num = q.top().second;
            q.pop();

            if (map[num] == 0) {
                continue;
            }

            sol.push_back(num);
            map[num] = 0;
            k--;
        }

        return sol;
    }
};