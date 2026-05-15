class Solution {
public:
    int findMin(vector<int>& nums) {
        // find largest element! --> pivot --> the next num after this is the min
        int n = nums.size();
        int l = 0, r = n - 1;
        int idx = 0 , mx = nums[0];
        while(l <= r){
            int mid = (l+r)/2;
            if(nums[mid] < mx){
                r = mid - 1; // discard the right half as all are low
            }
            else {
                mx = nums[mid];
                idx = mid;
                l = mid + 1;
            }

        }
        cout << idx << endl;
        if(idx == n-1) return nums[0];
        return nums[idx+1];
    }
};