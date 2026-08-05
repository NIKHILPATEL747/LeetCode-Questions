class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxlen=0;
        int j=0;
        int i=0;
        int zcount=0;
       for (i=0;i<n;i++)
       { if(nums[i]==0) zcount++;
        while(zcount>k)
        { if(nums[j]==0){
            zcount--;
            j++;
        }
        else j++;
        }
        int len=i-j+1;
        maxlen=max(maxlen,len);
        
       }
       return maxlen;
        
    }
};