class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last;
        vector<int> sol;

        for (int i = 0; i < s.size(); i++) {
            last[s[i]] = i;
        }

        int size = 0;
        int end = INT_MIN;

        for (int i = 0; i < s.size(); i++) {
            size++;
            end = max(end, last[s[i]]);

            if (i == end) {
                sol.push_back(size);
                size = 0;
            }
        }

        return sol;
    }
};