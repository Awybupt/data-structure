#include <iostream>

using namespace std;
#define Max 50

typedef struct{
    int i,j;//非零元素的行下标和列下表
    int num;//操作对象
}triple;

typedef struct{
    triple data[Max];
    int mu,nu,tu;
}matrix;

void inpput(matrix &q);

bool judgeand(matrix q,matrix p);

bool judgemult(matrix q,matrix p);

void aand(matrix p,matrix q,matrix &r);

void mullt(matrix p,matrix q,matrix &t);

void hangyouxian(matrix &q);

void lieyouxian(matrix &q);

void display(matrix p);

triple searh(matrix p,int x,int y);

int main()
{
    matrix A,B,C,D;
    //输入矩阵A，B
    cout<<"please input the information of A"<<endl;
    inpput(A);
    cout<<"please input the information of B"<<endl;
    inpput(B);

    if(judgeand(A,B))
    {
         aand(A,B,C);
         cout<<"A+B:";
         display(C);
    }
    else
    {
        cout<<"because the A.mu!=B.mu,so i couldn't calculate."<<endl;
    }

    if(judgemult(A,B))
    {
        mullt(A,B,D);
        cout<<"A*B";
        display(D);
    }
    else
    {
        cout<<"because the A.mu!=B.nu,so i couldn't calculate."<<endl;
    }
    return 0;
}

void mullt(matrix p,matrix q,matrix &t)
{
    hangyouxian(p);
    lieyouxian(q);
    triple ansp,anwq;
    int sun=0;
    int qw=1;
    for(int a=1;a<=p.mu;a++)//控制p行变化
    {
        for(int b=1;b<=q.nu;b++)//控制q列变化
        {
            for(int c=1;c<=p.nu;c++)
            {
                ansp=searh(p,a,c);
                anwq=searh(q,c,b);
                if(ansp.i==1&&anwq.i==1)
                {
                    sun=sun+p.data[ansp.num].num*q.data[anwq.num].num;
                }
            }
            if(sun!=0)
            {
                t.data[qw].i=a;
                t.data[qw].j=b;
                t.data[qw].num=sun;
                qw++;
            }
            sun=0;
        }
    }
    t.tu=qw-1;
}

void hangyouxian(matrix &q)
{
    triple tex;
    for(int a=1;a<q.tu;a++)
    {
        for(int b=1;b<q.tu;b++)
        {
           if(q.data[b].i>q.data[b+1].i)
           {
               tex.i=q.data[b].i;
               q.data[b].i=q.data[b+1].i;
               q.data[b+1].i=tex.i;

               tex.j=q.data[b].j;
               q.data[b].j=q.data[b+1].j;
               q.data[b+1].j=tex.j;

               tex.num=q.data[b].num;
               q.data[b].num=q.data[b+1].num;
               q.data[b+1].num=tex.num;
           }
        }
    }
}

void lieyouxian(matrix &q)
{
    triple tex;
    for(int a=1;a<q.tu;a++)
    {
        for(int b=1;b<q.tu;b++)
        {
           if(q.data[b].j>q.data[b+1].j)
           {
               tex.i=q.data[b].i;
               q.data[b].i=q.data[b+1].i;
               q.data[b+1].i=tex.i;

               tex.j=q.data[b].j;
               q.data[b].j=q.data[b+1].j;
               q.data[b+1].j=tex.j;

               tex.num=q.data[b].num;
               q.data[b].num=q.data[b+1].num;
               q.data[b+1].num=tex.num;
           }
        }
    }
}

triple searh(matrix p,int x,int y)
{
    triple wer;
    wer.i=0;
    wer.j=0;
    wer.num=0;
    for(int a=1;a<=p.tu;a++)
    {
        if(p.data[a].i==x&&p.data[a].j==y)
        {
            wer.i=1;
            wer.j=1;
            wer.num=a;
            return wer;
        }
    }
    return wer;
}

void display(matrix p)
{
    cout<<"the matrix is :"<<endl;
    for(int a=1;a<=p.tu;a++)
    {
        cout<<p.data[a].i<<"    ";
        cout<<p.data[a].j<<"    ";
        cout<<p.data[a].num<<endl;
    }
    cout<<"display function have finish perfectly!"<<endl;
}

void aand(matrix p,matrix q,matrix &r)
{
    for(int a=1;a<=p.tu;a++)
    {
        r.data[a].i=p.data[a].i;
        r.data[a].j=p.data[a].j;
        r.data[a].num=p.data[a].num;
    }
    r.mu=p.mu;
    r.nu=p.nu;
    r.tu=p.tu;
    int yu=0;
    for(int b=1;b<=q.tu;b++)
    {
        for(int c=1;c<=p.tu;c++)
        {
            if(q.data[b].i==r.data[c].i&&q.data[b].j==r.data[c].j)
            {
                r.data[c].num=r.data[c].num+q.data[b].num;
                yu=1;
            }
        }
        if(yu==0)
        {
            r.tu++;
            r.data[r.tu].num=q.data[b].num;
            r.data[r.tu].i=q.data[b].i;
            r.data[r.tu].j=q.data[b].j;
        }
        yu=0;
    }
}

bool judgeand(matrix q,matrix p)
{
    if(q.mu==p.mu&&q.nu==p.nu)
        return true;
    else
        return false;
}

bool judgemult(matrix q,matrix p)
{
    if(q.nu==p.mu)
        return true;
    else
        return false;
}

void inpput(matrix &q)
{
    int a=0,b=0,c=0;

    int d,f,g;
    cin>>d;
    while(d!=-1)
    {
        c++;
        q.data[c].i=d;
        cin>>f;
        q.data[c].j=f;
        cin>>g;
        q.data[c].num=g;
        cin>>d;
    }
    q.tu=c;
    for(int h=1;h<=c;h++)
    {
        if(q.data[h].i>a)
            a=q.data[h].i;
    }
    q.mu=a;
    for(int m=1;m<=c;m++)
    {
        if(q.data[m].j>b)
            b=q.data[m].j;
    }
    q.nu=b;
}

