class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddCount = 0, evenCount = 0;
        for (int num : nums1) {
            if (num % 2 == 0) evenCount++;
            else oddCount++;
        }
        
        if (oddCount == 0 || evenCount == 0) return true;
       
        return true;
    }
};
