class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m, n;
        int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

        m = grid.size();
        if (!m) return 0; // termination condition
        n = grid[0].size();

        int num_islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) { // traverse all cells
                if (grid[i][j] == '1') {
                    ++num_islands;
                    grid[i][j] = '0'; // mark as visited
                    queue<pair<int, int>> neighbors; // declare queue here
                    neighbors.push({i, j});

                    while (!neighbors.empty()) {
                        pair<int, int> it = neighbors.front();
                        neighbors.pop();
                        int row = it.first, col = it.second;

                        // see friends which are adjacent
                        if (row - 1 >= 0 && grid[row-1][col] == '1') {
                            // see if left friend is valid
                            neighbors.push({row-1, col});
                            grid[row-1][col] = '0'; // mark as visited
                        }
                        if (row + 1 <= m - 1 && grid[row+1][col] == '1') {
                            // see if right friend is valid
                            neighbors.push({row+1, col});
                            grid[row+1][col] = '0'; // mark as visited
                        }
                        if (col - 1 >= 0 && grid[row][col-1] == '1') {
                            // see if right friend is valid
                            neighbors.push({row, col-1});
                            grid[row][col-1] = '0'; // mark as visited
                        }
                        if (col + 1 <= n - 1 && grid[row][col+1] == '1') {
                            // see if right friend is valid
                            neighbors.push({row, col+1});
                            grid[row][col+1] = '0'; // mark as visited
                        }
                    }
                }
            }
        }

        return num_islands;
    }
};