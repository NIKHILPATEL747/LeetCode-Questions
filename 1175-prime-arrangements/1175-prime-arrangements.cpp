class Solution {
public:
    const int MOD = 1e9 + 7;

    // Function to check if a number is prime
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    
    long long factorial(int n) {
        long long res = 1;
        for (int i = 1; i <= n; i++) {
            res = (res * i) % MOD;
        }
        return res;
    }

    int numPrimeArrangements(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (isPrime(i)) count++;
        }
        int noncount = n - count;

        long long ans = (factorial(count) * factorial(noncount)) % MOD;
        return (int)ans;
    }
};