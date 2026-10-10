/*
- store diff
- common sense : decrease the max diff val
- so we cn consider k1+k2 op, and until it drops to 0 the whole process goes on
- after decreasing mx, the sorted order changes. hence we use maxheap to get mx
val at top
- once any element is 0. stop reducing it.
- problems : k can go till 10*9 + 10*9, hence this is not a optimal solution
---------NEW IDEA------------
- store count of each num, hence that num can be decreased altogether instead of
doing serially.
-  we do it in a vec, where idx is the val and the cal present there is the cnt.
- the vec's max val can be till 1e5. cuz it is given "0 <= nums1[i], nums2[i] <=
1e5" , so |1e5-0| =1e5
-  better to carry the process in reverse as we want to decrese the largest dff
first
*/

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        int k = k1 + k2;
        vector<int> v(1e5+1, 0);
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            v[abs(nums1[i] - nums2[i])]++;
        }
        long long res = 0;

        for (int i = 1e5; i >=1 ; i--) {
            if(k==0) break;
            int countop = min(k, v[i]);
            v[i] -= countop;
            v[i - 1] += countop; // decreaseing a number means its prev val cnt
                                 // increases
            k -= countop;
        }
        for(long long d = 1; d <= 1e5; d++){
            res += (v[d] * d * d); // count * num * num, cuz the numbers sq gets added cnt number of times
        }
        return res;
    }
};