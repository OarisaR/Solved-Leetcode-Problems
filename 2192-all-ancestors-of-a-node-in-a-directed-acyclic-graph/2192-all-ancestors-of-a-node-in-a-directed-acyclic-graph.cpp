class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> indeg(n);
        for (int i = 0; i < edges.size(); i++) {
            indeg[edges[i][1]]++; // u-->v
        }
        queue<int> q;
        vector<set<int>> ans(
            n); // taking set as there may be nodes having same ancestors
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            for (int u : adj[temp]) {
                // u is ngbr or child of temp
                ans[u].insert(temp); // adding direct parent

                // but all parents of temp is also ancestors of u!
                ans[u].insert(ans[temp].begin(), ans[temp].end());
                indeg[u]--;
                if (indeg[u] == 0)
                    q.push(u);
            }
        }
        vector<vector<int>> v;
        for (int i = 0; i < n; i++) {
            vector<int> temp(ans[i].begin(), ans[i].end());
            v.push_back(temp);
        }
        return v;
    }
};