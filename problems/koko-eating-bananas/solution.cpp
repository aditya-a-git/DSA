class Solution {
    bool canFinish(vector<int>& piles, int h, int k) {
        int sum = 0;

        for (const int i : piles) {
            sum += i % k == 0 ? i / k : i / k + 1;
        }

        return sum <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, u = *max_element(piles.begin(), piles.end());

        while (l < u) {
            int mid = (l + u) / 2;

            if (canFinish(piles, h, mid)) {
                u = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};