class Solution {
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

public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }

        string ans = "";
        int n1 = num1.size();
        int i = n1 - 1;
        int carry;

        while (i >= 0) {
            int j = num2.size() - 1;
            carry = 0;
            string subans = "";

            while (j >= 0) {
                int prod = (num1[i] - '0') * (num2[j] - '0');

                if (carry > 0) {
                    prod += carry;
                    carry = 0;
                }

                if (prod >= 10) {
                    carry = prod / 10;
                }

                char addend = (prod % 10) + '0';
                subans = addend + subans;
                j--;
            }

            if (carry) {
                char addend = carry + '0';
                subans = addend + subans;
                carry = 0;
            }

            for (int k = 0; k < n1 - i - 1; k++) {
                subans += '0';
            }

            ans = addStrings(ans, subans);
            i--;
        }

        if (carry) {
            char addend = carry + '0';
            ans = addend + ans;
        }

        return ans;
    }
};