class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        auto cmp = [](const auto& a, const auto& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }

            return a.first < b.first;
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> q(cmp);

        for (const string& s : words) {
            freq[s]++;
            q.push({freq[s], s});
        }

        vector<string> sol;

        while (!q.empty() && k != 0) {
            string top = q.top().second;

            if (freq[top] != 0) {
                sol.push_back(top);
                freq[top] = 0;
                k--;
            }

            q.pop();
        }

        return sol;
    }
};