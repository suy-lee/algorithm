class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // BFS approach
        vector<int> adj[numCourses];
        queue<int> q;
        vector<int> indegree(numCourses, 0);

        // Store adj node
         for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // Calc indegree u -> v
        for(int i = 0; i < prerequisites.size(); i++){
            indegree[prerequisites[i][0]]++;
        }

        // Push node which has indegree of 0
        for(int i = 0; i< indegree.size(); i++){
            if (indegree[i] == 0) q.push(i);
        }

        vector<int>result;

        // Simple BFS and keep storing indegree values equal to 0 into result vector
        while (!q.empty()){
           int v = q.front();
           q.pop();
   
           for(auto it : adj[v]){ // for all adjacent nodes
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
            result.emplace_back(v);
        }

        // Check case
        if (result.size() != numCourses)
            result.clear();

        return result;
    }
};