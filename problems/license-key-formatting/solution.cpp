class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string str = "";

        for (const char c : s) {
            if (c != '-') {
                str += toupper(c);
            }
        }

        int n = str.size();
        int first = n % k;
        string res = "";
        res += str.substr(0, first);

        if (res != "" && first != n) {
            res += '-';
        }

        int j = 0;

        for (int i = first; i < n; i++) {
            res += str[i];
            j++;

            if (j == k && i != n - 1) {
                res += '-';
                j = 0;
            }
        }

        return res;
    }
};