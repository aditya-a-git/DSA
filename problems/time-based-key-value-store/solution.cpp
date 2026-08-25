class TimeMap {
    unordered_map<string, set<pair<int, string>, greater<pair<int, string>>>> tab;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        tab[key].emplace(timestamp, value);
    }

    string get(string key, int timestamp) {
        string ans = "";

        for (const auto& p : tab[key]) {
            if (p.first <= timestamp ) {
                ans = p.second;
                break;
            }
        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */