class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m1, m2;

        for (const char c : s1) {
            m1[c]++;
        }

        int st = 0, end = s1.size() - 1;

        for (int i = st; i <= end && i < s2.size(); i++) {
            m2[s2[i]]++;
        }

        do {
            if (m1 == m2) {
                return true;
            }

            st++;
            end++;

            if (end >= s2.size()) {
                break;
            }

            m2[s2[end]]++;
            m2[s2[st - 1]]--;

            if (m2[s2[st - 1]] == 0) {
                m2.erase(s2[st - 1]);
            }
        } while (end < s2.size());

        return false;
    }
};