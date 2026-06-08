/*
- First thought is quicksort, which arranges elements based on a pivot
- (< pivot)   (== pivot)   (> pivot)
*/

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot)
                ans.push_back(nums[i]);
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] == pivot)
                ans.push_back(pivot);
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > pivot)
                ans.push_back(nums[i]);
        }

       return ans;
    }
};