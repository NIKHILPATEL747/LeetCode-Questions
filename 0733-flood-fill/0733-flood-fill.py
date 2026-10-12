class Solution:
    def floodFill(self, image: list[list[int]], sr: int, sc: int, color: int) -> list[list[int]]:
        rows=len(image)
        cols=len(image[0])
        original=image[sr][sc]
        if original==color:
            return image
        queue=deque()
        queue.append((sr,sc))
        image[sr][sc]=color
        direc=[(-1,0),(1,0),(0,1),(0,-1)]
        while queue:
            r,c=queue.popleft()
            for dr,dc in direc:
                nr=r+dr
                nc=c+dc
                if(0<=nr<rows and 0<=nc<cols and image[nr][nc]==original):
                    image[nr][nc]=color
                    queue.append((nr,nc))
        return image