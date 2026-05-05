class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        // [start,end]
        vector<int> events(52,0);
        for(auto &it : ranges){
            events[it[0]]+=1;
            events[it[1]+1]-=1;
        }
        // 1 2 3 4 5 6 7
        // 1   0   0   -1
        // 1 1 1 1 1 1 0
        for(int i = 1; i < events.size(); i++){
            events[i]+=events[i-1];
        }
        for(int i = left; i <= right; i++){
            if(events[i] == 0) return false;
        }
        return true;
    }


};