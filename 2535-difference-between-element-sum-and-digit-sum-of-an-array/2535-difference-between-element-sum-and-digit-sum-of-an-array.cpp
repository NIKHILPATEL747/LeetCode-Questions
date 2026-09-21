class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum1=0;
        int sum2=0;
        int x;
        for(int i=0;i<nums.size();i++)
        {
             int temp=nums[i];
            while(temp!=0)
            {  x=temp%10;
                sum2+=x;
                temp/=10;

            }
            sum1+=nums[i];

        }
         
              return abs(sum1-sum2);
        
    }
};