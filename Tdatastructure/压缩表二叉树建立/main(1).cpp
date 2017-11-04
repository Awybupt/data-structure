#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<queue>
#include<string>
#include<fstream>
using namespace std;

#define  OK       		1
#define  ERROR    		0
#define  TRUE       	1
#define  FALSE   		0
#define  INFEASIBLE   	-1
#define  OVERFLOW   	-2
typedef char ElemType;

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

CreateBiTree(BiTree& T)
{
	char c;
	cin>>c;
	if('*'==c){
		T=NULL;
	}
	else{
		T=(BiTree)malloc(sizeof(BiTNode));
		if (!T)
            exit(OVERFLOW);
		T->data=c;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

visit(char data,int level){
	printf("%c is %d level\n",data,level);
}

PreOrderTraverse(BiTree T,int level){
	if(T){
		visit(T->data,level);
		PreOrderTraverse(T->lchild,level+1);
		PreOrderTraverse(T->rchild,level+1);
	}
}

zhongOrderTraverse(BiTree T,int level){
	if(T){
		zhongOrderTraverse(T->lchild,level+1);
		visit(T->data,level);
		zhongOrderTraverse(T->rchild,level+1);
	}
}
houOrderTraverse(BiTree T,int level){
	if(T){
		houOrderTraverse(T->lchild,level+1);
		houOrderTraverse(T->rchild,level+1);
		visit(T->data,level);
	}
}

BiTree Delete (queue<BiTree> & q){
	BiTree temp;
	temp=q.front();
	q.pop();
	return temp;
}
cengciTraverse(BiTree T){
	if(T){
		queue<BiTree> q;
		BiTree BT;
		q.push(T);
		while(!q.empty()){
			BT=Delete(q);
			printf(" %c ",BT->data);
			if(BT->lchild) q.push(BT->lchild);
			if(BT->rchild) q.push(BT->rchild);
		}
	}

}

int Position(char mid[],char c)
{
    return strchr(mid,c)-mid;
}

void PreMidCreateTree(BiTree &pn, int i, int j, int len ,char pre[],char mid[])
{
    if(len <= 0){
		pn=NULL;
		return;
	}
    pn = new BiTNode;
    pn->data = pre[i];
    int m = Position(mid,pre[i]);
    PreMidCreateTree(pn->lchild, i+1, j, m-j,pre,mid);
    PreMidCreateTree(pn->rchild, i+(m-j)+1, m+1, len-1-(m-j),pre,mid);
}

int yezi(BiTree T){

    if(!T)
		return 0;
	else
		if(!T->lchild&&!T->rchild)
			return 1;
		else
			return yezi(T->lchild)+yezi(T->rchild);

}

//求叶子方案二
void yezi2(BiTree T,int &count){
	if(T){
		if(!T->lchild&&!T->rchild)	++count;
		yezi2(T->lchild,count);
		yezi2(T->rchild,count);
	}
}


//凹入表
void printtable(BiTree p,string ss)
{
	if(p==NULL)
		return;
	ss+="   ";
	printtable(p->rchild,ss);
	cout<<ss<<p->data<<endl;
	printtable(p->lchild,ss);
}

int main()
{
	cout<<"先序递归过程建立二叉树并计算二叉树中叶子结点的数目:"<<endl;
	int level=1;
	BiTree T=NULL;
	CreateBiTree(T);
	cout<<"前序遍历结果为："<<endl;
	PreOrderTraverse(T,level);
	cout<<"中序遍历结果为："<<endl;
	zhongOrderTraverse(T,level);
	cout<<"后序遍历结果为："<<endl;
	houOrderTraverse(T,level);
	cout<<"层次遍历结果为："<<endl;
	cengciTraverse(T);
	cout<<endl<<"节点数为:"<<endl;
	cout<<yezi(T)<<endl;//方法一
	int count=0; //方法二
	yezi2(T,count);
	cout<<count<<endl;
	cout<<"凹入表打印 "<<endl;
	string ss="";
	printtable(T,ss);
	cout<<"由二叉树的先序序列和中序序列建立一棵二叉树"<<endl;
	char xianxu[50],zhongxu[50];
	cout<<"输入先序序列"<<endl;
	cin>>xianxu;
	cout<<"输入中序序列"<<endl;
	cin>>zhongxu;
	BiTree test;
	PreMidCreateTree(test, 0, 0, strlen(zhongxu),xianxu,zhongxu);
	cout<<"前序遍历结果为："<<endl;
	PreOrderTraverse(test,1);
	cout<<"凹入表打印 "<<endl;
	printtable(test,ss);
	return 0;
}

