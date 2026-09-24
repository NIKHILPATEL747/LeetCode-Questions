class Solution {
public:
    int smallestIndex(vector<int>& nums) {
      int l=nums.size();
 
      for(int i=0;i<l;i++)
      {   int temp=nums[i];
           int sum=0;
        while(temp!=0)
        {  
            int x=temp%10;
            sum+=x;
            temp=temp/10;
        }
        if(sum==i) return i;
      }
      return -1;
    }
};