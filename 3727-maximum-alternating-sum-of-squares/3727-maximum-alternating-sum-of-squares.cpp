/*
- keep min elem in odd pos, so least value gets subtracted
- negative elem doesn't matter as we take square of them

-  arr[0]*2 - arr[1]*2 + arr[2]*2 - arr[3]*2
- (arr[0]*2 + arr[2]*2) - (arr[1]*2 + arr[3]*2)
equals
-  (arr[0]*2 + arr[1]*2 + arr[2]*2 + arr[3]*2) - 2 x (arr[1]*2 + arr[3]*2)
- total sum - 2*sum for numbers at odd position

*/

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long tot = 0;
        for(int i = 0; i< n ; i++){
            tot=tot+(nums[i]*nums[i]); // 28
            nums[i] = abs(nums[i]); 
        }
        sort(nums.begin(),nums.end()); // 1,1,2,2,3,3
        long long sum2 = 0;
        for(int i = 0; i< n/2;i++){
            sum2 += nums[i] * nums[i];
        }
        return tot - 2 * sum2;
        

    }
};