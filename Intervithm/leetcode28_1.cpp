#include <iostream>
#include <string>

using namespace std;

class Solution {//这都可以，深入理解for过程
public:
    int strStr(string haystack, string needle) {
        //非KMP
        int a=haystack.size();
        int b=needle.size();
        if(b==0)
            return 0;
        else if(a<b||a==0)
            return -1;
        for(int i=0;i<a-b+1;i++)
        {
            int j=i;
//            for(j;j<i+b;j++)
//            {
//                if(haystack[j]!=needle[j-i])
//                    break;
//            }
            while(j<i+b)
            {
                if(haystack[j]!=needle[j-i])
                    break;
                j=j+1;
            }
            if(j==i+b)
                return i;
        }
        return -1;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
