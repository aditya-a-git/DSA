class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i : asteroids) {
            if (i < 0) {
                if (!st.empty() && st.top() > 0) {
                    while (!st.empty() && st.top() > 0 && st.top() < abs(i)) {
                        st.pop();
                    }

                    if (!st.empty() && st.top() > 0) {
                        if(st.top() == abs(i)){
                            st.pop();
                        }else if(st.top() < abs(i)){
                            st.pop();
                            st.push(i);
                        }
                    } else {
                        st.push(i);
                    }
                } else {
                    st.push(i);
                }
            } else {
                st.push(i);
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};