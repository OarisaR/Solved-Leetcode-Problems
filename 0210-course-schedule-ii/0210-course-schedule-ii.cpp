class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        // 0-->[1,2]
        for (int i = 0; i < prerequisites.size(); i++) {
            // edge : first do  [i][1] --> then [i][0]; like a prereq course
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        // KAHNS ALGO -
        // to repeatedly remove nodes with in-degree 0. If you can remove all
        // nodes, no cycle exists.
        vector<int> indeg(numCourses);
        // Indegree of a node = number of incoming edges
        for (int i = 0; i < prerequisites.size(); i++) {

            indeg[prerequisites[i][0]]++;
        }
        queue<int> q;
        // pushing all nodes initially with 0 indegree
        for (int i = 0; i < numCourses; i++) {

            if (indeg[i] == 0)
                q.push(i);
        }
        vector<int> top_order;
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            top_order.push_back(temp);
            for (int u : adj[temp]) {
                indeg[u]--;
                if (indeg[u] == 0)
                    q.push(u);
            }
        }
        if (top_order.size() != numCourses)
            return {};
        return top_order;
    }
};