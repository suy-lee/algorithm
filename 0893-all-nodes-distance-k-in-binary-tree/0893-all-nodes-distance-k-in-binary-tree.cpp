/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    // directed acyclic graph to undirected acyclic graph
    void buildGraph(TreeNode *root, unordered_map<int, vector<int>> &graph) {
        if (root->left != NULL) {
            graph[root->val].push_back(root->left->val); // one-direction
            graph[root->left->val].push_back(root->val); // another-direction
            buildGraph(root->left, graph);
        }

        if (root->right != NULL) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            buildGraph(root->right, graph);
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Initialize return value for empty input
        if (k == 0)
            return {target->val};

        // Init spaces
        unordered_map<int, vector<int>> graph;
        unordered_map<int, bool> visited;
        vector<int> res;
        queue<int> q;
        int cnt = 0; // accumulate to calculate current level to match distance K

        // Build graph
        buildGraph(root, graph);

        // Push target to start bfs with, in this case it would be target node's value
        // since we'll gonna start from that node
        q.push(target->val);

        // Since q is initially empty, the first q.front() in bfs will
        // exactly start from above target->val, which has pushed right now.

        // Do bfs
        while (!q.empty()) {
            int sz = q.size();
            
            for (int i = 0; i < sz; i++) {
                
                int curr = q.front();
                q.pop();
                visited[curr] = true;

                for (int x : graph[curr]) { // for all adjacent nodes of 'curr' in graph
                    if (!visited[x]) // if not visited
                        q.push(x);
                }
            }

            cnt++;

            // If we reached the K'th layer, push the layer into res vector and break bfs
            if (cnt == k) {
                while (!q.empty()) {
                    res.push_back(q.front());
                    q.pop();
                }

                break;
            }
        }

        return res;
    }
};