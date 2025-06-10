class Solution {
    // 有cycle return true
    bool dfs(int node, vector<vector<int>>&adj, vector<bool>&visited, vector<bool>&onPath){
        if (onPath[node]) return true; // 發現環
        if (visited[node]) return false;

        visited[node] = true;
        onPath[node] = true;
        bool cycle = false;
        for (int nei = 0; nei < adj[node].size(); ++nei) {
            if(dfs(adj[node][nei], adj, visited, onPath))
                return true;
        }
        onPath[node] = false;
        return cycle;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> onPath(numCourses, false);
        for (int i = 0;i<numCourses;i++) {
            if(!visited[i]){
                if (dfs(i, adj, visited, onPath))
                    return false;
            }
        }
        return true;
    }
};
