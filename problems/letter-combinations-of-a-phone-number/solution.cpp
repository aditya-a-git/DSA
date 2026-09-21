class Solution {
public:
    void comb(unordered_map<int, string> let, int i, string ans, vector<string>& sol, string& digits){
        if(i >= digits.size()){
            sol.push_back(ans);
            return;
        }

        for(const char c : let[digits[i] - '0']){
            ans.push_back(c);
            comb(let, i + 1, ans, sol, digits);
            ans.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> let;
        let[2] = "abc";
        let[3] = "def";
        let[4] = "ghi";
        let[5] = "jkl";
        let[6] = "mno";
        let[7] = "pqrs";
        let[8] = "tuv";
        let[9] = "wxyz";

        vector<string> sol;
        comb(let, 0, "", sol, digits);
        return sol;
    }
};