class Solution {//栈无元素时不能抛出栈顶元素//教训！！！！！！！！！！
public:
    bool isValid(string s) {
        stack<char> mem;
        mem.push('a');
        int ssize=s.size();
        for(int i=0;i<ssize;i++)
        {
            if(isdouble(mem.top(),s[i]))
                mem.pop();
            else
                mem.push(s[i]);
        }
        if(mem.top()=='a')
            return true;
        else
            return false;
    }
    bool isdouble(char s,char b)
    {

        if(s=='('&&b==')')
            return true;
        else if(s=='['&&b==']')
            return true;
        else if(s=='{'&&b=='}')
            return true;
        else
            return false;
    }

};
