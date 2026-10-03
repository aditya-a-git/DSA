class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<bool> valid(n, false);
        stack<pair<char, int>> st;
        st.push({'z', -1});
        int i = 0;

        while (!st.empty() && i < n) {
            if (s[i] == '(') {
                st.push({s[i], i});
                i++;
                continue;
            }

            if (st.top().first == 'z') {
                i++;
                continue;
            }

            int idx = st.top().second;
            valid[i] = true;
            valid[idx] = true;
            st.pop();
            i++;
        }

        int currCount = 0;
        int maxCount = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (valid[i]) {
                currCount++;
            } else {
                maxCount = max(maxCount, currCount);
                currCount = 0;
            }
        }

        maxCount = max(maxCount, currCount);
        return maxCount;
    }
};