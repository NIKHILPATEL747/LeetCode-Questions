class Solution {
public:
    int findDuplicate(vector<int>& nums) {
            int n=nums.size();
      int i=0;
     while(i<n)
     {
        int crr_idx=nums[i];
        if(nums[crr_idx]==nums[i]) return nums[i];
        else swap(nums[i],nums[crr_idx]);
     }
    
     return 0;
        
    }
};    