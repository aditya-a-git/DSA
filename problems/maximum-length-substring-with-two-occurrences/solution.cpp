class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0, r = 0;
        int len = INT_MIN;
        unordered_map<char, int> freq;

        while (l <= r && r < s.size()) {
            if (freq[s[r]] == 2) {
                freq[s[l]]--;
                l++;
                // r++;
            } else {
                freq[s[r]]++;
                len = max(len, r - l + 1);
                r++;
            }
        }

        return len;
    }
};