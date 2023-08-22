class Solution {
    int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    int m, n;
    vector<vector<int>> h;

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        // Check if input is empty
        if (m == 0 || n == 0) return h;

        h = heights;

        queue<pair<int, int>> aQ;
        queue<pair<int, int>> pQ;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) pQ.push(make_pair(i, j));
                if (i == m-1 || j == n-1) aQ.push(make_pair(i, j));
            }
        }

        vector<vector<bool>> pB(m, vector<bool> (n, false)); // init 2d vector
        vector<vector<bool>> aB(m, vector<bool> (n, false));

        pB = bfs(pQ); // for pacific ocean
        aB = bfs(aQ); // for atlantic ocean

        // wrap-up
        vector<vector<int>> result;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pB[i][j] && aB[i][j]) result.push_back({i, j});
            }
        }

        return result;
    }

    // Get result!
    vector<vector<bool>> bfs(queue<pair<int, int>> q) {
        pair<int, int> cell;
        vector<vector<bool>> b_arr(m, vector<bool> (n, false));

        while (!q.empty()) {
            cell = q.front();
            q.pop();
            
            int row = cell.first;
            int col = cell.second;

            // Mark this cell reachable
            b_arr[row][col] = true;

            for (int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];
                
                // Termination Cond #1. Out of Range
                if (r < 0 || c < 0 || r >= m || c >= n) 
                    continue;

                if (b_arr[r][c] == true)
                    continue;

                // Termination Cond #2. New Cell is Lower than Current Cell
                if (h[row][col] > h[r][c])
                    continue;
                
                // Make mark and proceed
                q.push(make_pair(r, c));
            }
        }

        return b_arr;
    }
};