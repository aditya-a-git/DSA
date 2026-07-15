class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int maxFreq = 0;
        int l = 0, r = 0;
        int ans = 0;

        while (r < s.size() && l <= r) {
            int windowlen = r - l + 1;
            freq[s[r]]++;
            maxFreq = max(maxFreq, freq[s[r]]);

            if (windowlen - maxFreq > k) {
                freq[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};