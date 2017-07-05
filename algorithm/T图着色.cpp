#include <iostream>
#include <fstream>

using namespace std;

const int N = 42;  //图的顶点数
const int M = 6;   //色彩数


class Color
{
    friend int mColoring(int, int, int **);//着色函数
    private:
        bool Ok(int k);//判断是否可以着色
        void Backtrack(int t);//逆向寻找着色路径
        int n,      //图的顶点数
            m,      //可用的颜色数
            **a,    //图的邻接矩阵
            *x;     //当前解
        long sum;   //当前已找到的可m着色方案数
};
void Color::Backtrack(int t)
{
    if (t>n)
    {
        sum++;
        for (int i=1; i<=n; i++)
        cout << x[i] << " ";
        cout << endl;
     goto part;
    }
    else
    {
        for (int i=1;i<=m;i++) {
            x[t]=i;
            if (Ok(t))
                Backtrack(t+1);
        }
    }
part:t++;
}

bool Color::Ok(int k)// 检查颜色可用性
{
    for (int j=1;j<=n;j++)
    {
        if ((a[k][j]==1)&&(x[j]==x[k])) //相邻且颜色相同
        {
            return false;
        }
    }
    return true;
}


int mColoring(int n,int m,int **a)
{
    Color X;

    //初始化X
    X.n = n;
    X.m = m;
    X.a = a;
    X.sum = 0;
    int *p = new int[n+1];
    for(int i=0; i<=n; i++)
    {
        p[i] = 0;
    }
    X.x = p;
    X.Backtrack(1);
    delete []p;
    return X.sum;
}

int main()
{
    int **a = new int *[N+1];
    for(int i=1;i<=N;i++)
    {
        a[i] = new int[N+1];
    }

    cout<<"邻接矩阵:"<<endl;
    ifstream fin("tu1.txt");
    double temp;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            fin>>temp;
            if(temp>=99990)
                a[i][j]=0;
            else
                a[i][j]=1;
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    fin.close();

    cout<<"着色方案如下："<<endl;
    cout<<"当m="<<M<<"时，图G的可行着色方案数目为："<<mColoring(N,M,a)<<endl;
 for(int i=1;i<=N;i++)
    {
        delete[] a[i];
    }
    delete []a;

}
