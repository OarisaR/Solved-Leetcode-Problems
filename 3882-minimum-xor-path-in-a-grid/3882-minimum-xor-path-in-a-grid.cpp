class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bitset<1024>>> dp(
            m, vector<bitset<1024>>(n)); // value of xor in each cell reached
                                         // from all possible path
        // bitset --> {0,1,1..} where there is 1 it means the xor val is present
        dp[0][0][grid[0][0]] =
            1; // to reach frm 0,0 to 0,0 that grid[0][0] is set.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;
                bitset<1024> up;
                bitset<1024> left;
                if (i > 0) {
                    up = dp[i - 1][j];
                }
                if (j > 0) {
                    left = dp[i][j - 1];
                }
                bitset<1024> combined =
                    up | left; // OR operation finds which xor is present

                for (int x = 0; x < 1024; x++) {
                    if (combined[x]) {
                        int res = x ^ grid[i][j];
                        dp[i][j][res] = 1;
                    }
                }
            }
        }
        // dp[m-1][n-1] this bitset's minimunm xor val is the ans
        for (int x = 0; x < 1024; x++) {
            if (dp[m - 1][n - 1][x])
                return x;
        }
        return -1;
    }
};