class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<long long> L(n), R(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            int idx = -1;

            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                idx = st.top();
            }

            st.push(i);
            L[i] = idx;
        }

        st = {};

        for (int i = n - 1; i >= 0; i--) {
            int idx = n;

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                idx = st.top();
            }

            st.push(i);
            R[i] = idx;
        }

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += ((i - L[i]) * (R[i] - i) * arr[i]) % mod;
        }

        return sum % mod;
    }
};