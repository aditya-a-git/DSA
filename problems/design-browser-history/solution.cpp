class BrowserHistory {
    stack<string> bck;
    stack<string> fwd;

public:
    BrowserHistory(string homepage) { bck.push(homepage); }

    void visit(string url) {
        bck.push(url);
        fwd = {};
    }

    string back(int steps) {
        while (steps != 0 && bck.size() != 1) {
            fwd.push(bck.top());
            bck.pop();
            steps--;
        }

        cout << bck.top() << endl;
        return bck.top();
    }

    string forward(int steps) {
        while (steps != 0 && fwd.size() != 0) {
            bck.push(fwd.top());
            fwd.pop();
            steps--;
        }

        cout << bck.top() << endl;
        return bck.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */