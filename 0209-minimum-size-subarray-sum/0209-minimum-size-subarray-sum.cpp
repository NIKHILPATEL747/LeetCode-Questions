class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int sum=0;
        int len;
        int minlen=n+1;
        
        while(j<n)
        {
            sum+=nums[j];
            while(sum>=target)
            { len=j-i+1;
                sum-=nums[i];
                minlen=min(len,minlen);
                i++;

            }
            j++;
        }
        if(minlen==n+1) return 0;

        return minlen;
    }
};