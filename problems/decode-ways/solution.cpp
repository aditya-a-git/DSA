class Solution {
    int decode(string& s, int i, vector<int>& dp) {
        if (i == s.size()) {
            return 1;
        }

        if (s[i] == '0') {
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        if (s[i] == '1') {
            int n2 = 0;

            if (i + 2 <= s.size()) {
                n2 = decode(s, i + 2, dp);
            }

            return dp[i] = decode(s, i + 1, dp) + n2;
        }

        if (s[i] == '2') {
            int n2 = 0;

            if (i + 1 < s.size() && s[i + 1] <= '6' && i + 2 <= s.size()) {
                n2 = decode(s, i + 2, dp);
            }

            return dp[i] = decode(s, i + 1, dp) + n2;
        }

        return dp[i] = decode(s, i + 1, dp);
    }

public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return decode(s, 0, dp);
    }
};