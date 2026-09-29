/*
a+b-c-d can be written as the difference of two subset sums.
So basically, we need to find the number of ways such that the
difference between two subset sums is equal to target.

-> (a+b)-(c+d) -> s1 - s2 = target
-> s1 + s2 = sum
-> s1 = (target + sum) / 2

We only need to count the number of subsets with sum = s1 because
once s1 is chosen, s2 is automatically the remaining elements.

(1,2): when all signs are reversed, the result's sign is reversed
while the values remain unchanged, so target and -target have the
same number of ways. Hence, if target is negative, we can make it
positive.

-1+2 = 1
 1-2 = -1
 1+2 = 3
-1-2 = -3

Converting target to positive also ensures that s1 does not become
negative, which would cause problems during memoization.
*/

class Solution {
public:
    // two states are changing --> n and sum
    // n has max value of 20 and sum has max value of 1000
    int t[21][1001];

    int countsubsetsum(int n, vector<int>& nums, int sum) {
        if (n == 0) {
            return (sum == 0) ? 1 : 0;
        }

        if (t[n][sum] != -1)
            return t[n][sum];

        int skip = countsubsetsum(n - 1, nums, sum);

        int take = 0;
        if (nums[n - 1] <= sum) {
            take = countsubsetsum(n - 1, nums, sum - nums[n - 1]);
        }

        return t[n][sum] = (take + skip);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        memset(t, -1, sizeof(t));

        int n = nums.size();
        int s = 0;

        target = abs(target);

        for (int& x : nums)
            s += x;

        // check if s1 is an integer
        if ((s + target) % 2 != 0)
            return 0;

        int s1 = (s + target) / 2;

        // find the number of subsets with sum = s1
        return countsubsetsum(n, nums, s1);
    }
};