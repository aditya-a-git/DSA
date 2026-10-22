class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> map;

        for (const char c : s) {
            map[c]++;
        }

        auto comp = [](const auto& a, const auto& b) {
            return a.second < b.second;
        };

        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> pq(map.begin(), map.end(), comp);

        if (pq.top().second > (n + 1) / 2) {
            return "";
        }

        string ans(n, '-');
        int st = 0;

        while (!pq.empty()) {
            auto [c, freq] = pq.top();
            pq.pop();

            for (int i = 0; i < freq; i++) {
                if (st >= n) {
                    st = 1;
                }

                ans[st] = c;
                st += 2;
            }
        }

        return ans;
    }
};