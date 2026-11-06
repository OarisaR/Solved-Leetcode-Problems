/*
How many elements of first array is such that its difference with all elements in 2nd array is > d
*/

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        int n = arr1.size();
        int m = arr2.size();
        for(int i = 0; i < n ; i++){
            int cnt = 0;
            for(int j  = 0 ; j < m ; j++){
                if(abs(arr1[i]- arr2[j]) > d) {
                    cnt++;
                }
            }
            if(cnt==m) res++;
        }
        return res;
    }
};