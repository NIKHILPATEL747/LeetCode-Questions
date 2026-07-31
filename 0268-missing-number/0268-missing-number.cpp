class Solution {
public:
    int missingNumber(vector<int>& nums) { 
        int n=nums.size();
     vector<int>check (n+1,0);
     for(int i=0;i<n;i++)
     { int ele=nums[i];
       check[ele]=1;

     }
     for(int i=0;i<n+1;i++)
     {
        if(check[i]!=1)
        {
            return i;
        }
     }
     return 0;
     }

};