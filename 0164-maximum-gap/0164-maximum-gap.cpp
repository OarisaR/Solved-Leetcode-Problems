class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // nlogn
        int n = nums.size();
        int mx = 0;
        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            sum = nums[i + 1 - nums[i]
            mx = max(mx, sum);
        }
        return mx;
    }
};