/*
- find number of components
- if u,v lie in different component --> no edge --> false
- all nodes in one component will have path to reach each other
- so, we can simply store the nodes-->comp.number

*/

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> comp(n,-1);
        int cid = 0;
        comp[0] = cid; // assigning 0th node to 0th component 
        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i-1] > maxDiff) cid++;
            comp[i] = cid; 
        }
        vector<bool> res;
        for(auto &q : queries){
            int u = q[0];
            int v = q[1];
            res.push_back(comp[u]==comp[v]);
        }
        return res;
    }
};