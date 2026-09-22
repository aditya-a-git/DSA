class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (string& s : strs) {
            string org = s;
            sort(s.begin(), s.end());
            map[s].push_back(org);
        }

        vector<vector<string>> sol;

        for (const auto& p : map) {
            sol.push_back(p.second);
        }

        return sol;
    }
};