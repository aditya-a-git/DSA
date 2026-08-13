class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter,
                               vector<int>& newint) {
        if (inter.empty()) {
            return {newint};
        }

        vector<vector<int>> sol;
        int st = -1;
        bool done = false;

        for (const auto& vec : inter) {
            if (st != -1) {
                if (newint[1] >= vec[0] && newint[1] <= vec[1]) {
                    sol.push_back({st, vec[1]});
                    done = true;
                    st = -1;
                }

                if (newint[1] < vec[0]) {
                    sol.push_back({st, newint[1]});
                    sol.push_back({vec[0], vec[1]});
                    done = true;
                    st = -1;
                }
            } else if (newint[0] >= vec[0] && newint[0] <= vec[1]) {
                st = vec[0];

                if (newint[1] >= vec[0] && newint[1] <= vec[1]) {
                    sol.push_back({vec[0], vec[1]});
                    done = true;
                    st = -1;
                }

            } else if (!done && newint[0] < vec[0]) {
                st = newint[0];

                if (newint[1] < vec[0]) {
                    sol.push_back({st, newint[1]});
                    sol.push_back({vec[0], vec[1]});
                    done = true;
                    st = -1;
                }

                if (newint[1] >= vec[0] && newint[1] <= vec[1]) {
                    sol.push_back({st, vec[1]});
                    done = true;
                    st = -1;
                }
            } else {
                sol.push_back(vec);
            }
        }

        if (!done) {
            if (st == -1) {
                sol.push_back(newint);
            } else {
                sol.push_back({st, newint[1]});
            }
        }

        return sol;
    }
};