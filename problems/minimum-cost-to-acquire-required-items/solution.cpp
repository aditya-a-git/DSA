class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        long long individual = 1LL * cost1 * need1 + 1LL * cost2 * need2;
        int common = min(need1, need2);
        long long combined = 1LL * costBoth * common +
                             1LL * min(costBoth, cost1) * (need1 - common) +
                             1LL * min(costBoth, cost2) * (need2 - common);
        return min(individual, combined);
    }
};