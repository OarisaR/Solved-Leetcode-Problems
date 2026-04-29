class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // safe nodes = all outgoing edges must lead to terminal node [no
        // OUTGOING EDGES] aka another safe node
        int n = graph.size();
        vector<vector<int>> reverse_graph(n);
        vector<int> outdeg(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                // currently. i ---> ngbrs
                // changing ngbr--->i
                int neighbor = graph[i][j];
                reverse_graph[neighbor].push_back(i);
                outdeg[i]++; // count outgoing edges of i
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {

            if (outdeg[i] == 0)
                q.push(i);
        }
        vector<bool> safe(n, false);
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            safe[temp] = true;
            for (int u : reverse_graph[temp]) {
                outdeg[u]--;
                if (outdeg[u] == 0)
                    q.push(u);
            }
        }
        // in asc order
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (safe[i])
                result.push_back(i);
        }
        return result;
    }
};