#include <iostream>
#include <windows.h>
#include <fstream>

int bdep=0,tdep=0;

using namespace std;

double DoubleSelect(double n[],int low,int high,int choice)//一分为2
{
    if(low>=high)
    {
            return n[low];
    }
    int first=low,last=high;
    //cout<<first<<last<<endl;

    int xtemp=(int)rand()%(high-low)+low;//随机产生的地方！！！

    double key=n[xtemp];//划分依据
    while(first<last)
    {
        while(first<last&&n[last]>=key)
            --last;
        n[xtemp]=n[last];
        xtemp=last;
        while(first<last&&n[first]<=key)
            ++first;
        n[xtemp]=n[first];
        xtemp=first;
    }
    n[xtemp]=key;
    //for(int i=low;i<=high;i++)
       // cout<<n[i]<<endl;
        //cout<<xtemp<<n[xtemp]<<"fff"<<endl;
    //++sortdeep;
    ++bdep;
    if(xtemp>=choice)
        return DoubleSelect(n,low,xtemp,choice);
    else
        return DoubleSelect(n,xtemp+1,high,choice);
}

double TribleSelect(double n[],int low,int high,int choice)//一分为2
{
    if(low>=high)
    {
        if(low<=choice)
            return n[choice];
        else
            return -1;//查找失败，五元素
    }
    int first=low,last=high;
    //cout<<first<<last<<endl;

    int xtemp=(int)rand()%(high-low)+low;//随机产生的地方！！！

    double key=n[xtemp];//划分依据

    while (first<last)
    {
        while(first<last&&n[last]>=key)
            --last;
        n[xtemp]=n[last];
        xtemp=last;
        while(first<last&&n[first]<=key)
            ++first;
        n[xtemp]=n[first];
        xtemp=first;
    }
    n[xtemp]=key;
    //for(int i=low;i<=high;i++)
       //cout<<n[i]<<endl;
        //cout<<xtemp<<n[xtemp]<<"fff"<<endl;
    //++sortdeep;
    ++tdep;
    if(choice==xtemp)
        return key;
    if(xtemp>choice)
        return TribleSelect(n,low,xtemp-1,choice);
    else
        return TribleSelect(n,xtemp+1,high,choice);
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
    double b[1044];
    for(int i=0;i<n;i++)
    {
        b[i]=a[i];
    }
    fin.clear();
    fin.close();

    int choice1;
        cout<<"请输入要选择的次序:";
        cin>>choice1;
        cout<<"the dresult is"<<DoubleSelect(a,0,n-1,choice1-1)<<endl;

        cout<<"the tresult is"<<TribleSelect(b,0,n-1,choice1-1)<<endl;
        cout<<"three sort deep:"<<tdep<<"\ntwo sort deep:"<<bdep<<endl;


    return 0;
}
