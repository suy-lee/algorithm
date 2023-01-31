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
        int solcnt = m * n;
        vector<int> sol;

        while (cnt < m * n) {
            //printf("i=%d, j=%d, max_m=%d, max_n=%d\n", i, j, max_m, max_n);
            if (dirsel == 0) { // right
                for (j = min_m; j < max_m; ) {
                    sol.push_back(matrix[i][j]);
                    //printf("right: (%d, %d)\n", i, j);
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
                    //printf("down: (%d, %d)\n", i, j);
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
                    //printf("left: (%d, %d)\n", i, j);
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
                    //printf("up: (%d, %d)\n", i, j);
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
