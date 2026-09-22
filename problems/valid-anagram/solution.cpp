class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;

        for (const char c : s) {
            map[c]++;
        }

        for (const char c : t) {
            if (map.find(c) == map.end()) {
                return false;
            }

            map[c]--;
        }

        for (const auto& p : map) {
            if (p.second != 0) {
                return false;
            }
        }

        return true;
    }
};