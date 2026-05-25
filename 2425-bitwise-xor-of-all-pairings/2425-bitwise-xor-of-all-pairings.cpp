/*
Some initial ideas
- For n and m array -> n x m possible pairings are possible
- Result = XOR of all pairings
*/

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // numbers appearing even  times gets cancelled out!
        // so, do xor of only nums appearing odd times;
        int m = nums1.size();
        int n = nums2.size();
        unordered_map<int, long long> mp;
        for (int &num : nums1) {
            mp[num] += n;
        }
        for (int &num : nums2) {
            mp[num] += m;
        }

        int res = 0;
        for (auto &it : mp) {
            if (it.second % 2)
                res ^= it.first;
        }
        return res;
    }
};