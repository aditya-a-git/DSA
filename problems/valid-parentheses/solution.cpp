class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == ')') {
                if (st.empty() || st.top() != '(') {
                    return false;
                } else {
                    st.pop();
                    continue;
                }
            }

            if (c == ']') {
                if (st.empty() || st.top() != '[') {
                    return false;
                } else {
                    st.pop();
                    continue;
                }
            }

            if (c == '}') {
                if (st.empty() || st.top() != '{') {
                    return false;
                } else {
                    st.pop();
                    continue;
                }
            }

            st.push(c);
        }

        return st.empty();
    }
};