#include <iostream>
#include <windows.h>
#include <fstream>
int sortdeep=0;//记录递归深度
int judge=0;

using namespace std;

void quicksort(double n[],int low,int high)//固定
{
    for(int i=low;i<high;i++)
    {
        if(n[i]>n[i+1])
           break;
        if(i==high)
           return;
    }
    if(low>=high)
    {
        return ;
    }
    int first=low,last=high;
    double key=n[first];//划分依据

    while (first<last)
    {
        while(first<last&&n[last]>=key)
            --last;
        n[first]=n[last];
        while(first<last&&n[first]<=key)
            ++first;
        n[last]=n[first];
    }
    n[first]=key;
    if(low==first-1)
        judge=1;
    if(low!=first-1&&judge==0)
    ++sortdeep;
    quicksort(n,low,first-1);
    quicksort(n,first+1,high);
}
void Quicksort(double n[],int low,int high)//随机
{
    for(int i=low;i<high;i++)
    {
        if(n[i]>n[i+1])
           break;
        if(i==high)
           return;
    }
    if(low>=high)
    {
        return ;
    }
    int first=low,last=high;
    int xtemp=(int)rand()%(high-first)+first;//随机产生的地方！！！
    double key=n[xtemp];//划分依据
    //cout<<xtemp<<endl;
    double temp=n[first];
    n[first]=n[xtemp];
    n[xtemp]=temp;
    while (first<last)
    {
        while(first<last&&n[last]>=key)
            --last;
        n[first]=n[last];
        while(first<last&&n[first]<=key)
            ++first;
        n[last]=n[first];
    }
    n[first]=key;
    //sortdeep++;
    Quicksort(n,low,first-1);
    Quicksort(n,first+1,high);
}
int main()
{
    fstream fin;
    fin.open("k-dist.txt",fstream::in);
    string str;
    double a[1044];
    int n=0;
    while(!fin.eof())
    {
        fin>>a[n];
        getline(fin,str);
        ++n;
    }

    fin.clear();
    fin.close();
    LARGE_INTEGER freq_;
    QueryPerformanceFrequency(&freq_);

    LARGE_INTEGER begin_time;
    LARGE_INTEGER end_time;
    QueryPerformanceCounter(&begin_time);
    quicksort(a,0,n-1);
    QueryPerformanceCounter(&end_time);
    double ns_time = (end_time.QuadPart - begin_time.QuadPart) * 1000000.0 / freq_.QuadPart;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
        cout<<endl;
        cout<<"非随机的时间:"<<ns_time<<"us!"<<endl;
    QueryPerformanceCounter(&begin_time);
    Quicksort(a,0,n-1);
    QueryPerformanceCounter(&end_time);
    ns_time = (end_time.QuadPart - begin_time.QuadPart) * 1000000.0 / freq_.QuadPart;
        cout<<"随机的时间:"<<(ns_time)<<"us!"<<endl;
    //cout<<charge;
    cout<<"递归深度："<<sortdeep<<endl;
    return 0;
}
