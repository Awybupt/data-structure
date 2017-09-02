class Solution {
public:
    int reverse(int x) {
        const int max = 0x7fffffff;  //int最大值  
        const int min = 0x80000000;  //int最小值  
        long long ans = 0; 
        bool sig=true;
        if(x<0)
        {
            sig=not sig;
            x=0-x;
        }
        while(x>0)
        {
            int t=x%10;
            ans=ans*10+t;
            x=x/10;
        }
        if(ans>=max||ans<min)
            return 0;
        if(sig)
            return ans;
        else
            return 0-ans;
    }
};
