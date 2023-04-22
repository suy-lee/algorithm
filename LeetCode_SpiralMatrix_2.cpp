class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = matrix.size();
        int n = matrix[0].size();
        int min_m = 0, max_m = m, min_n = 0, max_n = n;
        int i = 0, j = 0;
        int cur_dir = 0;
        vector<int> res;

        int cnt = 0;
        while (cnt < m * n) {
            while (i >= min_m && j >= min_n && i < max_m && j < max_n) {
                res.push_back(matrix[i][j]);
                i += dir[cur_dir][0]; j += dir[cur_dir][1];
                cnt++;
            }
            
            switch (cur_dir) {
                case 0:
                    j -= 1; // *** restore
                    min_m += 1;
                    break;
                case 1:
                    i -= 1;
                    max_n -= 1;
                    break;
                case 2:
                    j += 1;
                    max_m -= 1;
                    break;
                case 3:
                    i += 1;
                    min_n += 1;
                    break;
            }

            cur_dir = (cur_dir + 1) % 4;
            i += dir[cur_dir][0]; j += dir[cur_dir][1];
        }

        return res;
    }
};
