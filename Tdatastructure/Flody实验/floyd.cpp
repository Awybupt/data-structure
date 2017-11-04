#include<iostream>
#include<cstdlib>

#define MAX_VERTEX_NUM 20
#define MAX_NUM        1000

using namespace std;

typedef struct ArcNode{      //弧信息 
	int adjvex;             //该弧所指向的顶点位置 
	struct ArcNode *nextare;//指向下一条弧的指针
	int weight;             //该弧的权值 
}ArcNode;

typedef struct VNode{
	char vertex;            //顶点信息，用一个字符表示一个顶点
	ArcNode *firstarc;      //指向第一条依附该顶点的弧的指针 
}VNode;

typedef struct{
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];    //邻接矩阵
	int vexnum;                                  //当前顶点数目 
}Arccell;

void ListToMatrix(VNode AdjList[],Arccell &Matrix)          //该函数将邻接表存储的图转化为邻接矩阵存储
{
	int i,j;
	for(i=0;i<Matrix.vexnum;++i)                           //初始化矩阵
		for(j=0;j<Matrix.vexnum;++j)
		     if(i==j)
		          Matrix.arcs[i][j]=0;
               else
                    Matrix.arcs[i][j]=MAX_NUM;
	for(i=0;i<Matrix.vexnum;++i)                           //邻接表转矩阵 
     {
     	ArcNode *p=AdjList[i].firstarc;
     	for(;p;p=p->nextare)
     	     Matrix.arcs[i][p->adjvex]=p->weight;
     }
     cout<<"邻接表转矩阵后的矩阵为：\n"; 
     for(i=0;i<Matrix.vexnum;++i)
     {
     	for(j=0;j<Matrix.vexnum;++j)
               cout<<Matrix.arcs[i][j]<<" ";
          cout<<endl;
     }
     cout<<"1000代表不连接"<<endl;
} 

void ShortestPath_FLOYD(Arccell &Matrix)                   //FLOYD算法求出最短路径 
{
	int u,v,w;
     for(u=0;u<Matrix.vexnum;++u)
          for(v=0;v<Matrix.vexnum;++v)
	          for(w=0;w<Matrix.vexnum;++w)
	               if(Matrix.arcs[v][u]+Matrix.arcs[u][w]<Matrix.arcs[v][w])
                         Matrix.arcs[v][w]=Matrix.arcs[v][u]+Matrix.arcs[u][w];	          
}

void FarthestVertex(VNode AdjList[],Arccell Matrix)                         //求出最远顶点 
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
	cout<<"距离最远的两个结点为: "<<AdjList[m].vertex<<" "<<AdjList[n].vertex<<endl;
	cout<<"距离为"<<MAX<<endl;
	
	for(i=0;i<Matrix.vexnum;++i)                   //看最远距离是否唯一 
	     for(j=0;j<Matrix.vexnum;++j)
	     {
     		if(Matrix.arcs[i][j]==MAX&&(i!=m||j!=n))
     		{
		          cout<<"距离最远的两个结点为: "<<AdjList[m].vertex<<" "<<AdjList[n].vertex<<endl;
	               cout<<"距离为"<<MAX<<endl;
		     }
     	}
}

void init(VNode AdjList[],Arccell &Matrix)                                            //初始化 
{
	int i=0;
	char ch;
	cout<<"请输入顶点个数：";
	cin>>Matrix.vexnum;
	cout<<"请输入所有的顶点（用字母表示,'#'代表输入结束）：";
	cin>>ch;
	for(;ch!='#';++i)
	{
		AdjList[i].vertex=ch;
		AdjList[i].firstarc=NULL;
		cin>>ch;
	}
     if(i!=Matrix.vexnum)
     {
     	cout<<"输入错误"<<endl;
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
	     	cout<<"顶点"<<AdjList[i].vertex<<"的邻接点位置和路径权值（-1代表输入结束）：";
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
	     cout<<"初始化结束"<<endl;
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
