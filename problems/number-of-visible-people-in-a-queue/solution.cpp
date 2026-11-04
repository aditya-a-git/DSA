class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first < heights[i]) {
                ans[i]++;
                int idx = st.top().second;
                st.pop();

                if (!st.empty()) {
                    ans[idx]++;
                }
            }

            st.push({heights[i], i});
        }

        while (!st.empty()) {
            int idx = st.top().second;
            st.pop();

            if (!st.empty()) {
                ans[idx]++;
            }
        }

        return ans;
    }
};