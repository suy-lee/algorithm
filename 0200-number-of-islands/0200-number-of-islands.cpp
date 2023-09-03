class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        int m, n;
        
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();
        
        int numIslands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    numIslands++;
                    grid[i][j] = '0';

                    pair<int, int> cell;
                    queue<pair<int, int>> neighbors;
                    neighbors.push({i, j});

                    while (!neighbors.empty()) {
                        cell = neighbors.front();
                        neighbors.pop();

                        int r = cell.first;
                        int c = cell.second;

                        if (r - 1 >= 0 && grid[r-1][c] == '1') {
                            neighbors.push({r-1, c});
                            grid[r-1][c] = '0';
                        }

                        if (r + 1 < m && grid[r+1][c] == '1') {
                            neighbors.push({r+1, c});
                            grid[r+1][c] = '0';
                        }

                        if (c - 1 >= 0 && grid[r][c-1] == '1') {
                            neighbors.push({r, c-1});
                            grid[r][c-1] = '0';
                        }
                        
                        if (c + 1 < n && grid[r][c+1] == '1') {
                            neighbors.push({r, c+1});
                            grid[r][c+1] = '0';
                        }
                    }
                }
            }
        }

        return numIslands;
    }
};