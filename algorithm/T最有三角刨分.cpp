//3d5 凸多边形最优三角剖分
//#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

double rad(double l){
	return l*3.14/180.0;
}

const double EARTH_RADIUS=6378.137;
double dis(double radlat1,double radlat2,double radlog1,double radlog2);

int N ;//凸多边形边数+1
double weight[28][28];//凸多边形的权

double MinWeightTriangulation(int n,double **t,int **s);

void Traceback(int i,int j,int **s);//构造最优解

double Weight(int a,int b,int c);//权函数

int main()
{
    cin>>N;
    if(N==21)
    {
       double jing1[20]={102.872,102.879,102.895,102.895,102.863,102.768,102.736,102.719,102.678,102.677,102.676,102.675,102.675,102.675,102.675,102.676,102.686,102.704,102.74,102.746};
	   double wei1[20]={25.01466,25.024444,25.050191,25.095,25.09831,25.10243,25.10088,25.096666,25.05902,25.05719,25.05218,25.03436,25.01318,25.00996,24.99597,24.99248,24.98032,24.97184,24.95721,24.9555};
    for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<N-1;j++)
        {

            weight[i][j]=dis(wei1[i],wei1[j],jing1[i],jing1[j]);
        }
    }
    }
    else
    {
       double jing1[28]={102.746,102.749,102.763,102.769,102.77,102.77,102.769,102.764,102.754,102.744,102.74,102.729,102.718,102.714,102.704,102.695,102.687,102.685,102.682,102.681,102.682,102.686,102.689,102.704,102.707,102.709,102.714,102.732};
	   double wei1[28]={24.98604,24.988197,25.0001,25.01036,25.01896,25.027222,25.033055,25.04446,25.05378,25.05965,25.06162,25.06275,25.06268,25.061944,25.05773,25.05141,25.04281,25.038284,25.03012,25.0252,25.01405,25.005124,25.00074,24.98862,24.9864,24.98496,24.9832,24.98221};
     for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<N-1;j++)
        {
            weight[i][j]=dis(wei1[i],wei1[j],jing1[i],jing1[j]);
        }
    }
    }
	int **s = new int *[N];
    double **t = new double *[N];
    for(int i=0;i<N;i++)
    {
        s[i] = new int[N];
        t[i] = new double[N];
    }
	cout<<"此多边形的最优三角剖分值为："<<std::fixed <<MinWeightTriangulation(N-1,t,s)<<endl;
    cout<<"最优三角剖分结构为："<<endl;
    Traceback(1,N-2,s); //s[i][j]记录了Vi-1和Vj构成三角形的第3个顶点的位置

	return 0;
}

double MinWeightTriangulation(int n,double **t,int **s)
{
	/***
	for(int i=1; i<=n; i++)
	{
		t[i][i] = 0.0;
	}
	for(int r=2; r<=n; r++) //r为当前计算的链长（子问题规模）
	{
		for(int i=1; i<=n-r+1; i++)//n-r+1为最后一个r链的前边界
		{
			int j = i+r-1;//计算前边界为r，链长为r的链的后边界

			t[i][j] = t[i+1][j] + Weight(i-1,i,j);//将链ij划分为A(i) * ( A[i+1:j] )这里实际上就是k=i

			s[i][j] = i;

			for(int k=i+1; k<j; ++k)
			{
				//将链ij划分为( A[i:k] )* (A[k+1:j])
				double u = t[i][k] + t[k+1][j] + Weight(i-1,k,j);
				if(u<t[i][j])
				{
					t[i][j] = u;
					s[i][j] = k;
				}
			}
		}
	}
	return t[1][N-2];***/

        for (int  i = 1; i <= n; i++)
            t[i][i] = 0;
       for (int  r = 2; r <= n; r++) //第1层循环
            for (int i = 1; i <= n-r+1; i++) {

                    int j= i + r - 1;
                    t[i][i] = t[i+1][j] + Weight(i-1, i, j);
                           s[i][i] =i;
                     for (int k =i+1; k <i+r-1; k++) {
                           int u=t[i][k] + t[k+1][j] + Weight(i-1,k,j);
                        if (u<t[i][j])
                            {
                                t[i][j]=u;
                                s[i][j] =k;
                            }
              }
        }
        return t[1][N-2];

}

void Traceback(int i,int j,int **s)
{
	if(i==j) return;
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	cout<<"三角剖分顶点："<<i<<","<<j+1<<","<<s[i][j]+1<<endl;
}

double Weight(int a,int b,int c)
{
	 return weight[a][b] + weight[b][c] + weight[a][c];
}

double dis(double radlat1,double radlat2,double radlog1,double radlog2)
{

	if(radlat1==radlat2&&radlog1==radlog2){
		return 0;
	}
	double s= acos(cos(radlat1)*cos(radlat2)*cos(radlog1-radlog2)+sin(radlat1)*sin(radlat2));
	if(s-0<0.000001){
		return 0;
	}
	return s=EARTH_RADIUS*s*10;
}
//3d5 凸多边形最优三角剖分
//#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

double rad(double l){
	return l*3.14/180.0;
}

const double EARTH_RADIUS=6378.137;
double dis(double radlat1,double radlat2,double radlog1,double radlog2);

int N ;//凸多边形边数+1
double weight[28][28];//凸多边形的权

double MinWeightTriangulation(int n,double **t,int **s);

void Traceback(int i,int j,int **s);//构造最优解

double Weight(int a,int b,int c);//权函数

int main()
{
    cin>>N;
    if(N==21)
    {
       double jing1[20]={102.872,102.879,102.895,102.895,102.863,102.768,102.736,102.719,102.678,102.677,102.676,102.675,102.675,102.675,102.675,102.676,102.686,102.704,102.74,102.746};
	   double wei1[20]={25.01466,25.024444,25.050191,25.095,25.09831,25.10243,25.10088,25.096666,25.05902,25.05719,25.05218,25.03436,25.01318,25.00996,24.99597,24.99248,24.98032,24.97184,24.95721,24.9555};
    for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<N-1;j++)
        {

            weight[i][j]=dis(wei1[i],wei1[j],jing1[i],jing1[j]);
        }
    }
    }
    else
    {
       double jing1[28]={102.746,102.749,102.763,102.769,102.77,102.77,102.769,102.764,102.754,102.744,102.74,102.729,102.718,102.714,102.704,102.695,102.687,102.685,102.682,102.681,102.682,102.686,102.689,102.704,102.707,102.709,102.714,102.732};
	   double wei1[28]={24.98604,24.988197,25.0001,25.01036,25.01896,25.027222,25.033055,25.04446,25.05378,25.05965,25.06162,25.06275,25.06268,25.061944,25.05773,25.05141,25.04281,25.038284,25.03012,25.0252,25.01405,25.005124,25.00074,24.98862,24.9864,24.98496,24.9832,24.98221};
     for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<N-1;j++)
        {
            weight[i][j]=dis(wei1[i],wei1[j],jing1[i],jing1[j]);
        }
    }
    }
	int **s = new int *[N];
    double **t = new double *[N];
    for(int i=0;i<N;i++)
    {
        s[i] = new int[N];
        t[i] = new double[N];
    }
	cout<<"此多边形的最优三角剖分值为："<<std::fixed <<MinWeightTriangulation(N-1,t,s)<<endl;
    cout<<"最优三角剖分结构为："<<endl;
    Traceback(1,N-2,s); //s[i][j]记录了Vi-1和Vj构成三角形的第3个顶点的位置

	return 0;
}

double MinWeightTriangulation(int n,double **t,int **s)
{
	/***
	for(int i=1; i<=n; i++)
	{
		t[i][i] = 0.0;
	}
	for(int r=2; r<=n; r++) //r为当前计算的链长（子问题规模）
	{
		for(int i=1; i<=n-r+1; i++)//n-r+1为最后一个r链的前边界
		{
			int j = i+r-1;//计算前边界为r，链长为r的链的后边界

			t[i][j] = t[i+1][j] + Weight(i-1,i,j);//将链ij划分为A(i) * ( A[i+1:j] )这里实际上就是k=i

			s[i][j] = i;

			for(int k=i+1; k<j; ++k)
			{
				//将链ij划分为( A[i:k] )* (A[k+1:j])
				double u = t[i][k] + t[k+1][j] + Weight(i-1,k,j);
				if(u<t[i][j])
				{
					t[i][j] = u;
					s[i][j] = k;
				}
			}
		}
	}
	return t[1][N-2];***/

        for (int  i = 1; i <= n; i++)
            t[i][i] = 0;
       for (int  r = 2; r <= n; r++) //第1层循环
            for (int i = 1; i <= n-r+1; i++) {

                    int j= i + r - 1;
                    t[i][i] = t[i+1][j] + Weight(i-1, i, j);
                           s[i][i] =i;
                     for (int k =i+1; k <i+r-1; k++) {
                           int u=t[i][k] + t[k+1][j] + Weight(i-1,k,j);
                        if (u<t[i][j])
                            {
                                t[i][j]=u;
                                s[i][j] =k;
                            }
              }
        }
        return t[1][N-2];

}

void Traceback(int i,int j,int **s)
{
	if(i==j) return;
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	cout<<"三角剖分顶点："<<i<<","<<j+1<<","<<s[i][j]+1<<endl;
}

double Weight(int a,int b,int c)
{
	 return weight[a][b] + weight[b][c] + weight[a][c];
}

double dis(double radlat1,double radlat2,double radlog1,double radlog2)
{

	if(radlat1==radlat2&&radlog1==radlog2){
		return 0;
	}
	double s= acos(cos(radlat1)*cos(radlat2)*cos(radlog1-radlog2)+sin(radlat1)*sin(radlat2));
	if(s-0<0.000001){
		return 0;
	}
	return s=EARTH_RADIUS*s*10;
}
//3d5 凸多边形最优三角剖分
//#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

double rad(double l){
	return l*3.14/180.0;
}

const double EARTH_RADIUS=6378.137;
double dis(double radlat1,double radlat2,double radlog1,double radlog2);

int N ;//凸多边形边数+1
double weight[28][28];//凸多边形的权

double MinWeightTriangulation(int n,double **t,int **s);

void Traceback(int i,int j,int **s);//构造最优解

double Weight(int a,int b,int c);//权函数

int main()
{
    cin>>N;
    if(N==21)
    {
       double jing1[20]={102.872,102.879,102.895,102.895,102.863,102.768,102.736,102.719,102.678,102.677,102.676,102.675,102.675,102.675,102.675,102.676,102.686,102.704,102.74,102.746};
	   double wei1[20]={25.01466,25.024444,25.050191,25.095,25.09831,25.10243,25.10088,25.096666,25.05902,25.05719,25.05218,25.03436,25.01318,25.00996,24.99597,24.99248,24.98032,24.97184,24.95721,24.9555};
    for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<N-1;j++)
        {

            weight[i][j]=dis(wei1[i],wei1[j],jing1[i],jing1[j]);
        }
    }
    }
    else
    {
       double jing1[28]={102.746,102.749,102.763,102.769,102.77,102.77,102.769,102.764,102.754,102.744,102.74,102.729,102.718,102.714,102.704,102.695,102.687,102.685,102.682,102.681,102.682,102.686,102.689,102.704,102.707,102.709,102.714,102.732};
	   double wei1[28]={24.98604,24.988197,25.0001,25.01036,25.01896,25.027222,25.033055,25.04446,25.05378,25.05965,25.06162,25.06275,25.06268,25.061944,25.05773,25.05141,25.04281,25.038284,25.03012,25.0252,25.01405,25.005124,25.00074,24.98862,24.9864,24.98496,24.9832,24.98221};
     for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<N-1;j++)
        {
            weight[i][j]=dis(wei1[i],wei1[j],jing1[i],jing1[j]);
        }
    }
    }
	int **s = new int *[N];
    double **t = new double *[N];
    for(int i=0;i<N;i++)
    {
        s[i] = new int[N];
        t[i] = new double[N];
    }
	cout<<"此多边形的最优三角剖分值为："<<std::fixed <<MinWeightTriangulation(N-1,t,s)<<endl;
    cout<<"最优三角剖分结构为："<<endl;
    Traceback(1,N-2,s); //s[i][j]记录了Vi-1和Vj构成三角形的第3个顶点的位置

	return 0;
}

double MinWeightTriangulation(int n,double **t,int **s)
{
	/***
	for(int i=1; i<=n; i++)
	{
		t[i][i] = 0.0;
	}
	for(int r=2; r<=n; r++) //r为当前计算的链长（子问题规模）
	{
		for(int i=1; i<=n-r+1; i++)//n-r+1为最后一个r链的前边界
		{
			int j = i+r-1;//计算前边界为r，链长为r的链的后边界

			t[i][j] = t[i+1][j] + Weight(i-1,i,j);//将链ij划分为A(i) * ( A[i+1:j] )这里实际上就是k=i

			s[i][j] = i;

			for(int k=i+1; k<j; ++k)
			{
				//将链ij划分为( A[i:k] )* (A[k+1:j])
				double u = t[i][k] + t[k+1][j] + Weight(i-1,k,j);
				if(u<t[i][j])
				{
					t[i][j] = u;
					s[i][j] = k;
				}
			}
		}
	}
	return t[1][N-2];***/

        for (int  i = 1; i <= n; i++)
            t[i][i] = 0;
       for (int  r = 2; r <= n; r++) //第1层循环
            for (int i = 1; i <= n-r+1; i++) {

                    int j= i + r - 1;
                    t[i][i] = t[i+1][j] + Weight(i-1, i, j);
                           s[i][i] =i;
                     for (int k =i+1; k <i+r-1; k++) {
                           int u=t[i][k] + t[k+1][j] + Weight(i-1,k,j);
                        if (u<t[i][j])
                            {
                                t[i][j]=u;
                                s[i][j] =k;
                            }
              }
        }
        return t[1][N-2];

}

void Traceback(int i,int j,int **s)
{
	if(i==j) return;
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	cout<<"三角剖分顶点："<<i<<","<<j+1<<","<<s[i][j]+1<<endl;
}

double Weight(int a,int b,int c)
{
	 return weight[a][b] + weight[b][c] + weight[a][c];
}

double dis(double radlat1,double radlat2,double radlog1,double radlog2)
{

	if(radlat1==radlat2&&radlog1==radlog2){
		return 0;
	}
	double s= acos(cos(radlat1)*cos(radlat2)*cos(radlog1-radlog2)+sin(radlat1)*sin(radlat2));
	if(s-0<0.000001){
		return 0;
	}
	return s=EARTH_RADIUS*s*10;
}
