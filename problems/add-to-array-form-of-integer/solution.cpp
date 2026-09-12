class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        bool carry = false;
        int i = num.size() - 1;

        while (k > 0 && i >= 0) {
            int n = k % 10;
            k /= 10;

            if (carry) {
                n++;
                carry = false;
            }

            num[i] += n;

            if (num[i] >= 10) {
                carry = true;
                num[i] -= 10;
            }

            i--;
        }

        while (k > 0) {
            int n = k % 10;
            k /= 10;

            if (carry) {
                n++;
                carry = false;
            }

            if (n >= 10) {
                n -= 10;
                carry = true;
            }

            num.insert(num.begin(), n);
        }

        while (i >= 0) {
            if (carry) {
                num[i]++;
                carry = false;
            }

            if (num[i] >= 10) {
                num[i] -= 10;
                carry = true;
            }

            i--;
        }

        if (carry) {
            num.insert(num.begin(), 1);
        }

        return num;
    }
};