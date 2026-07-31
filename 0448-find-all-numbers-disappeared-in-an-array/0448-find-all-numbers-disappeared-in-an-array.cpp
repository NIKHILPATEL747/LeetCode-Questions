class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
           int i=0;
     while(i<n)
     {
        int crr_idx=nums[i]-1;
        if(crr_idx==i||nums[i]==nums[crr_idx]) i++;
        else swap(nums[i],nums[crr_idx]); 
     }
     vector<int>ans;
     for(int i=0;i<n;i++)
     {
        if(nums[i]!=i+1) ans.push_back(i+1);
     }
     return ans;
        
    }
};