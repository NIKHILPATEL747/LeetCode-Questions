class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        
        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        int count = 0;
        
        function<void(int,int)> dfs = [&](int r, int c) {
            if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') return;
            grid[r][c] = '0'; 
            for (auto [dr, dc] : directions) {
                dfs(r + dr, c + dc);
            }
        };
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(i, j);
                }
            }
        }
        
        return count;
    }
};
