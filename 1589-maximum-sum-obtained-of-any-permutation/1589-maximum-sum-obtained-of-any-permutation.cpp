/*
### Permutation thought
- count max number of idx =  we can try to keep max num there
- then choose next max cnt and place next max num and so on...
- then apply line sweep!!
*/
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int MOD = 1e9+7;
        int n = nums.size();
        vector<int> events(n, 0);
        
        for (auto& req : requests) {
            int st = req[0];
            int en = req[1];
            events[st] += 1;
            if (en + 1 < n) {
                events[en+1] -= 1;
            }
        }
        // cum sum
        for (int i = 1; i < n; i++) {
            events[i] += events[i - 1];
        }
        int res  =  0;
        sort(nums.begin(),nums.end(),greater<int>()); // descending
        sort(events.begin(),events.end(),greater<int>()); // descending
        // now when we multiply max occuring idx gets multiplied with the max numbers first

        for(int i = 0; i < n ; i++){
           res = (res + (1LL * nums[i] * events[i]) % MOD) % MOD; 
        }
        return res % MOD;

    }
};