class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // do xor of all nums and compare with k to see in how many position the bit differs
        // to check that we can simply perform xor of the two nums
        // because xor = 1 when the bit mismatches
        // so we simply return the number of ones in their xor result
        int tot=0;
        for(int &num:nums){
            tot^=num;
        }
        int diff = tot ^ k;
        return __builtin_popcount(diff);
    }
};