class Solution {
public:
    // Topological sort, BFS, Kahn's Algorithm
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        vector<int> adj[numCourses+1];
        queue<int> q;
        vector<int> indegree(numCourses, 0);

        // Store directed graph
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        // Calc indegree
        for (int i = 0; i < prerequisites.size(); i++) {
            indegree[prerequisites[i][0]]++; 
        }
        
        // If indegree is 0 push that into queue
        for (int i = 0; i < indegree.size(); i++) {
             if (indegree[i] == 0) q.push(i);
        }

        int count = 0;
        
        // bfs
        while (!q.empty()) {
            int v = q.front(); 
            q.pop();
            count++;

            for(auto i : adj[v]){
                indegree[i]--;
                if (indegree[i] == 0) q.push(i);
            }     
        }

        if (count == numCourses) return true;
        else return false;
    }
};