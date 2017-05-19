#include <iostream>
using  namespace  std;

typedef  struct  node  {
    char   data;
    int    pnum;
    node   *lc,  *rc;
}  node,  *bitptr;

bitptr  CreateTree( char  TREE[50],  int  &i ){
    bitptr  t;
    char  ch;
    if  ( TREE[0] == '-' )  cin >> ch;  else  ch = TREE[i++];
    if  ( ch == '0' )  t = NULL;  else
    {   t = new  node;
        t->data = ch;
        t->pnum = 0;
        t->lc = CreateTree( TREE, i );
        t->rc = CreateTree( TREE, i );
    }
    return  t;
}

void  DisplayTree( bitptr t,  int  level ){
    if  ( t )
    {   DisplayTree( t->rc, level+1 );
        for  ( int  i = 1;  i < level;  i++ )  cout << "  ";
        cout << t->data << endl;
        DisplayTree( t->lc, level+1 );
    }
}

void  Height( bitptr  t,  int  level,  int  &High ){
    if  ( t )
    {   Height( t->lc,  level+1,  High );
        Height( t->rc,  level+1,  High );
        if  ( High < level )  High = level;
    }
}

int  Height1( bitptr  t ){
    int  lh,  rh;
    if  ( ! t )  return  0;
    lh = Height1( t->lc );
    rh = Height1( t->rc );
    return  lh > rh ? lh+1 : rh+1;
}

int  Count( bitptr  t ){
    int  lnum,  rnum;
    if  ( ! t )  return  0;
    lnum = Count( t->lc );
    rnum = Count( t->rc );
    return  lnum+rnum+1;
}

void  PreOrder( bitptr  t ){
    if  ( t )
    {   cout << t->data;
        PreOrder( t->lc );
        PreOrder( t->rc );
    }
}

void  InOrder( bitptr  t ){
    if  ( t )
    {   InOrder( t->lc );
        cout << t->data;
        InOrder( t->rc );
    }
}

void  PostOrder( bitptr  t ){
    if  ( t )
    {   PostOrder( t->lc );
        PostOrder( t->rc );
        cout << t->data;
    }
}

void  DisplayTree1( bitptr  t,  int  level ){
    if  ( t )
    {   DisplayTree1( t->rc, level+1 );
        for  ( int  i = 1;  i < level;  i++ )  cout << "  ";
        cout << t->data << ',' << t->pnum << endl;
        DisplayTree1( t->lc, level+1 );
    }
}

int  CountPnum( bitptr  t )
{   if  ( ! t )  return  -1;
    t->pnum = CountPnum( t->lc ) + CountPnum( t->rc ) + 2;
    return  t->pnum;
}

int  CountPnum1( bitptr  t )
{   if  ( ! t )  return  0;
    t->pnum = 0;
    if  ( t->lc )  t->pnum +=  CountPnum( t->lc ) + 1;
    if  ( t->rc )  t->pnum +=  CountPnum( t->rc ) + 1;
    return  t->pnum;
}

int  CountPnum2( bitptr  t )
{   if  ( ! t )  return  0;
    if  ( ! t->lc && ! t->rc )  return  0;
    t->pnum = CountPnum( t->lc ) + CountPnum( t->rc ) + 2;
    return  t->pnum;
}

int  CountPnum3( bitptr  t )
{   if  ( ! t )  return  -1;
    t->pnum++;
    if  ( t->lc )  CountPnum3( t->lc );
    if  ( t->rc )  CountPnum3( t->rc );
    return  t->pnum;
}

int  main()
{   bitptr  t;
    char  TREE[50] = "FBA00DC00E00JHG00I00K00";
    int  H = 0, i = 0;
    cout << "请输入二叉树的前序序列，空指针用 0 表示：" << endl;
    t = CreateTree( TREE, i );
    cout << "该二叉树如下：" << endl;
    DisplayTree( t, 1 );
    cout << "该二叉树的前序遍历是：";
    PreOrder( t );
    cout << endl;
    cout << "该二叉树的中序遍历是：";
    InOrder( t );
    cout << endl;
    cout << "该二叉树的后序遍历是：";
    PostOrder( t );
    cout << endl;
    Height( t, 1, H );
    cout << "该二叉树的高度是 ";
    cout << H << " 。" << endl;
    cout << "该二叉树的高度是 ";
    cout << Height1( t ) << " 。" << endl;
    cout << "该二叉树的结点个数是 ";
    cout << Count( t ) << endl;
    cout << "该二叉树的各结点子孙个数是:" << endl;
    CountPnum3( t );
    DisplayTree1( t, 1 );
    CountPnum1( t );
    DisplayTree1( t, 1 );
    CountPnum2( t );
    DisplayTree1( t, 1 );
    CountPnum( t );
    DisplayTree1( t, 1 );
    system( "pause" );
    return  0;
}

