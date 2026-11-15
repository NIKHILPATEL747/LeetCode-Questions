class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int prefix_sum = 0;
        int even = 1; 
        int odd = 0;

        for (int num : arr) {
            prefix_sum += num;
            if (prefix_sum % 2 == 1) {
                ans = (ans + even) % MOD;
                odd++;
            } else {
                ans = (ans + odd) % MOD;
                even++;
            }
        }

        return ans;
    }
};