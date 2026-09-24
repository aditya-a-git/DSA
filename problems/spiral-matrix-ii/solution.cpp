class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, -1));
        queue<vector<int>> q;
        q.push({0, 0, 'r', 1});

        while (!q.empty()) {
            auto vec = q.front();
            int r = vec[0], c = vec[1], num = vec[3];
            char dir = vec[2];
            q.pop();

            mat[r][c] = num;

            if (dir == 'r') {
                if (c + 1 < n && mat[r][c + 1] == -1) {
                    q.push({r, c + 1, 'r', num + 1});
                } else if (r + 1 < n && mat[r + 1][c] == -1) {
                    q.push({r + 1, c, 'd', num + 1});
                }
            }

            if (dir == 'd') {
                if (r + 1 < n && mat[r + 1][c] == -1) {
                    q.push({r + 1, c, 'd', num + 1});
                } else if (c - 1 >= 0 && mat[r][c - 1] == -1) {
                    q.push({r, c - 1, 'l', num + 1});
                }
            }

            if (dir == 'l') {
                if (c - 1 >= 0 && mat[r][c - 1] == -1) {
                    q.push({r, c - 1, 'l', num + 1});
                } else if (r - 1 >= 0 && mat[r - 1][c] == -1) {
                    q.push({r - 1, c, 'u', num + 1});
                }
            }

            if (dir == 'u') {
                if (r - 1 >= 0 && mat[r - 1][c] == -1) {
                    q.push({r - 1, c, 'u', num + 1});
                } else if (c + 1 < n && mat[r][c + 1] == -1) {
                    q.push({r, c + 1, 'r', num + 1});
                }
            }
        }

        return mat;
    }
};