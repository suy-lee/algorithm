class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int tmp = 0;
        int m = matrix.size();

        // 상하반전
        for (int i = 0; i < m/2; i++) {
            for (int j = 0; j < m; j++) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[m-i-1][j];
                matrix[m-i-1][j] = tmp;
            }
        }

        // 대각선반전
        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
};
