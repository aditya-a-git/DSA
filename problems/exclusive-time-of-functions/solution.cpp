class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int, int>> st;
        vector<int> ans(n);
        int prev = 0;

        for (const string& s : logs) {
            int cidx = s.find(':');
            int fid = stoi(s.substr(0, cidx));
            cidx = s.find(':', cidx + 1);
            int time = stoi(s.substr(cidx + 1));

            if (s.contains("start")) {
                if (!st.empty()) {
                    auto [id, t] = st.top();
                    st.pop();
                    st.push({id, t + time - prev});
                }

                st.push({fid, 0});
                prev = time;
            } else {
                auto [id, t] = st.top();
                st.pop();
                ans[id] += t + time - prev + 1;
                prev = time + 1;
            }
        }

        return ans;
    }
};