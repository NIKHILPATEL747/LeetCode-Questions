class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                ans.push_back(nums[i]);
            }
            else{
                ans.push_back(nums[i]+ans[i-1]);
            }
        }
        return ans;

    }
};