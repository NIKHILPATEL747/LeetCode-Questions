class Solution {
public:
    int smallestNumber(int n, int t) {
        bool flag=true;
        
        while(flag)
        {
            int temp=n;
            int x;
            int p=1;
            while(temp!=0)
            { x=temp%10;
            p*=x;
            temp/=10;
                
            }
            if(p%t==0)
            { flag=false;
                return n;
            }
            n++;
        }
        return 0;
    }
};