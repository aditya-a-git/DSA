class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        for (const char c : s) {
            if (st.empty() || st.top().first != c) {
                st.push({c, 1});
                continue;
            }

            if (st.top().second == k - 1) {
                st.pop();
            } else {
                st.top().second++;
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans = string(st.top().second, st.top().first) + ans;
            st.pop();
        }

        return ans;
    }
};