class Solution {
public:
    bool isGood(vector<int>& nums) {


        int n = nums.size();
        if(n==1) return false;
        map<int, int> mp;
        for (int& num : nums)
            mp[num]++;
        for (int i = 1; i < n; i++) {
            if (i == n - 1) {
                if (mp[i] != 2)
                    return false;
            } else {
                if (mp[i] != 1)
                    return false;
            }
        }
        return true;
    }
};