class LRUCache {
    unordered_map<int, int> tab;
    list<int> l;
    int cap, count = 0;

public:
    LRUCache(int capacity) { cap = capacity; }

    int get(int key) {
        if (tab.find(key) != tab.end()) {
            l.remove(key);
            l.push_back(key);
            return tab[key];
        }

        return -1;
    }

    void put(int key, int value) {
        if (tab.find(key) != tab.end()) {
            tab[key] = value;
            l.remove(key);
            l.push_back(key);
            return;
        }

        if (count == cap) {
            int lkey = l.front();
            l.pop_front();
            tab.erase(lkey);
            count--;
        }

        tab[key] = value;
        l.push_back(key);
        count++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */