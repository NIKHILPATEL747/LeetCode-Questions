class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            int revPos = 26 - (s[i] - 'a');
            int strPos = i + 1; 
            result += revPos * strPos;
        }
        
        return result;
    }
};
