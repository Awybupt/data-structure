```cpp
#include <iostream>
#include <string>

/* 招行测试
 * 给出一个非空的字符串，判断这个字符串是否是由它的一个子串进行多次首尾拼接构成的。
例如，"abcabcabc"满足条件，因为它是由"abc"首尾拼接而成的，而"abcab"则不满足条件。
输入描述:

非空字符
输出描述:

如果字符串满足上述条件，则输出最长的满足条件的的子串；如果不满足条件，则输出false。
输入例子1:

abcabc
输出例子1:

abc
*/
using namespace std;

int main()
{
    string str;
    cin>>str;
    int lenstr = int(str.size());
    bool isOk = false;
    for (int i = lenstr/2; i >= 1; --i)
    {
        string tmp = str.substr(0, i);
        string res;
        for (int j = 0; j < lenstr / i; ++j)
            res += tmp;
        if (res == str)
        {
            cout << tmp << endl;
            isOk = true;
            break;
        }
    }
    if (!isOk)
        cout << "false" << endl;
    return 0;
}
```
