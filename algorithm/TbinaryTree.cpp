/***#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

typedef int data;

typedef struct
{
       data weight;
       int parent,lchild,rchild;
}HTNode;

typedef HTNode * HuffmanTree;



void InitHuffmanTree(HuffmanTree &HT,int m)
{
       HT=new HTNode[m];
       for(int i=0;i<m;i++)
       {
              HT[i].weight=0;
              HT[i].parent=-1;
              HT[i].lchild=-1;
              HT[i].rchild=-1;
       }
}
//****************************************
//从n个结点中选取最小的两个结点
//****************************************
void SelectMin(HuffmanTree &HT,int n,int &min1,int &min2)
{
       typedef struct m
       {
              int NewWeight;//存储权
              int p;//存储该结点所在的位置
       }TempNode,*TempTree;

       TempTree TT=new TempNode[n];
       int j=0;

       for(int i=0;i<n;i++)
       {
              if(HT[i].parent==-1&& HT[i].weight!=0)
              {
                     TT[j].NewWeight=HT[i].weight;
                     TT[j].p=i;
                     j++;
              }
       }//将HT中没有双亲的结点存储到TT中

       int m1=0,m2=0;

       for(int i=0;i<j;i++)
       {
              if(TT[i].NewWeight<TT[m1].NewWeight)//此处不让取到相等，是因为结点中有相同权值的时候，m1取最前
                  m1=i;
       }

       for(int i=0;i<j;i++)
       {
              if(m1==m2)
                  m2++;//当m1在第一个位置的时候，m2向后移一位
              if(TT[i].NewWeight<=TT[m2].NewWeight&& i!=m1)//此处取到相等，是让在结点中有相同的权值的时候，
                  m2=i;
                                   //m2取最后的那个。

       }

       min1=TT[m1].p;
       min2=TT[m2].p;

}


void CreateHaffmanTree(HuffmanTree &HT,int n,int a[])
{
       int i;
       int m;
       int min1,min2;
       if(n<=1)
              cout<<"ParameterError!";
       m=2*n-1;//哈夫曼树中结点的个数

       InitHuffmanTree(HT,m);

       for(i=0;i<n;i++)
       {
            HT[i].weight=a[i];
       }

       for(i=n;i<m;i++)
       {
              SelectMin(HT,i,min1,min2);
              HT[min1].parent=i;
              HT[min2].parent=i;
              HT[i].lchild=min1;
              HT[i].rchild=min2;
              HT[i].weight=HT[min1].weight+HT[min2].weight;

              cout<<min1<<" "<<min2<<endl;
       }
}

//***********************************
//构造哈夫曼编码
//***********************************


typedef struct
{
       char ch;
       string bits;
}CodeNode;

typedef CodeNode * HuffmanCode;


void CreateHuffmanCode(HuffmanTree &HT,HuffmanCode &HC,int n)
{
       int i;
       int start;
       int c;
       int p;
       char * cd;
       HC=new CodeNode[n];
       cd=new char[n];
       cd[n-1]='/0';

       for(i=0;i<n;i++)
       {
              if(i==n-1)
                HC[i].ch='#';
              else
                HC[i].ch=(char)97+i;
              start=n-1;

              c=i;
              while((p=HT[c].parent)>=0)
              {
                     --start;
                     cd[start]=(HT[p].lchild==c)?'0':'1';
                     c=p;
              }

              for(int y=start;y<=n;y++)
                  HC[i].bits=HC[i].bits+cd[start];
              //strcpy(HC[i].bits,&cd[start]);


       }

       delete cd;
}

/
void OutputHuffmanCode(HuffmanCode&HC,int n)
{
       int i;
       for(i=0;i<n;i++)
       {
              cout<<HC[i].ch<<" "<<HC[i].bits<<endl;
       }
}

int  main()
{
       int i=27;
       int inpu[27]={0};
       fstream fin;
       fin.open("2.txt");
       char exmchar;
       string j;
       while(fin>>exmchar)
       {

           if(exmchar>96&&exmchar<123)
               {++inpu[exmchar-97];
               j=j+exmchar;
               }
           else if(exmchar>64&&exmchar<91)
               {++inpu[exmchar-65];
               j=j+exmchar;
               }
           else
               {++inpu[26];
               j=j+'{';
               }
       }
       //cout<<j.size()<<endl;
       fin.close();
       HuffmanTree HT;
       HuffmanCode HC;

       CreateHaffmanTree(HT,i,inpu);
       CreateHuffmanCode(HT,HC,i);
       OutputHuffmanCode(HC,i);
       ofstream fout;
       int r=0;
       fout.open("2ans.txt");
       while(r<j.size())
       {
        int es=(int)j[r]-95;
        //cout<<es<<endl;
           fout<<HC[es].bits;
           r++;
       }
       fout.close();

       return 0;
}***/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include<iomanip>
#include <string>
#include <cstring>
#include <math.h>
#include <cctype>
using namespace std;


typedef struct{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;

int lenOfCode(char*s)
{
    int len=0;
    for(;s[len]!=NULL;++len)
        ++len;
    return len;
}


typedef char **HuffmanCode;

void Info(int *s) //统计文本文档每个字符的出现次序，每出现一次，对应的下表为其ASSIC码值的数组值加一
{
	char ch;  ifstream fin;
	fin.open("2.txt");
	fin.get(ch);
	while(fin.good())
	{
	    if(isalpha(ch)){
            if(isupper(ch))
                s[(int)(ch-'A'+1)]++;
            else if(islower(ch))
                s[(int)(ch-'a'+1)]++;
        }
		else
            s[27]++;
		fin.get(ch);
	}
    fin.close();
}

void Select(HuffmanTree HT,int k,int &  s1,int & s2)   //在HT【1...i-1】选择parent为0且权值最小的两个结点，其序号分别为s1，s2
{
    int i,cycle=1,m;
    for(m=1;m<=k&&cycle!=3;++m)
    {
     	if(HT[m].parent==0&&cycle==1)
     	{
	     	s1=m;
	     	cycle=2;
	    }
        else if(HT[m].parent==0&&cycle==2)
        {
          	s2=m;
          	++cycle;
          	if(HT[s1].weight>HT[s2].weight)
          	{
	          	s2=s1;
	          	s1=m;
	        }
        }
    }
    for(i=m;i<=k;i++)
    {
        if(HT[i].weight<HT[s2].weight&&HT[i].parent==0)
        {
            if (HT[i].weight<HT[s1].weight)
            {
                s2=s1;
                s1=i;
            }
            else
                s2=i;
        }
    }
}
void HuffmanCoding(HuffmanTree & HT,HuffmanCode & HC,int *w,int n)//哈夫曼编码函数
{
	if(n<=1) return;
	int m=2*n-1;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));             //0号单元未启用
	HuffmanTree p;
	int i;
	for(p=HT+1,i=1;i<=n;++i,++p,++w)
    {
        p->weight=*(w+1);
     	p->parent=p->lchild=p->rchild=0;
    }

	for(;i<=m;++i,++p)
        p->weight=p->parent=p->lchild=p->rchild=0;
    int s1,s2;
    for(i=n+1;i<=m;++i)
    {                       //建哈夫曼树
     	Select(HT,i-1,s1,s2);              //在HT【1...i-1】选择parent为0且权值最小的两个结点，其序号分别为s1，s2
     	HT[s1].parent=i;
     	HT[s2].parent=i;
     	HT[i].lchild=s1;
     	HT[i].rchild=s2;
     	HT[i].weight=HT[s1].weight+HT[s2].weight;
    }

     //从叶子结点到根逆向求每个字符的哈夫曼编码
	HC=(HuffmanCode)malloc((n+1)*sizeof(char*));      //分配n个字符编码的头指针向量

	char *cd=(char*)malloc(n*sizeof(char));            //分配编码字符串空间
	cd[n-1]='\0';
	int c,f;                                  //编码结束符
	for(i=1;i<=n;++i)                                 //逐个字符求哈夫曼树
	{
		int start=n-1;                                    //编码结束符位置
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
		{
			if(HT[f].lchild==c)
			    cd[--start]='0';
                else
			    cd[--start]='1';
		}
		HC[i]=(char*)malloc((n-start)*sizeof(char));          //为第i个字符编码分配空间
		strcpy(HC[i],&cd[start]);                  //从cd复制码串到HC
	}
	free(cd);
}



int main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	int i;
	int s[28]={0};
    Info(s);    //用来统计字符的出现次数
    int num = 0;
    for(i=1;i<=27;++i)
        num=num+s[i];
    double rate[28];
    for(i=1;i<=27;++i)
        rate[i]= (double)s[i]/num;
    HuffmanCoding(HT,HC,s,27);
	for(i=1;i<=26;++i)
        if(i%2!=0)
            cout<<(char)(i-1+'a')<<"编码"<<HC[i]<<"频率："<<setprecision(3)<<rate[i]<<"        ";
        else
            cout<<(char)(i-1+'a')<<"编码"<<HC[i]<<"频率："<<setprecision(3)<<rate[i]<<endl;
    cout<<"#  "<<"编码："<<HC[i]<<"频率："<<setprecision(3)<<rate[i]<<endl;
    int len[28];
    for(i=1;i<=27;++i)
        len[i]=lenOfCode(HC[i]);
    int huffManBits=0;
    for(i=1;i<=27;++i)
        huffManBits=huffManBits+s[i]*len[i];
    cout<<endl<<"哈夫曼编码比特数："<<huffManBits<<endl;
    cout<<"定长编码比特数："<<8*num<<endl;
    return 0;
}
