class MinStack {
    stack<int> st, minst;

public:
    MinStack() {}

    void push(int value) {
        st.push(value);

        if (minst.empty() || minst.top() >= value) {
            minst.push(value);
        }
    }

    void pop() {
        int val = st.top();
        st.pop();

        if (val == minst.top()) {
            minst.pop();
        }
    }

    int top() { return st.top(); }

    int getMin() { return minst.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */