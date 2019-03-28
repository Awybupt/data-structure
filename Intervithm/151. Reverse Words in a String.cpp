class Solution {
public:
    string reverseWords(string s) {
        int sSize=s.size();
        
        //reverse origin string
        for (int i=0,j=sSize-1;i<j;i++,j--)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }

        //reverse word char sequence
        for (int i=0,j=0;i<sSize;j=(++i))
        {
            if (s[i]!=' ')
            {
                for (;i<sSize&&s[i]!=' ';i++);
                
                for (int m=j,n=i-1;m<n;m++,n--)
                {
                    char temp = s[m];
                    s[m]=s[n];
                    s[n]=temp;
                }
            }
        }
        
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        for (int i=0;i<s.size();i++)
            if (s[i]==' '&&s[i+1]==' ')
            {   
                s.erase(i,1);
                i-=1;
            }
        return s;
    }
};
