class Solution {
    bool canShip(vector<int>& weights, int days, int k) {
        int cap = k;

        for (const int i : weights) {
            if (cap - i < 0) {
                days--;
                cap = k - i;

                if (days == 0) {
                    return false;
                }
            } else {
                cap -= i;
            }
        }

        return true;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end()), u = accumulate(weights.begin(), weights.end(), 0);

        while (l < u) {
            int mid = (l + u) / 2;

            if (canShip(weights, days, mid)) {
                u = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};