class Solution {
public:
    string evaluate(string s, vector<vector<string>>& know) {
        unordered_map<string, string> map;

        for (const auto& vec : know) {
            map[vec[0]] = vec[1];
        }

        string temp;
        string ans;
        bool brack = false;

        for (const char c : s) {
            if (brack) {
                if (c == ')') {
                    if (map.find(temp) != map.end()) {
                        ans += map[temp];
                    } else {
                        ans += '?';
                    }

                    temp.clear();
                    brack = false;
                } else {
                    temp += c;
                }
            } else {
                if (c == '(') {
                    brack = true;
                } else {
                    ans += c;
                }
            }
        }

        return ans;
    }
};