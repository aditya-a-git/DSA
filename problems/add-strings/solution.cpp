class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        bool carry = false;

        while (i >= 0 && j >= 0) {
            char sum = num1[i] - '0' + num2[j];

            if (carry) {
                sum++;
                carry = false;
            }

            if (sum - '0' >= 10) {
                sum = sum - 10;
                carry = true;
            }

            ans = sum + ans;
            i--;
            j--;
        }

        while (i >= 0) {
            char sum = num1[i];

            if (carry) {
                sum++;
                carry = false;
            }

            if (sum - '0' >= 10) {
                sum = sum - 10;
                carry = true;
            }

            ans = sum + ans;
            i--;
        }

        while (j >= 0) {
            char sum = num2[j];

            if (carry) {
                sum++;
                carry = false;
            }

            if (sum - '0' >= 10) {
                sum = sum - 10;
                carry = true;
            }

            ans = sum + ans;
            j--;
        }

        if (carry) {
            ans = '1' + ans;
        }

        return ans;
    }
};