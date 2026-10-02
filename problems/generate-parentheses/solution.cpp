class Solution {
public:
    bool isSafe(string ans, char ch, int n) {
        int open = 0, close = 0;
        for (char i : ans) {
            if (i == '(') {
                open++;
            } else {
                close++;
            }
        }
        if (ch == '(') {
            if (open == n) {
                return false;
            }
        } else {
            if (close == open) {
                return false;
            }
        }

        return true;
    }
    void paran(string& ans, vector<string>& sol, int n) {
        if (ans.size() == n * 2) {
            sol.push_back(ans);
            return;
        }

        if (isSafe(ans, '(', n)) {
            ans.push_back('(');
            paran(ans, sol, n);
            ans.pop_back();
        }
        if (isSafe(ans, ')', n)) {
            ans.push_back(')');
            paran(ans, sol, n);
            ans.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string ans;
        vector<string> sol;
        paran(ans, sol, n);
        return sol;
    }
};