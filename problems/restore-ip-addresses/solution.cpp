class Solution {
    void solve(string& s, string ans, vector<string>& sol, int i, int part) {
        if (i >= s.size()) {
            return;
        }

        if (part == 4) {
            string remain = s.substr(i);

            if (remain.size() > 3) {
                return;
            }

            if (remain == "0") {
                ans += remain;
                sol.push_back(ans);
                return;
            }

            if (remain[0] == '0') {
                return;
            }

            if (stoi(remain) <= 255) {
                ans += remain;
                sol.push_back(ans);
            }

            return;
        }

        if (s[i] == '0') {
            ans += s[i];
            ans += '.';
            solve(s, ans, sol, i + 1, part + 1);
            ans.pop_back();
            return;
        }

        for (int j = 0; j < 3; j++) {
            if (stoi(s.substr(i, j + 1)) <= 255) {
                ans += s[i + j];
                ans += '.';
                solve(s, ans, sol, i + j + 1, part + 1);
                ans.pop_back();
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> sol;
        solve(s, "", sol, 0, 1);
        return sol;
    }
};