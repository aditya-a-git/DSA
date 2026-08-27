class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre(n + 1);
        pre[0] = 0;

        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + arr[i];
        }

        int len = 1;
        int sum = 0;

        while (len <= n) {
            for (int i = 1; i <= n && i + len - 1 <= n; i++) {
                sum += pre[i + len - 1] - pre[i - 1];
            }

            len += 2;
        }

        return sum;
    }
};