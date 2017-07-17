/*楼梯共有m级，可以跨一级或者两级，有多少种走法
从一级到一级有0种走法
这是一个递归问题
f(n)=f(n-1)+f(n-2)
*/
class floor{
    int m;//楼梯数
    int solve(int);
}
int floor::solve(int num)
{
    if(num==1||num=2)
        return 0;
    else 
        return solve(n-1)+solve(n-2);
}
