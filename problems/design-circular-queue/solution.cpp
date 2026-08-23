class MyCircularQueue {
    vector<int> q;
    int f = 0, r = -1, size, count = 0;

public:
    MyCircularQueue(int k) {
        size = k;
        q = vector<int>(k);
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        r = (r + 1) % size;
        q[r] = value;
        count++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        f = (f + 1) % size;
        count--;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return q[f];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }

        return q[r];
    }

    bool isEmpty() { return count == 0; }

    bool isFull() { return count == size; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */