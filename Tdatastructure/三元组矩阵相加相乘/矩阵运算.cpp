/*假设稀疏矩阵A和B均以三元组表作为存储结构，试写出矩阵相加和相乘的算法，另设三元组表C存放结果矩阵。
要求：
从键盘输入稀疏矩阵A和B
检测A和B能否相加/相乘
如能，做矩阵相加和相乘运算，并打印运算结果
如不能，应显示出原因*/ 

#include<stdio.h>
#include<stdlib.h>
#define Max 10
struct tuple
{
	int i;
	int j;
	int v;
};

typedef struct
{
	int m;
	int n;
	int t;
	struct tuple date[Max+1];
}Matrix;

void init(Matrix & A,Matrix & B);
void Add(Matrix & A,Matrix & B,Matrix & C);
void Output(Matrix & C);
void Multi(Matrix & A,Matrix & B,Matrix & C);

main()
{
	Matrix a,b;
    	printf("请输入两个矩阵规模：\n");
	printf("请输入矩阵A的行数m=");
	scanf("%d",&a.m);
	printf("请输入矩阵A的列数n=");
	scanf("%d",&a.n);
	printf("请输入矩阵B的行数m=");
    scanf("%d",&b.m);
    printf("请输入矩阵B的列数n=");
    scanf("%d",&b.n);
     
    if(a.m!=b.m||a.n!=b.n)                                         //矩阵加法 
    {
     	printf("矩阵A和B不能做加法运算：");
     	if(a.m!=b.m&&a.n!=b.n)
     	    printf("两矩阵行列数都不相等\n");
	    else if(a.m!=b.m)
            printf("两矩阵行数不相等\n");
        else 
            printf("两矩阵列数不相等\n");
    }
    else 
    {
     	printf("矩阵A和B可以做加法运算\n");
     	Matrix c;
     	c.m=a.m;
     	c.n=a.n;
     	init(a,b);
     	Add(a,b,c);
     	printf("A+B后矩阵为：\n"); 
     	Output(c);
    }
    
    if(a.m!=b.n||a.n!=b.m)
    {
    	printf("矩阵A和B不能做乘法运算：");
    	if(a.m!=b.n&&a.n!=b.m)
    	    printf("A的行数不等于B的列数且A的列数不等于B的行数\n");
    	else if(a.m!=b.n)
    	    printf("A的行数不等于B的列数\n");
    	else
    	    printf("A的列数不等于B的行数\n");
	}                                       
	else
	{
		printf("矩阵A和B能做乘法运算\n");
		Matrix c;
		c.m=a.m;
		c.n=b.n;
		init(a,b);
		Multi(a,b,c);
		printf("A*B后的矩阵为：\n");
		Output(c);
	}                 
}

void init(Matrix & A,Matrix & B)                                  //对矩阵AB进行初始化 
{
	int k;
	printf("请输入矩阵A的非零元素个数（最大为10)t=");
	scanf("%d",&A.t);
	for(k=1;k<=A.t;++k)
	{
		printf("数据%d：\n",k);
		printf("行数i=");
		scanf("%d",&A.date[k].i);
		printf("列数j=");
		scanf("%d",&A.date[k].j);
		printf("数据v=");
		scanf("%d",&A.date[k].v);
	}
	printf("请输入矩阵B的非零元素个数（最大为10)t=");
	scanf("%d",&B.t);
	for(k=1;k<=B.t;++k)
	{
		printf("数据%d：\n",k);
		printf("行数i=");
		scanf("%d",&B.date[k].i);
		printf("列数j=");
		scanf("%d",&B.date[k].j);
		printf("数据v=");
		scanf("%d",&B.date[k].v);
	}
}

void Add(Matrix & A,Matrix & B,Matrix & C)                               //完成矩阵加法运算 
{
	int k,lA=1,lB=1;
	for(k=1;lA<=A.t&&lB<=B.t;++k)
	{
		if(A.date[lA].i<B.date[lB].i||A.date[lA].i==B.date[lB].i&&A.date[lA].j<B.date[lB].j)
		{
			C.date[k].i=A.date[lA].i;
			C.date[k].j=A.date[lA].j;
			C.date[k].v=A.date[lA].v;
			++lA;
		}
		else if(A.date[lA].i==B.date[lB].i&&A.date[lA].j==B.date[lB].j)
		{
			C.date[k].i=A.date[lA].i;
			C.date[k].j=A.date[lA].j;
			C.date[k].v=A.date[lA].v+B.date[lB].v;
			++lA;
			++lB;
		}
		else
		{
			C.date[k].i=B.date[lB].i;
			C.date[k].j=B.date[lB].j;
			C.date[k].v=B.date[lB].v;
			++lB;
		}
	}
	if(lA<A.t)
	{
		for(;lA<=A.t;++k)
		{
			C.date[k].i=A.date[lA].i;
			C.date[k].j=A.date[lA].j;
			++lA;
		}
	}
	if(lB<B.t)
	{
		for(;lB<=B.t;++k)
		{
			C.date[k].i=B.date[lB].i;
			C.date[k].j=B.date[lB].j;
			++lB;
		}
	}
}

void Output(Matrix & C)                                                            //输出结果矩阵C 
{
	int k,l,lC=1;
	for(k=1;k<=C.m;++k)
	{
		for(l=1;l<=C.n;++l)
		{
			if(C.date[lC].i==k&&C.date[lC].j==l&&lC<=Max)
            {
               	printf("%d ",C.date[lC].v);
               	++lC;
            }
            else
                printf("0 ");
		}
		printf("\n");
	}
}

/*基本思路：遍历两个三元组，找到A中列数与B中行数相等的元素，两元素相乘，再遍历C结果矩阵找到该乘积应属于的那个位置加进去（该位置
  行数i等于A中元素行数，列数j等于B中元素列数），如果没找到那就是C中一个新的date值 ，时间复杂度为n^3*/ 
  
void Multi(Matrix & A,Matrix & B,Matrix & C)                                      //完成矩阵乘法 
{
	int lA,lB,lC=1,k,l,s=0;
	for(k=1;k<=Max;++k)
	    C.date[k].v=0;
	k=1;
	for(lA=1;lA<=A.t;++lA)           
	{
		for(lB=1;lB<=B.t;++lB)
		{
			if(A.date[lA].j==B.date[lB].i)
			{
				for(l=1;l<k;++l)                            //遍历C三元组看该乘积是否属于之前已经形成发date结点值 
             	{
            		if(C.date[l].i==A.date[lA].i&&C.date[l].j==B.date[lB].j)
	             	{
	             		++s;
	            		C.date[l].v=C.date[l].v+A.date[lA].v*B.date[lB].v;
		            	break;
	            	}
            	}
            	if(s==0)
            	{
            		C.date[k].i=A.date[lA].i;
            		C.date[k].j=B.date[lB].j;
            		C.date[k].v=A.date[lA].v*B.date[lB].v;
            		++k;
				}
				s=0;
			}
		}
	}
}
