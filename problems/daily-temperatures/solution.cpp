class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int, int>> st;
        int n = temp.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            int currtemp = temp[i];

            while (!st.empty() && st.top().first < currtemp) {
                int idx = st.top().second;
                ans[idx] = i - idx;
                st.pop();
            }

            st.push({temp[i], i});
        }

        return ans;
    }
};