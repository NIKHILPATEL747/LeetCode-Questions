class Solution {
public:
    bool checkDivisibility(int n) {
        long long p=1;
        long long sum=0;
        long long temp=n;
        while(temp!=0)
        { int rem=temp%10;
          sum+=rem;
          p*=rem;
          temp=temp/10;

        }
        if(n%(sum+p)==0) return true;
        return false;
        
    }
};