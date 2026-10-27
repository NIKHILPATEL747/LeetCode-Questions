class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        queue<int> q;
        vector<bool> visited(n, false);
        
        q.push(start);
        visited[start] = true;
        
        int distance = 0;
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                
                if (nums[curr] == target) {
                    return distance;
                }
                
                int left = curr - 1;
                if (left >= 0 && !visited[left]) {
                    visited[left] = true;
                    q.push(left);
                }
                
                int right = curr + 1;
                if (right < n && !visited[right]) {
                    visited[right] = true;
                    q.push(right);
                }
            }
            distance++;
        }
        
        return -1;
    }
};