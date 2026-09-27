class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        st.push("");

        for (const char c : s) {
            if (c == '(') {
                st.push("");
            } else if (c == ')') {
                string rev = st.top();
                st.pop();
                string temp = st.top();
                st.pop();

                reverse(rev.begin(), rev.end());
                st.push(temp + rev);
            } else {
                string temp = st.top();
                st.pop();
                st.push(temp + c);
            }
        }

        return st.top();
    }
};