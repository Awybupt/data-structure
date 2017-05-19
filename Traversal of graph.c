#include  "iostream"
#include "stdio.h"

using  namespace  std;

#define  MAXVNUM  100
#define  MAXQUEUE  200
#define  MAXCOST  30000
#define  filename  "g3.dat"

typedef  int  adjmatrix[MAXVNUM][MAXVNUM];

typedef  struct{
    char  vertex[MAXVNUM];
    adjmatrix  arcs;
    int  vtxnum, arcnum;
} graph;

void  CreateGraph( graph  &G )
{   int  i, j;
    G.arcnum = 0;
#ifdef  filename
    FILE  *f;
    f = fopen( filename, "r" );
    fscanf( f, "%d\n", &G.vtxnum );
    for  ( i = 0;  i < G.vtxnum;  i++ )  fscanf( f, "%c", &G.vertex[i] );
    for  ( i = 0;  i < G.vtxnum;  i++ )
        for  ( j = 0;  j < G.vtxnum;  j++ )
        {   fscanf( f, "%d", &G.arcs[i][j] );
            if  ( G.arcs[i][j] > 0 )  G.arcnum++;;
        }
    cout << "请输入顶点个数：" << G.vtxnum << endl;
    cout << "请输入各顶点名称：";
    for  ( i = 0;  i < G.vtxnum;  i++ )  cout << G.vertex[i];
    cout << endl;
    cout << "请输入图的邻接矩阵：" << endl;
    for  ( i = 0;  i < G.vtxnum;  i++ )
    {   for  ( j = 0;  j < G.vtxnum;  j++ )
            cout << G.arcs[i][j] << ' ';
        cout << endl;
    }
#else
    cout << "请输入顶点个数：";
    cin >> G.vtxnum;
    cout << "请输入各顶点名称：";
    for  ( i = 0;  i < G.vtxnum;  i++ )  cin >> G.vertex[i];
    cout << "请输入图的邻接矩阵：" << endl;
    for  ( i = 0;  i < G.vtxnum;  i++ )
        for  ( j = 0;  j < G.vtxnum;  j++ )
        {   cin >> G.arcs[i][j];
            if  ( G.arcs[i][j] > 0 )  G.arcnum++;
        }
#endif
    for  ( i = 1;  i < G.vtxnum;  i++ )
        for  ( j = 0;  j < i;  j++ )  if  ( G.arcs[i][j] != G.arcs[j][i] )  return;
    G.arcnum /= 2;
}

int  Firstadj( graph  G,  int  v )
{   int  i = 0;
    while  ( i < G.vtxnum )
    {   if  ( G.arcs[v][i] > 0 )  return  i;
        i++;
    }
    return  -1;
}

int  Nextadj( graph  G,  int  v,  int  w )
{   int  i = w+1;
    while  ( i < G.vtxnum )
    {   if  ( G.arcs[v][i] > 0 )  return  i;
        i++;
    }
    return  -1;
}

int  visited[MAXVNUM];

void   dfs( graph  G,  int  v )
{   int  w;
    cout << G.vertex[v] << ' ';
    visited[v] = 1;
    for  ( w = Firstadj( G, v );  w >= 0;  w = Nextadj( G, v, w ))
        if  ( ! visited[w] )  dfs( G, w );
}

void  Dfstraverse( graph  G )
{   int  v;
    for ( v = 0;  v < G.vtxnum;  v++ )  visited[v] = 0;
    for ( v = 0;  v < G.vtxnum;  v++ )  if  ( ! visited[v] )  dfs( G , v );
}

typedef  struct {
    int  data[MAXQUEUE];
    int  front, rear;
} queue;

queue  Q;

void  Iniqueue( queue  &Q )
{   Q.front = 0;
    Q.rear = 0;
}

void  Enqueue( queue  &Q,  int  x )
{   int  r = ( Q.rear + 1 ) % MAXQUEUE;
    if  ( r == Q.front )  cout << "队列满！" << endl;   else
    {   Q.data[Q.rear] = x;
        Q.rear = r;
    }
}

int  Dequeue( queue  &Q )
{   if  ( Q.front == Q.rear )  cout << "队列空！" << endl;  else
    {   int  x = Q.data[Q.front];
        Q.front = ( Q.front + 1 ) % MAXQUEUE;
        return  x;
    }
}

int  Empty( queue  Q )
{   return  Q.front == Q.rear;
}

void  bfs( graph  G,  int  v )
{   int  i, w;
    Iniqueue( Q );
    visited[v] = 1;
    Enqueue( Q , v );
    while  ( ! Empty( Q ) )
    {   v = Dequeue( Q );
        cout << G.vertex[v] << ' ';
        for  ( w = Firstadj( G, v );   w >= 0;   w = Nextadj( G, v , w ))
            if  ( ! visited[w] )
            {   visited[w] = 1;
                Enqueue( Q , w );
            }
    }
}

void  Bfstraverse( graph  G )
{   int  v;
    for ( v = 0;  v < G.vtxnum;  v++ )  visited[v] = 0;
    for ( v = 0;  v < G.vtxnum;  v++ )  if  ( ! visited[v] )  bfs( G, v );
}

void  Change( graph  &G )
{   int  i, j;
    for  ( int i = 0;  i < G.vtxnum;  i++ )
        for  ( int j = 0;  j < G.vtxnum;  j++ )
            if  ( G.arcs[i][j] == -1 )  G.arcs[i][j] = MAXCOST;
}

void  Prim( graph  G  )
{   int  tree[MAXVNUM], cost[MAXVNUM], flag[MAXVNUM] = {0};
    int  i, j, k, mincost;
    for  ( i = 0;  i < G.vtxnum;  i++ )
    {   cost[i] = G.arcs[0][i];
        tree[i] = 0;
    }
    flag[0] = 1;
    for  ( i = 1;  i < G.vtxnum;  i++ )
    {   mincost = MAXCOST;
        for( j =1 ;  j < G.vtxnum;  j++ )
        {   if ( flag[j] == 0 && cost[j] < mincost )
            {   mincost = cost[j];
                k = j;
            }
        }
        flag[k] = 1;
        for  ( j = 1;  j < G.vtxnum;  j++ )
           if (  flag[j] == 0 && G.arcs[k][j] < cost[j] )
           {   cost[j] = G.arcs[k][j];
               tree[j] = k;
           }
    }
    for  ( i = 1;  i < G.vtxnum;  i++ )  cout << '(' << G.vertex[tree[i]]
        << ',' << G.vertex[i] << ',' << cost[i] << ")  ";
    cout << endl;
}

typedef  struct {
    int  v1, v2;
    int  cost;
} edgetype;

void  Caledges( graph  G,  edgetype  edges[ ] )
{   int  i, j, k;
    edgetype  edge;
    k = 0;
    for  ( i = 0;  i < G.vtxnum;  i++ )
        for  ( j = i+1;  j < G.vtxnum;  j++ )
            if  ( G.arcs[i][j] != MAXCOST )
            {   edges[k].v1 = i;
                edges[k].v2 = j;
                edges[k++].cost = G.arcs[i][j];
            }
    for  ( i = 0;  i < G.arcnum-1;  i++ )
        for  ( j = 0;  j < G.arcnum-i-1;  j++ )
            if  ( edges[j].cost > edges[j+1].cost )
            {   edge = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = edge;
            }
}

int  Find( int  father[ ],  int  v )
{   int  t = v;
    while  ( father[t] >= 0 ) t = father[t];
    return  t;
}

void  Kruskal( graph  G )
{   edgetype  edges[MAXVNUM], tree[MAXVNUM];
    int  father[MAXVNUM];
    int  i, j, k, vf1, vf2;
    Caledges( G, edges );
    for  ( i = 0;  i < G.vtxnum;  i++ )  father[i] = -1;
    i = 0;
    j = 0;
    while  ( i < G.arcnum && j < G.vtxnum-1 )
    {   vf1 = Find( father, edges[i].v1 );
        vf2 = Find( father, edges[i].v2 );
        if  ( vf1 != vf2)
        {   father[vf2] = vf1;
            tree[j] = edges[i];
            j++;
        }
        i++;
    }
    for  ( i = 0;  i < G.vtxnum-1;  i++ )  cout << '(' << G.vertex[tree[i].v1]
        << ',' << G.vertex[tree[i].v2] << ',' << tree[i].cost << ")  ";
    cout << endl;
}

void  TopoSort( graph  G )
{   int  indegree[MAXVNUM] = {0};
    int  i, j, n = 0;
    for  ( i = 0;  i < G.vtxnum;  i++ )
        for  ( j = 0;  j < G.vtxnum;  j++ )  if  ( G.arcs[j][i] )  indegree[i]++;
    Iniqueue( Q );
    for  ( i = 0;  i < G.vtxnum;  i++ )  if  ( ! indegree[i] )  Enqueue( Q, i );

    while  ( ! Empty( Q ) )
    {   i = Dequeue( Q );
        cout << G.vertex[i] << ' ';
        for  ( j = Firstadj( G, i );   j >= 0;   j = Nextadj( G, i , j ))
        {   indegree[j]--;
            if  ( ! indegree[j] )  Enqueue( Q , j );
            n++;
        }
    }
    if  ( n < G.vtxnum )  cout << "此非有向无环图。";
    cout  << endl;
}

void  Dijkstra( graph  G,  int  v )
{   int  final[MAXVNUM]={1,0}, D[MAXVNUM], P[MAXVNUM];
    int  i, j, k, min, pre;
    for  ( i = 0;  i < G.vtxnum;  i++ )
    {   D[i] = G.arcs[v][i];
	    P[i] = v;
    }
    D[v] = 0;
    final[v] = 1;
    P[v] = -1;
    for  ( i = 1;  i < G.vtxnum;  i++ )
    {   min = MAXCOST+1;
	    for  ( k = 0;  k < G.vtxnum;  j++ )
	    if  ( ! final[k] && D[k] < min )
	    {   j = k;
	        min = D[k];
        }
	    final[j] = 1;
	    for  ( k = 0;  k < G.vtxnum;  k++ )
	       if  ( ! final[k] && ( D[j]+G.arcs[j][k] < D[k] ) )
	       {   D[k] = D[j]+G.arcs[j][k];
	           P[k] = j;
	       }
	}
	cout<<"***";
    for  ( i = 1;  i < G.vtxnum;  i++ )
	{   printf("%f：%d", D[i], i);
        pre = P[i];
	    while  ( pre >= 0 )
	    {   printf("←%d", pre);
	        pre = P[pre];
        }
	    printf("\n");
    }
}

int  main()
{   graph  G;
    CreateGraph( G );cout << "边数=" << G.arcnum << endl;
    cout << endl;
    cout << "深度优先遍历是：";
    Dfstraverse( G );
    cout << endl;
    cout << "广度优先遍历是：";
    Bfstraverse( G );
    cout << endl;
    Change( G );
    cout << "Prim算法结果是：";
    Prim( G );
    cout << "Kruskal 算法是：";
    Kruskal( G );
    cout << "拓扑排序序列是：";
    TopoSort( G );
    cout << "V1到各点距离是：";
    Dijkstra( G, 0 );
    system( "pause" );
    return  1;
}

