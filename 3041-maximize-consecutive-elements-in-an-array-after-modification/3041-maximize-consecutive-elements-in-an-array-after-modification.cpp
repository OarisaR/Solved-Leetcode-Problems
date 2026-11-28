class Solution {
public:
    int n;
    vector<vector<int>> memo;
    int findmethod(vector<int>& nums, int start, int target) {
        int j = lower_bound(nums.begin() + start, nums.end(), target) -
                nums.begin();
        // lower bound means it returnsfirst element >= target!

        if (j < n && nums[j] == target) {
            return j;
        }
        return -1;
    }
    int solve(int i, int inc, vector<int>& nums) {
        int curr = nums[i] + inc;
        int len = 1;

        if (memo[i][inc] != -1)
            return memo[i][inc];
        // two opt
        // first : find curr + 1
        int j = findmethod(nums, i + 1, curr + 1);
        if (j != -1) {
            // if found
            len = max(len, 1 + solve(j, 0, nums));
        }
        // second: find curr, and then incremenet

        // first find it
        j = findmethod(nums, i + 1, curr);
        if (j != -1) {
            // if found then only inc
            len = max(len, 1 + solve(j, 1, nums));
        }
        return memo[i][inc] = len;
    }
    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        memo.assign(n + 1, vector<int>(2, -1));

        int res = 1; // at best 1 sequence
        for (int i = 0; i < n; i++) {
            res = max({res, solve(i, 0, nums), solve(i, 1, nums)});
            // current number not incremented --> 0
            // incremented --> 1
        }
        return res;
    }
};