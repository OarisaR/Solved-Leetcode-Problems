class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // nlogn
        int n = nums.size();
        int mx = 0;
        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            sum = abs(nums[i] - nums[i + 1]);
            mx = max(mx, sum);
        }
        return mx;
    }
};