class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        int n = speed.size();
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({pos[i], speed[i]});
        }

        stack<double> st;

        while (!pq.empty()) {
            auto [p, s] = pq.top();
            pq.pop();
            double t = (double)(target - p) / s;

            if (!st.empty() && t <= st.top()) {
                continue;
            }

            st.push(t);
        }

        return st.size();
    }
};