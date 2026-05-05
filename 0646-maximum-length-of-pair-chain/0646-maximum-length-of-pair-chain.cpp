class Solution {
public:
    vector<vector<int>> dp;
    int lis(vector<vector<int>>& pairs, int prev, int curr) {
        if (curr >= pairs.size())
            return 0;
        if (prev != -1 && dp[prev][curr] != -1)
            return dp[prev][curr];

        int take = 0;

        if (prev == -1 || pairs[curr][0] > pairs[prev][1]) {
            take = 1 + lis(pairs, curr, curr + 1);
        }
        int not_take = 0 + lis(pairs, prev, curr + 1);
        if (prev != -1)
            dp[prev][curr] = max(take, not_take);
        return max(take, not_take);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        dp = vector<vector<int>>(1002, vector<int>(1002, -1));
        return lis(pairs, -1, 0); // prev and curr idx;
    }
};