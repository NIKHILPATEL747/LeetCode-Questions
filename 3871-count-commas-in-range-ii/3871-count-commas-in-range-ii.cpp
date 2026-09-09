class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        string s = to_string(n);
        int len = s.length();

        for (int d = 4; d <= len; d++) {
            long long start = (long long)pow(10, d - 1);
            long long end = min(n, (long long)pow(10, d) - 1);
            if (end >= start) {
                long long count = end - start + 1;
                ans += count * ((d - 1) / 3);
            }
        }
        return ans;
    }
};
