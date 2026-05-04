class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
       vector<int> mp(1001,0);
        for (int i = 0; i < n; i++) {
            int st = trips[i][1];
            int en =trips[i][2];
            int pass = trips[i][0];
            mp[st]+=pass; // passengers hopped
            mp[en]-=pass;//passengers dropped
            if(mp[i] > capacity) return false;
        }
        for(int i = 1; i < mp.size() ; i++){
            mp[i]+=mp[i-1];
            if(mp[i] > capacity) return false;
        }
        return true;

    }
};