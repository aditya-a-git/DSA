class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        queue<int> q;
        int m = grid.size();
        int n = grid[0].size();

        while (k != 0) {
            q.push(grid[m - 1][n - 1]);

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    q.push(grid[i][j]);
                    grid[i][j] = q.front();
                    q.pop();
                }
            }

            k--;
            q.pop();
        }

        return grid;
    }
};