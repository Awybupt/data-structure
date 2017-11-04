#include<iostream>
#include<cstdlib>

#define MAX_VERTEX_NUM 20
#define MAX_NUM        1000

using namespace std;

typedef struct ArcNode{      //����Ϣ 
	int adjvex;             //�û���ָ��Ķ���λ�� 
	struct ArcNode *nextare;//ָ����һ������ָ��
	int weight;             //�û���Ȩֵ 
}ArcNode;

typedef struct VNode{
	char vertex;            //������Ϣ����һ���ַ���ʾһ������
	ArcNode *firstarc;      //ָ���һ�������ö���Ļ���ָ�� 
}VNode;

typedef struct{
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];    //�ڽӾ���
	int vexnum;                                  //��ǰ������Ŀ 
}Arccell;

void ListToMatrix(VNode AdjList[],Arccell &Matrix)          //�ú������ڽӱ�洢��ͼת��Ϊ�ڽӾ���洢
{
	int i,j;
	for(i=0;i<Matrix.vexnum;++i)                           //��ʼ������
		for(j=0;j<Matrix.vexnum;++j)
		     if(i==j)
		          Matrix.arcs[i][j]=0;
               else
                    Matrix.arcs[i][j]=MAX_NUM;
	for(i=0;i<Matrix.vexnum;++i)                           //�ڽӱ�ת���� 
     {
     	ArcNode *p=AdjList[i].firstarc;
     	for(;p;p=p->nextare)
     	     Matrix.arcs[i][p->adjvex]=p->weight;
     }
     cout<<"�ڽӱ�ת�����ľ���Ϊ��\n"; 
     for(i=0;i<Matrix.vexnum;++i)
     {
     	for(j=0;j<Matrix.vexnum;++j)
               cout<<Matrix.arcs[i][j]<<" ";
          cout<<endl;
     }
     cout<<"1000��������"<<endl;
} 

void ShortestPath_FLOYD(Arccell &Matrix)                   //FLOYD�㷨������·�� 
{
	int u,v,w;
     for(u=0;u<Matrix.vexnum;++u)
          for(v=0;v<Matrix.vexnum;++v)
	          for(w=0;w<Matrix.vexnum;++w)
	               if(Matrix.arcs[v][u]+Matrix.arcs[u][w]<Matrix.arcs[v][w])
                         Matrix.arcs[v][w]=Matrix.arcs[v][u]+Matrix.arcs[u][w];	          
}

void FarthestVertex(VNode AdjList[],Arccell Matrix)                         //�����Զ���� 
{
	int i,j,m,n;
	int MAX=0;
	for(i=0;i<Matrix.vexnum;++i)
	     for(j=0;j<Matrix.vexnum;++j)
	     {
     		if(Matrix.arcs[i][j]>MAX)
     		{
		          MAX=Matrix.arcs[i][j];	
		          m=i;
		          n=j;
		     }
     	}
	cout<<"������Զ���������Ϊ: "<<AdjList[m].vertex<<" "<<AdjList[n].vertex<<endl;
	cout<<"����Ϊ"<<MAX<<endl;
	
	for(i=0;i<Matrix.vexnum;++i)                   //����Զ�����Ƿ�Ψһ 
	     for(j=0;j<Matrix.vexnum;++j)
	     {
     		if(Matrix.arcs[i][j]==MAX&&(i!=m||j!=n))
     		{
		          cout<<"������Զ���������Ϊ: "<<AdjList[m].vertex<<" "<<AdjList[n].vertex<<endl;
	               cout<<"����Ϊ"<<MAX<<endl;
		     }
     	}
}

void init(VNode AdjList[],Arccell &Matrix)                                            //��ʼ�� 
{
	int i=0;
	char ch;
	cout<<"�����붥�������";
	cin>>Matrix.vexnum;
	cout<<"���������еĶ��㣨����ĸ��ʾ,'#'���������������";
	cin>>ch;
	for(;ch!='#';++i)
	{
		AdjList[i].vertex=ch;
		AdjList[i].firstarc=NULL;
		cin>>ch;
	}
     if(i!=Matrix.vexnum)
     {
     	cout<<"�������"<<endl;
     	exit(0);
     }    
     else
     {
     	for(i=0;i<Matrix.vexnum;++i)
	     	cout<<i<<"."<<AdjList[i].vertex<<" ";
     	cout<<endl;
     	ArcNode *last;
     	for(i=0;i<Matrix.vexnum;++i)
     	{
	     	cout<<"����"<<AdjList[i].vertex<<"���ڽӵ�λ�ú�·��Ȩֵ��-1���������������";
	     	int num;
	     	cin>>num;
	     	while(num!=-1)
	     	{
	     		ArcNode *p=(ArcNode*)malloc(sizeof(ArcNode));
	     		if(AdjList[i].firstarc==NULL)
          		  	AdjList[i].firstarc=p;   
  		          else
          		  	last->nextare=p;		          
    		          last=p;
         		  	p->nextare=NULL;
         		  	
         		  	p->adjvex=num;
         		  	cin>>num;
         		  	p->weight=num;
         		  	cin>>num;
	     	}
	     }
	     cout<<"��ʼ������"<<endl;
     }
}

main()
{
	VNode AdjList[MAX_VERTEX_NUM];
	Arccell Matrix;
	init(AdjList,Matrix);
	ListToMatrix(AdjList,Matrix);
	ShortestPath_FLOYD(Matrix);
	FarthestVertex(AdjList,Matrix);
}
