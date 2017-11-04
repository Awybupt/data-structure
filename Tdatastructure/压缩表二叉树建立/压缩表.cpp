#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<cstring>
#include<queue>
#include<math.h>
using namespace std;

typedef struct{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;

typedef char **HuffmanCode;

void Info(int *s);          //统计文本文档每个字符的出现次序，每出现一次，对应的下表为其ASSIC码值的数组值加一
void HuffmanCoding(HuffmanTree & HT,HuffmanCode & HC,int *w,int n);  //哈夫曼编码函数
void Select(HuffmanTree HT,int k,int &  s1,int & s2);   //在HT【1...i-1】选择parent为0且权值最小的两个结点，其序号分别为s1，s2
void BinFileGen(HuffmanCode HC);               //生成二进制文件函数
void Print(HuffmanCode HC);
void codee(HuffmanCode HC,int *Tail);                    //压缩存储
void Decode(HuffmanCode HC,HuffmanTree HT,int n,int Tail);             //解码函数 

main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	int i,k=0,Tail,m;
	int s[256]={0};
	cout<<"是否现在开始压缩文件？ （1.是 0.否）"<<endl;
	cin>>m;
	if(m==1)
	{
		Info(s);    //用来统计字符的出现次数
	    HuffmanCoding(HT,HC,s,256);
    	codee(HC,&Tail);
    	cout<<"压缩成功！已将file.txt压缩存储到FILE.txt！"<<endl;
	}
	else
	{
		cout<<"压缩失败！"<<endl; 
		exit(0);
	}
	cout<<"是否解压缩文件？ （1.是 0.否）"<<endl;
	cin>>m;
	if(m==1)
	{
		Decode(HC,HT,511,Tail);
		cout<<"解压缩成功！已将FILE.txt压缩存储到file1.txt！"<<endl;
	}
	else
	{
		cout<<"解压失败！"<<endl;
		exit(0);
	}
}

void Info(int s[])                        //统计字符出现次数
{
	char ch;
	ifstream fin;
	fin.open("file.txt");
	fin.get(ch);
	while(fin.good())
	{
		s[(int)ch]++;
		fin.get(ch);
	}
     fin.close();
}

void HuffmanCoding(HuffmanTree & HT,HuffmanCode & HC,int *w,int n)  //哈夫曼编码
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

void Select(HuffmanTree HT,int k,int & s1,int & s2)     //在HT【1...i-1】选择parent为0且权值最小的两个结点，其序号分别为s1，s2
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
            {
                s2=i;
            }
        }
    }
}

void codee(HuffmanCode HC,int *Tail)
{
    ofstream oop("FIFE.txt");
    ifstream fin;
    string exm;
    char ch; 
    int we;
    queue<int> goal;
	fin.open("file.txt");                     //file.txt是最初的文本文件，FILE.txt是压缩存储的文件 
	ch=fin.get();
	while(fin.good())
	{
		exm=HC[(int)ch];
		//cout<<ch<<endl;
		//cout<<exm<<endl;
		int numm=exm.size();
		for(int i=0;i<numm;i++)
        {
            int sun=exm[i]-'0';
            goal.push(sun);
        }
        if(goal.size()>8)
        {
            int er=0;
            for(we=0;we<8;we++)
            {
	      		er=er+goal.front()*((int)pow(2,7-we));
                goal.pop();
                if(goal.empty())
                we=9;
            }
            oop<<(char)er;
        }
		ch=fin.get();
	}
	int er=0;
    for(we=0;!goal.empty();we++)
    {
        er=er+goal.front()*((int)pow(2,7-we));
        goal.pop();
    }
    *Tail=we;
    oop<<(char)er;
  	fin.close();
}

void Decode(HuffmanCode HC,HuffmanTree HT,int n,int Tail)
{
	ifstream fin("FIFE.txt");
	ofstream fout;
	int t=0,i;
	short k=1;
	char ch;
	string str(100000,'l');
	ch=fin.get();
	//cout<<ch<<endl;
	while(fin.fail()==false)
	{
      	for (i=0; i<8; i++,ch>>=1)
     	{
	     	if (ch & k)
		     	str[t*8+8-i]='1';
	     	else
		     	str[t*8+8-i]='0';
      	}
      	++t;
      	ch=fin.get();
      	//cout<<ch<<endl;
	}
	//for(i=1;i<=8*t;++i)
	    //cout<<str[i];
	fin.close();
	int f=n;
	fout.open("file1.txt");
	if(!fout.is_open())
	    cout<<"error";
	for(i=1;i<=8*(t-1)+Tail;++i)
	{
		if(str[i]=='1')
		{
			if(HT[f].rchild)
			{
				f=HT[f].rchild;
			}
			else
			{
				ch=(char)f;
				fout<<ch;
				f=n;
				--i;
			}
		}
		else
		{
			if(HT[f].lchild)
			{
				f=HT[f].lchild;
			}
			else
			{
				ch=(char)f;
				fout<<ch;
				f=n;
				--i;
			}
		}
	}
	ch=(char)f;
	fout<<ch;
	fout.close();
}
