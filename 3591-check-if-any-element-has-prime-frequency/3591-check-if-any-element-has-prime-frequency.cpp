class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int n : nums) {
            freq[n]++;
        }
        for (auto &p : freq) {
            if (isPrime(p.second)) return true;  // ✅ only need one prime frequency
        }
        return false;
    }
};