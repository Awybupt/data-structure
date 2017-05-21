#include <iostream>
#include <cstdlib>
#include <fstream>
#include <windows.h>
using namespace std;

int charge=0;

void Merge(double a[],double temp[],int left,int mid,int right)
{
    int i=left,j=mid+1,k=left;

    while(i<mid+1&&j<right+1)
    {
        if(a[i]<=a[j])
        {
            temp[k++]=a[i++];

        }
        else{
            temp[k++]=a[j++];

        }
    }
    if(i<mid+1)
    {
        while(i<mid+1)
            temp[k++]=a[i++];
    }
    else{
        while(j<right+1)
            temp[k++]=a[j++];
    }
    for(int i=left;i<=right;i++)
        a[i]=temp[i];
}

void mergesort(double a[],double temp[],int left,int right)//µÝ¹é
{
     if(left<right)
     {
         int mid;
         ++charge;
         mid=(left+right)/2;
         mergesort(a,temp,left,mid);
         mergesort(a,temp,mid+1,right);
         Merge(a,temp,left,mid,right);

     }
}
void mergg(double a[],int le)//·ÇµÝ¹é
{
    int i,ln,lx,rn,rx,next;
    int *tmp=(int*)malloc(sizeof(int)*le);

    for(i=1;i<le;i*=2)
    {
        for(ln=0;ln<le-i;ln=rx)
        {
            rn=lx=ln+i;
            rx=lx+i;

            if(rx>le)
                rx=le;
            next=0;
            while(ln<lx&&rn<rx)
                tmp[next++]=a[ln]>a[rn]?a[rn++]:a[ln++];
            while(ln<lx)
                a[--rn]=a[--lx];
            while(next>0)
                a[--rn]=tmp[--next];
        }
    }
    free(tmp);
    //cout<<"success!";
}

int main()
{
    fstream fin;
    fin.open("k-dist.txt",fstream::in);                         //读取图书基本信息
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

    double temp[n];

    LARGE_INTEGER freq_;
    QueryPerformanceFrequency(&freq_);

    LARGE_INTEGER begin_time;
    LARGE_INTEGER end_time;
    QueryPerformanceCounter(&begin_time);
    mergesort(a,temp,0,n);
    QueryPerformanceCounter(&end_time);

    double ns_time = (end_time.QuadPart - begin_time.QuadPart) * 1000000.0 / freq_.QuadPart;

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
        cout<<endl;
        cout<<"recurrence time:"<<(ns_time)<<"us!"<<endl;
    QueryPerformanceCounter(&begin_time);
     mergg(a,n);
    QueryPerformanceCounter(&end_time);
     ns_time = (end_time.QuadPart - begin_time.QuadPart) * 1000000.0 / freq_.QuadPart;
        cout<<"anti_recurrence time:"<<(ns_time)<<"us!"<<endl;
    //cout<<charge;
    return 0;
}
