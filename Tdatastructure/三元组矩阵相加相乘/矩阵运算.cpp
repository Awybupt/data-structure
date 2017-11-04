/*����ϡ�����A��B������Ԫ�����Ϊ�洢�ṹ����д��������Ӻ���˵��㷨��������Ԫ���C��Ž������
Ҫ��
�Ӽ�������ϡ�����A��B
���A��B�ܷ����/���
���ܣ���������Ӻ�������㣬����ӡ������
�粻�ܣ�Ӧ��ʾ��ԭ��*/ 

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
    	printf("���������������ģ��\n");
	printf("���������A������m=");
	scanf("%d",&a.m);
	printf("���������A������n=");
	scanf("%d",&a.n);
	printf("���������B������m=");
    scanf("%d",&b.m);
    printf("���������B������n=");
    scanf("%d",&b.n);
     
    if(a.m!=b.m||a.n!=b.n)                                         //����ӷ� 
    {
     	printf("����A��B�������ӷ����㣺");
     	if(a.m!=b.m&&a.n!=b.n)
     	    printf("�������������������\n");
	    else if(a.m!=b.m)
            printf("���������������\n");
        else 
            printf("���������������\n");
    }
    else 
    {
     	printf("����A��B�������ӷ�����\n");
     	Matrix c;
     	c.m=a.m;
     	c.n=a.n;
     	init(a,b);
     	Add(a,b,c);
     	printf("A+B�����Ϊ��\n"); 
     	Output(c);
    }
    
    if(a.m!=b.n||a.n!=b.m)
    {
    	printf("����A��B�������˷����㣺");
    	if(a.m!=b.n&&a.n!=b.m)
    	    printf("A������������B��������A������������B������\n");
    	else if(a.m!=b.n)
    	    printf("A������������B������\n");
    	else
    	    printf("A������������B������\n");
	}                                       
	else
	{
		printf("����A��B�����˷�����\n");
		Matrix c;
		c.m=a.m;
		c.n=b.n;
		init(a,b);
		Multi(a,b,c);
		printf("A*B��ľ���Ϊ��\n");
		Output(c);
	}                 
}

void init(Matrix & A,Matrix & B)                                  //�Ծ���AB���г�ʼ�� 
{
	int k;
	printf("���������A�ķ���Ԫ�ظ��������Ϊ10)t=");
	scanf("%d",&A.t);
	for(k=1;k<=A.t;++k)
	{
		printf("����%d��\n",k);
		printf("����i=");
		scanf("%d",&A.date[k].i);
		printf("����j=");
		scanf("%d",&A.date[k].j);
		printf("����v=");
		scanf("%d",&A.date[k].v);
	}
	printf("���������B�ķ���Ԫ�ظ��������Ϊ10)t=");
	scanf("%d",&B.t);
	for(k=1;k<=B.t;++k)
	{
		printf("����%d��\n",k);
		printf("����i=");
		scanf("%d",&B.date[k].i);
		printf("����j=");
		scanf("%d",&B.date[k].j);
		printf("����v=");
		scanf("%d",&B.date[k].v);
	}
}

void Add(Matrix & A,Matrix & B,Matrix & C)                               //��ɾ���ӷ����� 
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

void Output(Matrix & C)                                                            //����������C 
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

/*����˼·������������Ԫ�飬�ҵ�A��������B��������ȵ�Ԫ�أ���Ԫ����ˣ��ٱ���C��������ҵ��ó˻�Ӧ���ڵ��Ǹ�λ�üӽ�ȥ����λ��
  ����i����A��Ԫ������������j����B��Ԫ�������������û�ҵ��Ǿ���C��һ���µ�dateֵ ��ʱ�临�Ӷ�Ϊn^3*/ 
  
void Multi(Matrix & A,Matrix & B,Matrix & C)                                      //��ɾ���˷� 
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
				for(l=1;l<k;++l)                            //����C��Ԫ�鿴�ó˻��Ƿ�����֮ǰ�Ѿ��γɷ�date���ֵ 
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
