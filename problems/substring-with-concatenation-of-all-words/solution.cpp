class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> freq;

        for (const string& str : words) {
            freq[str]++;
        }

        int len = words[0].size();
        int n = words.size(); 
        vector<int> sol;

        for (int i = 0; i < len; i++) {
            int left = i;
            int right = i;
            unordered_map<string, int> temp;
            int count = 0;

            while (right + len <= s.size()) {
                string sub = s.substr(right, len);
                right += len;

                if (freq.find(sub) == freq.end()) {
                    left = right;
                    temp.clear();
                    count = 0;
                    continue;
                }

                temp[sub]++;
                count++;

                while (temp[sub] > freq[sub]) {
                    string leftword = s.substr(left, len);
                    temp[leftword]--;
                    left += len;
                    count--;
                }

                if (count == n) {
                    sol.push_back(left);
                    string leftword = s.substr(left, len);
                    temp[leftword]--;
                    left += len;
                    count--;
                }
            }
        }

        return sol;
    }
};