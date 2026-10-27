class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int min1=INT_MAX;
    for(int i=0;i<nums.size();i++)
    {
         if(nums[i]==target)
             {
                int ans=abs(i-start);
              min1=min(min1,ans);
             }
    }
       return min1;
    }
};