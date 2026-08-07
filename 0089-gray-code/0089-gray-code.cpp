class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int size = 1 << n; // total numbers = 2^n
        for (int i = 0; i < size; i++) {
            result.push_back(i ^ (i >> 1)); 
            // Gray code formula: binary ^ (binary >> 1)
        }
        return result;
    }
};
