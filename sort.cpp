//第一次写排序算法
#include <iostream>
#include<cstdio>
using namespace std;

void swap_array(int arraynum[],int i,int j)//交换函数
{
    int tmp=arraynum[i];
    arraynum[i]=arraynum[j];
    arraynum[j]=tmp;
}

void InsertSort(int arraynum[],int n)//插入排序
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(arraynum[j]<arraynum[j-1])
                swap_array(arraynum,j,j-1);
            else
                break;
        }
    }
}

void BubbleSort(int arraynum[],int n)//冒泡排序
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=n-1;j>i;j--)
        {
            if(arraynum[j]<arraynum[j-1])
                swap_array(arraynum,j,j-1);
        }
    }
}

void ShellSort(int arraynum[],int n)//希尔排序
{
    for(int Delta=n/2;Delta>0;Delta/=2)
    {
        for(int i=0;i<Delta;i++)
        {
            for(int j=Delta+i;j<n;j+=Delta)
            {
                for(int k=j;k>0;k-=Delta)
                {
                    if(arraynum[k]<arraynum[k-1])
                        swap_array(arraynum,k,k-1);
                }
            }
        }
    }
}

void quickSort(int arraynum[],int left,int right)
{
    if(left>right)
        return;
    int first=left;
    int last=right;
    int key=arraynum[first];
    while(first<last)
    {
        while(first<last&&arraynum[last]>=key)
            --last;
        arraynum[first]=arraynum[last];
        while(first<last&&arraynum[first]<=key)
            ++first;
        arraynum[last]=arraynum[first];
    }
    arraynum[first]=key;
    quickSort(arraynum,left,first-1);
    quickSort(arraynum,first+1,right);
}

void QuickSort(int arraynum[],int n)//快速排序
{
    quickSort(arraynum,0,n);
}

void Merge(int source[],int temp[],int start,int mid,int endi)
{
    int i=start,j=mid+1,k=start;
    while(i!=mid+1&&j!=endi+1)
    {
        if(source[i]<=source[j])
            temp[k++]=source[i++];
        else
            temp[k++]=source[j++];
    }
    if(i<=mid)
    {
        while(i<=mid)
            temp[k++]=source[i++];
    }
    else
    {
        while(j<=endi)
            temp[k++]=source[j++];
    }
    for(i=start;i<=endi;i++)
        source[i]=temp[i];
}
void mergesort(int arraynum[],int temp[],int start,int endin)
{
     int mid;
     if(start<endin)
     {
         mid=(start+endin)/2;
         mergesort(arraynum,temp,start,mid);
         mergesort(arraynum,temp,mid+1,endin);
         Merge(arraynum,temp,start,mid,endin);

     }
}
void MergeSort(int arraynum[],int n)//归并排序
{
    int b[100];
    mergesort(arraynum,b,0,n-1);
}

void heapadjust(int arraynum[],int i,int length)
{
    int nchild;
    int ntemp;
    for(;2*i+1<length;i=nchild)
    {
        nchild=2*i+1;
        if(nchild<length-1&&arraynum[nchild+1]>arraynum[nchild])++nchild;
        if(arraynum[i]<arraynum[nchild])
        {
            ntemp=arraynum[i];
            arraynum[i]=arraynum[nchild];
            arraynum[nchild]=ntemp;
        }
        else
            break;
    }
}
void HeapSort(int arraynum[],int n)//堆排序
{
    int i;
    for(i=n/2-1;i>=0;--i)
    {
        heapadjust(arraynum,i,n);
    }
    for(i=n-1;i>0;--i)
    {
        arraynum[i]=arraynum[0]^arraynum[i];
        arraynum[0]=arraynum[0]^arraynum[i];
        arraynum[i]=arraynum[0]^arraynum[i];
        heapadjust(arraynum,0,i);
    }
}

int maxb(int arraynum[],int n)//基数排序求最大位
{
    int d=1;
    int p=10;
    for(int i=0;i<n;++i)
    {
        while(arraynum[i]>=p)
        {
            p*=10;
            ++d;
        }
    }
    return d;
}

void RadixSort(int arraynum[],int n)//基数排序
{
    int d=maxb(arraynum,n);
    int *tmp=new int[n];
    int *countnum=new int[10];
    int i,j,k;
    int radix=1;
    for(i=1;i<=d;i++)
    {
        for(j=0;j<10;j++)
            countnum[j]=0;
        for(j=0;j<n;j++)
        {
            k=(arraynum[j]/radix)%10;
            countnum[k]++;
        }
        for(j=1;j<10;j++)
        {
            countnum[j]=countnum[j-1]+countnum[j];
        }
        for(j=n-1;j>=0;j--)
        {
            k=(arraynum[j]/radix)%10;
            tmp[countnum[k]-1]=arraynum[j];
            countnum[k]--;
        }
        for(j=0;j<n;j++)
            arraynum[j]=tmp[j];
        radix=radix*10;
    }
    delete []tmp;
    delete []countnum;
}
void CocktailSort(int arraynum[],int n)//搅拌排序
{
    for(int i=0;i<(n-1)/2+1;i++)
    {
        if(i%2==0)
        {
            for(int j=n-1;j>i;j--)
            {
                if(arraynum[j]<arraynum[j-1])
                    swap_array(arraynum,j,j-1);
            }
        }
        else
        {
            for(int j=i;j<n-1;j++)
            {
                if(arraynum[j]>arraynum[j+1])
                    swap_array(arraynum,j,j+1);
            }
        }
    }
}


int main()
{
    int arraynum[10]={2,34,12,98,6,23,45,299,38,23};
    MergeSort(arraynum,10);
    for(int i=0;i<10;i++)
        cout<<arraynum[i]<<" ";
    cout<<endl;
    return 0;
}
