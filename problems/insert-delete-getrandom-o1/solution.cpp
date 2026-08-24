class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> idx;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (idx.find(val) != idx.end()) {
            return false;
        }

        nums.push_back(val);
        idx[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (idx.find(val) == idx.end()) {
            return false;
        }

        nums[idx[val]] = nums[nums.size() - 1];
        nums.pop_back();
        idx[nums[idx[val]]] = idx[val];
        idx.erase(val);
        return true;
    }

    int getRandom() {
        int index = rand() % nums.size();
        return nums[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */