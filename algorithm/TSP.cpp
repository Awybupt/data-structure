#include <iostream>
#include <memory.h>//或者也可以是string.h
#include <fstream>

using namespace std;
const int M=20;

class Traveling{
    friend double TSP(double**,int*,int,double);//tsp算法
private:
	void backTrack(int i);
	int city;    //城市数目
	int* x;     //当前旅行策略
	int* bestx; //最优旅行策略
	double** a;
	double current_cost;//当前代价
	double bestc;   //存放最小代价值
	double NoEdge;  //不连通的标志，这里设为-1
};

void Traveling::backTrack(int i)
{
	if(i==city){
		if(a[x[city-1]][x[city]]!=NoEdge &&
			a[x[city]][1]!=NoEdge &&
			(current_cost+a[x[city-1]][x[city]]+a[x[city]][1]<bestc || bestc==NoEdge))
		{
			bestc=current_cost+a[x[city-1]][x[city]]+a[x[city]][1];
			for(int j=1;j<=city;j++)
				bestx[j]=x[j];
		}
	}else{
		for(int j=1;j<=city;j++)
			if(a[x[i-1]][x[j]]!=NoEdge &&
				(current_cost+a[x[i-1]][x[i]]<bestc || bestc==NoEdge))
			{
				swap(x[i],x[j]);
				current_cost+=a[x[i-1]][x[i]];
				backTrack(i+1);
				current_cost-=a[x[i-1]][x[i]];
				swap(x[i],x[j]);
			}
	}
}




double TSP(double** a,int* bestPath,int city,double NoEdge)
{
	Traveling Y;
	Y.x=new int[city+1];
	for(int i=1;i<=city;i++)
		Y.x[i]=i;
	Y.a=a;
	Y.city=city;
	Y.bestc=NoEdge;
	Y.bestx=bestPath;
	Y.current_cost=0;
	Y.NoEdge=NoEdge;
	Y.backTrack(2);
	delete[] Y.x;
/*
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<M;j++)
		{
			cout<<"  "<<a[i][j];
		}
		cout<<endl;
	}*/
	cout<<"The path: ";
	for(int i=1;i<=city;i++)
	{
		cout<<" "<<Y.bestx[i];
	}
	cout<<endl;
	return Y.bestc;
}

int main(void)
{
	double **smap;
	int * bestpath;

	smap = new double* [M];
	for(int i=0;i<M;i++)
        smap[i] = new double[M];
    ifstream fin("rec3.txt");
     for(int i=0;i<M;i++)
	{
		for(int j=0;j<M;j++)
		{
			fin>>smap[i][j];
			if(smap[i][j]>=99998)
                smap[i][j]=-1;
			//cout<<smap[i][j];
		}
	}
	fin.close();
	bestpath = new int[M];
	memset(bestpath,0,sizeof(bestpath));
	cout<<"The min cost: "<<TSP(smap,bestpath,M-1,-1)<<endl;
	return 0;
}
