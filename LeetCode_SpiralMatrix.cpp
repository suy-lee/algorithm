class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int max_m = matrix[0].size(), m = matrix[0].size();
        int max_n = matrix.size(), n = matrix.size();
        int min_m = 0;
        int min_n = 0;
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dirsel = 0;
        int cnt = 0, i = 0, j = 0, prev_i = 0, prev_j = 0;
        vector<int> sol;

        while (cnt < m * n) {
            if (dirsel == 0) { // right
                for (j = min_m; j < max_m; ) {
                    sol.push_back(matrix[i][j]);
                    prev_i = i, prev_j = j;   
                    i += dir[dirsel][0], j += dir[dirsel][1];
                    cnt++;
                }    
                i = prev_i, j = prev_j; // restore
                min_n++;
            }
            else if (dirsel == 1) { // down
                for (i = min_n; i < max_n; ) {
                    sol.push_back(matrix[i][j]);
                    prev_i = i, prev_j = j;
                    i += dir[dirsel][0], j += dir[dirsel][1];
                    cnt++;
                }
                i = prev_i, j = prev_j; // restore
                max_m--;
            }
            else if (dirsel == 2) { // left
                for (j = max_m-1; j >= min_m; ) {
                    sol.push_back(matrix[i][j]);
                    prev_i = i, prev_j = j;
                    i += dir[dirsel][0], j += dir[dirsel][1];
                    cnt++;
                }
                i = prev_i, j = prev_j; // restore
                max_n--;
            }
            else {
                for (i = max_n-1; i >= min_n; ) {
                    sol.push_back(matrix[i][j]);
                    prev_i = i, prev_j = j;
                    i += dir[dirsel][0], j += dir[dirsel][1];
                    cnt++;
                }
                i = prev_i, j = prev_j; // restore
                min_m++;
            }
            dirsel = (dirsel + 1) % 4;
        }

        return sol;
    }
};
