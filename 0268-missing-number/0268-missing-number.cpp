class Solution {
public:
    int missingNumber(vector<int>& nums) { 
        int n=nums.size();
     int i=0;
     while(i<n)
     {
        int crr_idx=nums[i];
        if(crr_idx==i||nums[i]==n) i++;
        else swap(nums[i],nums[crr_idx]);
     }
     for(int i=0;i<n;i++)
     {
        if(nums[i]!=i) return i;
     }
     return n;
     }

};