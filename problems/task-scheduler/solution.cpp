class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        for (const char c : tasks) {
            freq[c]++;
        }

        auto cmp = [](const auto& a, const auto& b) {
            return a.second < b.second;
        };

        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)>
            q(freq.begin(), freq.end(), cmp);

        int largest = q.top().second;
        q.pop();
        int blanks = (largest - 1) * n;
        int intervals = largest + blanks;

        while (!q.empty()) {
            int currfreq = q.top().second;
            q.pop();

            if (currfreq == largest) {
                if (blanks >= currfreq - 1) {
                    blanks -= currfreq - 1;
                    intervals++;
                } else {
                    intervals += currfreq - blanks;
                    blanks = 0;
                }
            } else {
                if (blanks >= currfreq) {
                    blanks -= currfreq;
                } else {
                    intervals += currfreq - blanks;
                    blanks = 0;
                }
            }
        }

        return intervals;
    }
};