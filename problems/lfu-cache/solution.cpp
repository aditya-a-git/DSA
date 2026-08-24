struct Node {
    int val;
    int freq;
    list<int>::iterator pos;
};

class LFUCache {
    unordered_map<int, Node> tab;
    unordered_map<int, list<int>> freqMap;
    int minFreq = -1;
    int cap;
    int count = 0;

public:
    LFUCache(int capacity) { this->cap = capacity; }

    int get(int key) {
        if (tab.find(key) != tab.end()) {
            int freq = tab[key].freq;
            // cout << key << " " << freq << endl;
            freqMap[freq].erase(tab[key].pos);
            freqMap[freq + 1].push_back(key);
            tab[key].pos = prev(freqMap[freq + 1].end());
            tab[key].freq++;

            if (freq == minFreq && freqMap[freq].empty()) {
                minFreq++;
            }

            return tab[key].val;
        }

        return -1;
    }

    void put(int key, int value) {
        if (tab.find(key) != tab.end()) {
            tab[key].val = value;
            int freq = tab[key].freq;
            freqMap[freq].erase(tab[key].pos);
            freqMap[freq + 1].push_back(key);
            tab[key].pos = prev(freqMap[freq + 1].end());
            tab[key].freq++;

            if (freq == minFreq && freqMap[freq].empty()) {
                minFreq++;
            }
        } else {
            Node node;
            node.val = value;
            node.freq = 1;
            freqMap[1].push_back(key);
            node.pos = prev(freqMap[1].end());
            tab[key] = node;

            if (count < cap || minFreq == -1) {
                count++;
            } else {
                int delkey = freqMap[minFreq].front();
                tab.erase(delkey);
                freqMap[minFreq].pop_front();
            }

            minFreq = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */