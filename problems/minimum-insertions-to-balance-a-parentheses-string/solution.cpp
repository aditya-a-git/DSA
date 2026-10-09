class Solution {
public:
    int minInsertions(string s) {
        stack<int> st;
        int score = 0;

        for (const char c : s) {
            if (c == '(') {
                if(!st.empty() && st.top() == 1){
                    st.pop();
                    score++;
                }

                st.push(2);
            } else {
                if (st.empty()) {
                    score++;
                    st.push(1);
                } else {
                    st.top()--;

                    if (st.top() == 0) {
                        st.pop();
                    }
                }
            }
        }

        while (!st.empty()) {
            score += st.top();
            st.pop();
        }

        return score;
    }
};