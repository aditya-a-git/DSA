class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int count = 0;

        for (const char c : s) {
            if (c == '(') {
                st.push('(');
                count = max(count,(int) st.size());
            } else if (c == ')') {
                st.pop();
            }
        }

        return count;
    }
};