#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}*BiTree;
void CreatTree(BiTree & root);
void PrePrintTree(BiTree root);
void InPrintTree(BiTree root);
void LatePrintTree(BiTree root);
main()
{
	BiTree root;
	printf("请输入二叉树的先序遍历：");
	CreatTree(root);
	printf("您输入的二叉树为：\n");
	printf("先序遍历序列：");
	PrePrintTree(root);
	printf("\n");
	
	printf("中序遍历序列：");
	InPrintTree(root);
	printf("\n");
	
	printf("后序遍历序列：");
	LatePrintTree(root);
	printf("\n");
}

void CreatTree(BiTree & root)
{
	char c;
	if((c=getchar())!='*'&&c!='\n')
	{
		root=(BiTree)malloc(sizeof(struct BiTNode));
		root->data=c;
		CreatTree(root->lchild);
		CreatTree(root->rchild);
	}
	else
	    root=NULL;
}

void PrePrintTree(BiTree root)
{
	if(root!=NULL)
	     printf("%c",root->data);
     if(root->lchild!=NULL)
          PrePrintTree(root->lchild);
     if(root->rchild!=NULL)
          PrePrintTree(root->rchild);
}

void InPrintTree(BiTree root)
{
	if(root==NULL)
	     exit(0);
	if(root->lchild!=NULL)
	     InPrintTree(root->lchild);
     printf("%c",root->data);
     if(root->rchild!=NULL)
          InPrintTree(root->rchild);
}

void LatePrintTree(BiTree root)
{
	if(root==NULL)
	     exit(0);
	if(root->lchild!=NULL)
	     LatePrintTree(root->lchild);
     if(root->rchild!=NULL)
          LatePrintTree(root->rchild);
     printf("%c",root->data);
}
