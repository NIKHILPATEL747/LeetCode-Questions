class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<pair<int,int>> directions = {
            {-1,0}, {1,0}, {0,-1}, {0,1}
        };

        int maxArea = 0;

        function<int(int,int)> dfs = [&](int r, int c) {
            if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0)
                return 0;

            grid[r][c] = 0;

            int area = 1;

            for (auto [dr, dc] : directions) {
                area += dfs(r + dr, c + dc);
            }

            return area;
        };

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(i, j));
                }
            }
        }

        return maxArea;
    }
};