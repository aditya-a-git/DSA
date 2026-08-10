class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        int count = 0;
        int prevEnd = INT_MIN;

        for (const auto& vec : pairs) {
            if (vec[0] > prevEnd) {
                prevEnd = vec[1];
                count++;
            }
        }

        return count;
    }
};