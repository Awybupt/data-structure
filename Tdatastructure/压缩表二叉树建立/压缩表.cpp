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

void Info(int *s);          //ͳ���ı��ĵ�ÿ���ַ��ĳ��ִ���ÿ����һ�Σ���Ӧ���±�Ϊ��ASSIC��ֵ������ֵ��һ
void HuffmanCoding(HuffmanTree & HT,HuffmanCode & HC,int *w,int n);  //���������뺯��
void Select(HuffmanTree HT,int k,int &  s1,int & s2);   //��HT��1...i-1��ѡ��parentΪ0��Ȩֵ��С��������㣬����ŷֱ�Ϊs1��s2
void BinFileGen(HuffmanCode HC);               //���ɶ������ļ�����
void Print(HuffmanCode HC);
void codee(HuffmanCode HC,int *Tail);                    //ѹ���洢
void Decode(HuffmanCode HC,HuffmanTree HT,int n,int Tail);             //���뺯�� 

main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	int i,k=0,Tail,m;
	int s[256]={0};
	cout<<"�Ƿ����ڿ�ʼѹ���ļ��� ��1.�� 0.��"<<endl;
	cin>>m;
	if(m==1)
	{
		Info(s);    //����ͳ���ַ��ĳ��ִ���
	    HuffmanCoding(HT,HC,s,256);
    	codee(HC,&Tail);
    	cout<<"ѹ���ɹ����ѽ�file.txtѹ���洢��FILE.txt��"<<endl;
	}
	else
	{
		cout<<"ѹ��ʧ�ܣ�"<<endl; 
		exit(0);
	}
	cout<<"�Ƿ��ѹ���ļ��� ��1.�� 0.��"<<endl;
	cin>>m;
	if(m==1)
	{
		Decode(HC,HT,511,Tail);
		cout<<"��ѹ���ɹ����ѽ�FILE.txtѹ���洢��file1.txt��"<<endl;
	}
	else
	{
		cout<<"��ѹʧ�ܣ�"<<endl;
		exit(0);
	}
}

void Info(int s[])                        //ͳ���ַ����ִ���
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

void HuffmanCoding(HuffmanTree & HT,HuffmanCode & HC,int *w,int n)  //����������
{
	if(n<=1) return;
	int m=2*n-1;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));             //0�ŵ�Ԫδ����
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
    {                       //����������
     	Select(HT,i-1,s1,s2);              //��HT��1...i-1��ѡ��parentΪ0��Ȩֵ��С��������㣬����ŷֱ�Ϊs1��s2
     	HT[s1].parent=i;
     	HT[s2].parent=i;
     	HT[i].lchild=s1;
     	HT[i].rchild=s2;
     	HT[i].weight=HT[s1].weight+HT[s2].weight;
    }

     //��Ҷ�ӽ�㵽��������ÿ���ַ��Ĺ���������
	HC=(HuffmanCode)malloc((n+1)*sizeof(char*));      //����n���ַ������ͷָ������
	char *cd=(char*)malloc(n*sizeof(char));            //��������ַ����ռ�
	cd[n-1]='\0';
	int c,f;                                  //���������
	for(i=1;i<=n;++i)                                 //����ַ����������
	{
		int start=n-1;                                    //���������λ��
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
		{
			if(HT[f].lchild==c)
			    cd[--start]='0';
                else
			    cd[--start]='1';
		}
		HC[i]=(char*)malloc((n-start)*sizeof(char));          //Ϊ��i���ַ��������ռ�
		strcpy(HC[i],&cd[start]);                  //��cd�����봮��HC
	}
	free(cd);
}

void Select(HuffmanTree HT,int k,int & s1,int & s2)     //��HT��1...i-1��ѡ��parentΪ0��Ȩֵ��С��������㣬����ŷֱ�Ϊs1��s2
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
	fin.open("file.txt");                     //file.txt��������ı��ļ���FILE.txt��ѹ���洢���ļ� 
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
