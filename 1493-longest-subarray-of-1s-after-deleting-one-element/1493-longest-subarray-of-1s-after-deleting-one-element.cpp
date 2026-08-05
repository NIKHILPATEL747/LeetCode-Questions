class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int n=nums.size();
        int maxlen=0;
        int j=0;
        int i=0;
        int zcount=0;
        int k=1;
        
     for (i=0;i<n;i++)
       { if(nums[i]==0) zcount++;
        while(zcount>k)
        { if(nums[j]==0){
            zcount--;
            j++;
        }
        else j++;
        }
        int len=i-j;
        maxlen=max(maxlen,len);
        
       }
       return maxlen;
        

        
    }
};