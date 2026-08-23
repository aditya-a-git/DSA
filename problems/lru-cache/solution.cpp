class LRUCache {
    unordered_map < int, pair<int, list<int>::iterator>> tab;
    list<int> l;
    int cap, count = 0;

public:
    LRUCache(int capacity) { cap = capacity; }

    int get(int key) {
        if (tab.find(key) != tab.end()) {
            l.erase(tab[key].second);
            l.push_back(key);
            tab[key].second = prev(l.end());
            return tab[key].first;
        }

        return -1;
    }

    void put(int key, int value) {
        if (tab.find(key) != tab.end()) {
            tab[key].first = value;
            l.remove(key);
            l.push_back(key);
            tab[key].second = prev(l.end());
            return;
        }

        if (count == cap) {
            int lkey = l.front();
            l.pop_front();
            tab.erase(lkey);
            count--;
        }

        l.push_back(key);
        tab[key] = {value, prev(l.end())};
        count++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */