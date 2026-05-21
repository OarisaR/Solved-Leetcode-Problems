class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        //[5,2,0,3,1]
        //Output: [5,7,2,3,2]

        // 5 = a0
        // 2 = a0 ^ a1
        // 0 = a0 ^ a1 ^ a3  = 2 ^ a3. how to find a3 then?
        // 2 ^ 0 = a3; [similar ones get cancelled out] in this way we can find a1,a2,a3...
        vector<int> ans(pref.size());
        ans[0] = pref[0];
        for(int i = 1; i < pref.size() ; i++){
            ans[i] = pref[i] ^ pref[i-1];
        }
        return ans;
    }
};