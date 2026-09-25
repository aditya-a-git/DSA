class FrontMiddleBackQueue {
    deque<int> q;
    int count = 0;

public:
    FrontMiddleBackQueue() {}

    void pushFront(int val) {
        q.push_front(val);
        count++;
    }

    void pushMiddle(int val) {
        int r = count / 2;
        stack<int> st;
        while (!q.empty() && r != 0) {
            st.push(q.front());
            q.pop_front();
            r--;
        }

        q.push_front(val);

        while (!st.empty()) {
            q.push_front(st.top());
            st.pop();
        }
        count++;
    }

    void pushBack(int val) {
        q.push_back(val);
        count++;
    }

    int popFront() {
        if(q.empty()){
            return -1;
        }

        int num = q.front();
        q.pop_front();
        count--;
        return num;
    }

    int popMiddle() {
        if(q.empty()){
            return -1;
        }

        int r = count / 2;

        if (count % 2 == 0) {
            r--;
        }

        int num;
        stack<int> st;

        while (!q.empty() && r != 0) {
            st.push(q.front());
            q.pop_front();
            r--;
        }

        if (q.empty()) {
            num = -1;
        } else {
            num = q.front();
            q.pop_front();
        }

        while (!st.empty()) {
            q.push_front(st.top());
            st.pop();
        }

        count--;
        return num;
    }

    int popBack() {
        if(q.empty()){
            return -1;
        }

        int num = q.back();
        q.pop_back();
        count--;
        return num;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */