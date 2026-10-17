class Solution {
public:
    int sum(int n) {
        int s = 0;
        while (n > 0) {
            s += n % 10; // extract last digit
            n /= 10;     // remove last digit
        }
        return s;
    }
    int minSwaps(vector<int>& nums) {
        vector<int> expected = nums;
        int n = nums.size();

        auto lambda = [this](int& a, int& b) {
            int da = sum(a);
            int db = sum(b);
            if (da != db)
                return da < db;
            return a < b;
        };
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i; // storing the original pos of the numbers
        } 
        sort(expected.begin(), expected.end(), lambda);
        int swap = 0;
        for (int i = 0; i < n; i++) {
           // cout << expected[i] << " ";
            if (nums[i] == expected[i])
                continue; // no swap needed
            
            // find idx of the expected number
            int idx = mp[expected[i]];
            // we need to swap nums[idx] and nums[i];

            int temp = nums[idx];
            nums[idx] = nums[i];
            mp[nums[idx]] = idx;
            nums[i] = temp;
            mp[nums[i]] = i;

            swap++;
        }
        return swap;
    }
};