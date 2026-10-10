class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        int maxDiff = 0;
        vector<int> freq(100001, 0); // since nums[i] ≤ 1e5
        
        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            freq[d]++;
            maxDiff = max(maxDiff, d);
        }
        
        long long k = (long long)k1 + k2;
        
        for (int d = maxDiff; d > 0 && k > 0; d--) {
            if (freq[d] == 0) continue;
            int move = min((long long)freq[d], k);
            freq[d] -= move;
            freq[d-1] += move;
            k -= move;
        }
        
        long long ans = 0;
        for (long long d = 0; d <= maxDiff; d++) {
            if (freq[d] > 0) {
                ans += (long long)d * d * freq[d];
            }
        }
        
        return ans;
    }
};
