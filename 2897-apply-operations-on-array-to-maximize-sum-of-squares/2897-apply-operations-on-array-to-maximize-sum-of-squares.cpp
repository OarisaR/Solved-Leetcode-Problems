/*
Some insights.
Choose the numbers which are power of 2 / whose AND is 0, but of course they
must not be same. Because doing the AND of such numbers will result in zero, and
doing the OR will basically transfer the number from one to other. So let's say
I'm doing OR of 2 and 8. It will be 10. So basically it's transferring. So it's
become 8 plus 2. However, if the number is same, then it doesn't have any
benefit because the number stays the same. So we need a number higher than the
individual of the numbers.
- The two numbers are chosen such that the 1 is not present at the same
position, because only AND of two ones would result in a one. So basically this
will ensure that those two numbers will always have an AND of zero.

---------------------final plan-------------------------
- we will try to make the larger num large and smalle num small.
- it is basically transferring the 1's in the bit positions.
*/

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(32, 0); // stores count of ones in each bit pos
        for (int i = 0; i < n; i++) {
            for (int b = 0; b < 32; b++) {
                if (nums[i] & (1 << b)) {
                    // bit is set?
                    cnt[b]++;
                }
            }
        }
        int MOD = 1e9 + 7;
        long long res = 0;
        while (k--) {
            long long curr = 0; // we build number from 0
            for (int b = 0; b < 32; b++) {
                if (cnt[b] > 0) {
                    
                    curr =( curr | (1 << b)); // set to 1
                    cnt[b]--;
                    
                }
            }
            res = (res +  (curr * curr)) % MOD;
        }
        return res;
    }
};