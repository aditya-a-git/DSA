class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;
        int dig_sum = 0, dig_prod = 1;

        while (n != 0) {
            dig_sum += n % 10;
            dig_prod *= n % 10;
            n /= 10;
        }

        return num % (dig_sum + dig_prod) == 0;
    }
};