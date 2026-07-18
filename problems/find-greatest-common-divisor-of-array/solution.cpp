class Solution {
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }

        return gcd(b, a % b);
    }

public:
    int findGCD(vector<int>& nums) {
        int minnum = INT_MAX, maxnum = INT_MIN;

        for (const int i : nums) {
            minnum = min(minnum, i);
            maxnum = max(maxnum, i);
        }

        return gcd(maxnum, minnum);
    }
};