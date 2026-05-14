class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return false;
        vector<int> freq(n, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0 || nums[i] >= n)
                return false;
            freq[nums[i]]++;
        }

        for (int i = 1; i < n; i++) {
            if (i == n - 1) {
                if (freq[i] != 2)
                    return false;
            } else {
                if (freq[i] != 1)
                    return false;
            }
        }
        return true;
    }
};