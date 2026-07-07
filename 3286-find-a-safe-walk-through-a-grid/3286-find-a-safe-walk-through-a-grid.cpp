class Solution {
public:
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {-1, 1, 0, 0};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        // min cost to reach dest = x
        // condition for returning true, health - x >=1
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        // res[i][j] = min cost to reach i,j from 0,0
        deque<pair<int, int>> dq;
        res[0][0] = grid[0][0]; // src
        dq.push_front({0, 0});
        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;
                if (res[r][c] + grid[nr][nc] < res[nr][nc]) {
                    res[nr][nc] = res[r][c] + grid[nr][nc];
                    if (grid[nr][nc] == 0) {
                        // same level , so cost wont increase, we push it to the
                        // front as the min is to be processed earlier
                        dq.push_front({nr, nc});
                    } else {
                        dq.push_back({nr, nc});
                    }
                }
            }
        }
        int x = res[m - 1][n - 1];
        return health - x >= 1 ? true : false;
    }
};