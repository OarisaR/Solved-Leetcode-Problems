/*
CASE-1
[0,3,2,1]
[0,1,2,3]
[ok,3&1,ok,1&3] --> 1

CASE-2
[0,1,3,2]
[0,1,2,3]
[ok,ok,3&2,2&3] --> 2 & 1 
*/


class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums);
        sort(sorted.begin(),sorted.end());
        if(sorted == nums) return 0;
        int res = -1;
        for(int i = 0; i  < n ; i++){
            if(nums[i]!=sorted[i]) res=res&(nums[i]&sorted[i]);
            
        }
        return res;
    }
};