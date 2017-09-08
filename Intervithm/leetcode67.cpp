#include <iostream>
#include <string>
using namespace std;
//class Solution {
//public:
//    string addBinary(string a, string b) {
//        int c=a.size();
//        int d=b.size();
//        string ans;
//        int memo=0;
//        int max;
//        d>c?max=d:max=c;
//        int e,f,g=0;//当前位数
//
//        for(int i=0;i<max;i++)
//        {
//
//            if(i>=c) e=0;
//            else e=a[i]-'0';
//            if(i>=d) f=0;
//            else f=b[i]-'0';
//            switch(f+e+g) {
//                case 0:
//                    ans='0'+ans;
//                    g=0;
//                    break;
//                case 1:
//                    ans='1'+ans;
//                    g=0;
//                    break;
//                case 2:
//                    ans='0'+ans;
//                    g=1;
//                    break;
//                case 3:
//                    ans='1'+ans;
//                    g=1;
//            }
//        }
//        if(g==1)
//            ans='1'+ans;
//        return ans;
//    }
//};
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string s = "";

        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i--] - '0' : 0;
            c += j >= 0 ? b[j--] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }

        return s;
    }
};
int main() {
    string a,b,c;
    cin>>a;
    cin>>b;
    Solution s;

    cout << s.addBinary(a,b)<< std::endl;
    return 0;
}
