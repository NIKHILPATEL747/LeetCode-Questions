class Solution:
    def openLock(self, deadends: list[str], target: str) -> int:
        dead_set = set(deadends)
        
        if '0000' in dead_set:
            return -1
        
        if target == '0000':
            return 0
            
        queue = deque([('0000', 0)])
        visit = {'0000'}
        
        while queue:
            curr, move = queue.popleft()
            
            if curr == target:
                return move
                
            for wheel in range(4):
                digit = int(curr[wheel])
                for rot in (-1, 1):
                    newdigit = (digit + rot) % 10
                    newstate = curr[:wheel] + str(newdigit) + curr[wheel+1:]
                    
                    if newstate not in dead_set and newstate not in visit:
                        visit.add(newstate)
                        queue.append((newstate, move + 1))
                        
        return -1