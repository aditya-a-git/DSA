class Solution {
public:
    string convert(string s, int num) {
        if (num == 1) {
            return s;
        }

        vector<string> rows(num);
        int i = 0;
        bool rev = false;

        for (const char c : s) {
            rows[i] += c;

            if (i == num - 1) {
                rev = true;
            }

            if (i == 0) {
                rev = false;
            }

            if (rev) {
                i--;
            } else {
                i++;
            }
        }

        string ans;

        for (const string& str : rows) {
            ans += str;
        }

        return ans;
    }
};