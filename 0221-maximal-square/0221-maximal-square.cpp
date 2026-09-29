class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        
        vector<vector<int>> mat1(m, vector<int>(n, 0));
        int side = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        mat1[i][j] = 1;
                    } else {
                        mat1[i][j] = 1 + min({mat1[i-1][j], mat1[i][j-1], mat1[i-1][j-1]});
                    }
                    side = max(side, mat1[i][j]);
                }
            }
        }
        
        return side * side;
    }
};
