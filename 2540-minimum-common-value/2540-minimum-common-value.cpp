class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        for (int& num : nums1)
            mp[num]++;
        for (int& num : nums2)
            mp[num]++;
        for (auto it : mp) {
            // cout<<"( "<<it.first<<" - "<<it.second<<endl;
            if (it.second > 1) {
                if ((find(nums1.begin(), nums1.end(), it.first) !=
                     nums1.end()) &&
                    (find(nums2.begin(), nums2.end(), it.first) !=
                     nums2.end())) {
                    return it.first;
                }
            }
        }
        return -1;
    }
};