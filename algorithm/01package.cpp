#include<stdio.h>
void knapsack(int v[],int w[],int c, int m[][602], int length);
void traceback(int m[][602],int w[],int c,int x[],int length);
int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}

int min(int a,int b)
{
    if(a<b) return a;
    else return b;
}

int v1[100],v2[100];
int w1[100],w2[100];
int m1[100][602];
int m2[100][602];
int x1[100],x2[100];

int main()
{
	FILE * ptr1;
	ptr1=fopen("5.txt","a+");
	if(ptr1==NULL)
	{
		printf("open error!");
		return 0;
	}
	int i;
	int weigh=0;
	for(i=1;i<=50;i++) fscanf(ptr1,"%d",&w1[i]);
	for(i=1;i<=50;i++) fscanf(ptr1,"%d",&v1[i]);
	for(i=1;i<=99;i++) fscanf(ptr1,"%d",&w2[i]);
	for(i=1;i<=99;i++) fscanf(ptr1,"%d",&v2[i]);

	fclose(ptr1);

	knapsack(v1,w1,300,m1,50);
	knapsack(v2,w2,600,m2,99);
	traceback(m1,w1,300,x1,50);
	traceback(m2,w2,600,x2,99);

	printf("第一组的物品放入情况为；\n");
	for(i=1;i<=50;i++) printf("%d ",x1[i]);
	printf("\n背包总重量为：");
	for(i=1;i<=50;i++) weigh=weigh+x1[i]*w1[i];
	printf("%d\n总价值为%d\n",weigh,m1[1][300]);
	weigh=0;
	for(i=1;i<=50;i++) weigh=weigh+x1[i]*v1[i];
	printf("%d",weigh);
	weigh=0;

	printf("第二组的物品放入情况为：\n");
	for(i=1;i<=99;i++)
        printf("%d ",x2[i]);
	printf("\n背包总重量为：");
	for(i=1;i<=99;i++)
	weigh=weigh+x2[i]*w2[i];
	printf("%d\n总价值为%d\n",weigh,m2[1][600]);
	weigh=0;
	for(i=1;i<=99;i++)
	weigh=weigh+x2[i]*v2[i];
	printf("%d",weigh);

}

void knapsack(int v[],int w[],int c, int m[][602],int length)
{
	int n=length;
    int i,j;
	for(j=0;j<=c;j++)
	{

		if(w[n]>j)
		m[n][j]=0;
		else
		m[n][j]=v[n];
	}
	for(i=n-1;i>1;i--)
	{
		for(j=0;j<=c;j++)
		{
			if(w[i]>j)
			m[i][j]=m[i+1][j];
			else
			m[i][j]=max(m[i+1][j],m[i+1][j-w[i]]+v[i]);
		}
	}

	m[1][c]=m[2][c];
	if(c>=w[1]) m[1][c]=max(m[1][c],m[2][c-w[1]]+v[1]);
}

void traceback(int m[][602],int w[],int c,int x[],int length)
{

	int i;
	int n=length;
	for(i=1;i<n;i++)
	{
		if(m[i][c]==m[i+1][c]) x[i]=0;
		else {
			x[i]=1;
			c=c-w[i];
		}
	}

	if(m[n][c]>0) x[n]=1;
	else x[n]=0;
}
