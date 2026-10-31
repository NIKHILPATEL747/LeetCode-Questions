class Solution:
    def orangesRotting(self, grid: list[list[int]]) -> int:
        from collections import deque
        
        m = len(grid)
        n = len(grid[0])
        
        queue = deque()
        fresh = 0
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    queue.append((i, j))
                elif grid[i][j] == 1:
                    fresh += 1
                    
        if fresh == 0:
            return 0
            
        minutes = 0
        direc = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        while queue and fresh > 0:
            rotted_any = False
            for _ in range(len(queue)):
                r, c = queue.popleft()
                for dr, dc in direc:
                    nr = r + dr
                    nc = c + dc
                    if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == 1:
                        grid[nr][nc] = 2
                        queue.append((nr, nc))
                        fresh -= 1
                        rotted_any = True
            
            if rotted_any:
                minutes += 1
                
        return minutes if fresh == 0 else -1