class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int min_sum = -1;
        
        for (int i = 0; i < n; ++i) {
            int current_sum = 0;
            for (int j = i; j < n && (j - i + 1) <= r; ++j) {
                current_sum += nums[j];
                
                if ((j - i + 1) >= l && current_sum > 0) {
                    if (min_sum == -1 || current_sum < min_sum) {
                        min_sum = current_sum;
                    }
                }
            }
        }
        
        return min_sum;
    }
};