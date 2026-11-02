"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        visited={}
        visited[node]=Node(node.val)
        queue=deque([node])
        while queue:
            curr=queue.popleft()
            for ngh in curr.neighbors:
                if ngh not in visited:
                    visited[ngh]=Node(ngh.val)
                    queue.append(ngh)
                visited[curr].neighbors.append(visited[ngh])
        return visited[node]