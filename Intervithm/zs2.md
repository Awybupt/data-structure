```cpp
/*
n = 3，所有的合法序列

((()))  (()()) (())() ()(()) ()()()     

思路

针对一个长度为2n的合法排列，第1到2n个位置都满足如下规则

1
左括号的个数≥右括号的个数
所以，我们就可以按照这个规则去打印括号

假设在位置k我们还剩余left个左括号和right个右括号

如果left和right均为零，则说明我们已经完成一个合法排列，可以将其打印出来
如果left>0，打印左括号
如果right>0 并且 right>left 打印右括号

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void generate(const int ln,const int rn, const string &sb,vector<string>& list)
{
    if(ln == 0 && rn == 0)
        list.push_back(sb);
    if(ln>0)
        generate(ln-1,rn,sb+"(",list);
    if(rn>0 && ln<rn)
        generate(ln,rn-1,sb+")",list);
};
int main()
{
    int n=0;
    cin>>n;
    vector<string> list;
    generate(n,n,"",list);
    for (const auto &i : list) {
        cout<< i <<endl;
    }
    return 0;
}
```
