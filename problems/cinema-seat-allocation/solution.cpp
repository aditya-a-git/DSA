class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reserved) {
        unordered_map<int, unordered_set<int>> seats;

        for (const auto& vec : reserved) {
            seats[vec[0]].insert(vec[1]);
        }

        int count = 0;
        int rows = 0;

        for (const auto& p : seats) {
            rows++;
            bool left = true, right = true, mid = true;

            for (const int seat : p.second) {
                if (seat == 2 || seat == 3) {
                    left = false;
                }

                if (seat == 4 || seat == 5) {
                    left = false;
                    mid = false;
                }

                if (seat == 6 || seat == 7) {
                    mid = false;
                    right = false;
                }

                if (seat == 8 || seat == 9) {
                    right = false;
                }
            }

            if (left && right) {
                count += 2;
            } else if (left || mid || right) {
                count++;
            }
        }

        int remaining = (n - rows) * 2;

        return count + remaining;
    }
};