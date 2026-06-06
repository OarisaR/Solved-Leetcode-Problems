class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 0);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
        } // 10 14 22 25
        int sum = pref[n - 1];
        vector<int> ans;
        // left sum - right sum = answer
        for (int i = 0; i < n; i++) {
            int left = pref[i] - nums[i];
            int right = sum - nums[i] - left;
            ans.push_back(abs(left - right));
        }
        return ans;
    }
};