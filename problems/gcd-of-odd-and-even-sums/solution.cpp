class Solution {
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }

        return gcd(b, a % b);
    }

public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0, sumEven = 0;

        for (int i = 1; i <= n; i++) {
            sumOdd += 2 * i - 1;
            sumEven += 2 * i;
        }

        return gcd(sumEven, sumOdd);
    }
};