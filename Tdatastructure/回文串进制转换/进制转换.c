#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#define siz 100
struct stak{
    int *base;
    int *top;
    int stacksize;//粘当前的存储空间
};

int main()
{
    struct stak s;
    s.base=(int*)malloc(siz*sizeof(int));
    s.stacksize=siz;
    s.top=s.base;//申请栈空间

    char bbs;
    scanf("%c",&bbs);
    while(bbs!='#')
    {
        *s.top=bbs-'0';
        if(*s.top>1)
        {
            printf("error");
            return 0;
        }
        s.top++;
        scanf("%c",&bbs);//执行完最后一遍后s.top并没有被赋值
    }//完成进站操作
    s.top--;
    int num=1,sum=0;
    while(s.base!=s.top)
    {
        sum=sum+(*s.top)*num;
        num=num*2;;
        free(s.top);
        s.top--;
    }
    sum=sum+(*s.base)*num;
    printf("%o\n",sum);
    return 0;
}

