

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 2) return points.size();
        
        int result = 0;
        
        for (int i = 0; i < points.size(); i++) {
            unordered_map<double, int> slopeCount;
            int duplicate = 1;
            int vertical = 0;
            int localMax = 0;
            
            for (int j = i + 1; j < points.size(); j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                if (dx == 0 && dy == 0) {
                    duplicate++;
                } else if (dx == 0) {
                    vertical++;
                } else {
                    double slope = (double)dy / dx;
                    slopeCount[slope]++;
                    localMax = max(localMax, slopeCount[slope]);
                }
                localMax = max(localMax, vertical);
            }
            
            result = max(result, localMax + duplicate);
        }
        
        return result;
    }
};
