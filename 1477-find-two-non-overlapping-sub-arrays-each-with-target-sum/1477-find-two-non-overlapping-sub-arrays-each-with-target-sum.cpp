class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int i = 0, j = 0;
        int currsum = 0;
        vector<int> minbestlentillI(n, INT_MAX);
        int bestminlen = INT_MAX;
        int res = INT_MAX;
        while (j < n) {
            currsum += arr[j];
            while (i < j && currsum > target) {
                currsum -= arr[i];
                i++;
            }
            if (currsum == target) {
                // find the min len subbarray till i-1
                int len = j - i + 1;
                if (i > 0 && minbestlentillI[i - 1] != INT_MAX) {
                    res = min(res, len + minbestlentillI[i - 1]);
                }

                bestminlen = min(bestminlen,len); 

            }
            minbestlentillI[j] = bestminlen;
            j++;
        }
    return res == INT_MAX? -1:res;
    }
};