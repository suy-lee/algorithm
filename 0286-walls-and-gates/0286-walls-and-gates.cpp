#define GATE 0
#define WALL -1
#define INF 2147483647

// BFS employed to solve this problem since it's all about shortest path problem
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        int m = rooms.size();
        int n = rooms[0].size();

        queue<pair<int, int>> q; // to push gate coord

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == GATE) {
                    q.push(make_pair(i, j)); // push gate to calculate empty rooms's distance from gate -- backwards.
                }
            }
        }

        while (!q.empty()) { // for every gates
            pair<int, int> item = q.front();
            q.pop();

            int r = item.first;
            int c = item.second;

            for (int i = 0; i < 4; i++) { // search every direction to find empty room
                int new_r = r + dir[i][0];
                int new_c = c + dir[i][1];
                
                if (new_r < 0 || new_c < 0 || new_r >= m || new_c >= n ||
                    rooms[new_r][new_c] != INF)
                    //rooms[new_r][new_c] == WALL || rooms[new_r][new_c] == GATE)
                    //!problem: above code can't filter 'already value assigned' cell
                    continue; // terminate for-loop
                
                rooms[new_r][new_c] = rooms[r][c] + 1;
                q.push(make_pair(new_r, new_c));
            }
        }

    }
};