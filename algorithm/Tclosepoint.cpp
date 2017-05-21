#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;

double delta = INT_MAX;

void swap(double &x, double &y)
{
    double tmp = x;
    x = y;
    y = tmp;
}
//插入排序算法
void insert_sort(vector<double>&A, int p, int r)
{
    int i,j;
    double key = 0;
    for (i=p+1; i<=r; i++)
    {
        key = A[i];
        j = i - 1;
        while (j>=p && A[j]>key)
        {
            A[j+1] = A[j];//将A[j]往前移动
            j--;
        }
        A[j+1] = key;
    }
}


//将整型容器划分为两个部分
int partion(vector<double> &A,int p, int r)
{
    int count = p - 1;
    double key = A[r];

    for (int i=p; i<=r-1; i++)
    {
        if (A[i] < key)
        {
            count++;
            swap(A[count],A[i]);
        }
    }
    swap(A[count+1],A[r]);
    return count+1;
}

//取得中位数的中位数
double get_median(vector<double>&data, int p, int r)
{
    int i=0;
    int n = r - p + 1;            //获得原始数组数据个数
    int remains = n%5;
    int group_count = (n+4)/5;   //计算出五个元素一组的组数；

    //int *group_median = new int[group_count];
    vector<double> group_median(group_count);

    if (p==r)
    {
        return data[p];
    }
    //以下代码求出五个元素为一组的中位数
    if (0 == remains) //如果元素的个数正好可以分为以5个元素为单位的整数组
    {
        for (i=p; i<=r-4; i=i+5)
        {
            insert_sort(data, i, i+4);
            group_median[(i-p)/5] = data[p+2];
        }
    }
    else
    {
        for (i=p; i<=(r-remains-4);i=i+5)
        {
            insert_sort(data, i, i+4);
            group_median[(i-p)/5] = data[i+2];
        }
        //处理不够5个元素的组，改组开始的序号为r-remains+1，结束序号为r
        insert_sort(data,r-remains+1,r);
        group_median[group_count-1] = data[r-remains+1+remains/2];
    }
    if (group_count==1)
    {
        return group_median[0];
    }
    else
    {
        return get_median(group_median,0,group_count-1);
    }
    return 0;
}

/*就是因为get_position函数写错了，导致很久都没有能够发现错误，要仔细啊~~*/
int get_position(vector<double> &A, int p, int r, double key)
{
    for (int i=p; i<=r; i++)
    {
        if (A[i]==key)
        {
            return i;
        }
    }

    return -1;
}
//该函数是为了找到数组A中，第seq小的数
double select(vector<double> &A,int p, int r, int seq)
{
    //获得数组A的中位数的中位数，将其作为划分数组的支点
    double pivot_key = get_median(A, p, r);
    int pos = get_position(A,p,r,pivot_key);
    swap(A[pos],A[r]);
    int i = partion(A, p, r);
    int x = i - p + 1;
    if (seq == x)
    {
        return A[i];
    }
    else if (seq < x)
    {
        return select(A, p, i-1, seq);
    }
    else
    {
        return select(A, i+1, r, seq-x);
    }
}
class Point
{
public:
    double x;
    double y;
    Point(double x=0, double y=0)
    {
        this->x = x;
        this->y = y;
    }
    Point& operator=(const Point &p)
    {
        this->x = p.x;
        this->y = p.y;
        return *this;
    }
    Point(const Point &pp)
    {
        this->x = pp.x;
        this->y = pp.y;
    }
    friend ostream &operator<<(ostream &os, const Point & p)
    {
        os<<"("<<p.x<<"," << p.y << ")";

        return os;
    }

};
//将两个点交换
void swap_point(Point &p1, Point &p2)
{
    Point tmp = p1;
    p1 = p2;
    p2 = tmp;
}
//根据点容器的最后一个点，将点集合划分为两个部分
int partion_Point_Set(vector<Point> &p,int l, int r)
{
    int count = -1;
    double key = p[r].x;
    for (unsigned i=0; i<=p.size()-2; i++)
    {
        if (p[i].x<key)
        {
            count++;
            swap_point(p[i],p[count]);
        }
    }
    swap_point(p[count+1],p[r]);
    return count+1;
}
//获得两点间的距离
double Distance(const Point &p1, const Point &p2)
{
    double x = (p1.x - p2.x);
    double y= (p1.y - p2.y);
    double distance = sqrt(x*x+y*y);
    return distance;
}
//找到两个数的最小值
double min(double x, double y)
{
    if (x>y)
    {
        return y;
    }
    else
    {
        return x;
    }

}
//按照点的x坐标来检索点在容器中的位置
int get_point_position_x(const vector<Point> &p, int l, int r, double x_key)
{
    int ans1,ans2;
    for (int i=l; i<=r; i++)
    {
        if (p[i].x == x_key)
        {
            ans1 = i;
            break;
        }
    }
    for (int i=r; i>=l; i--)
    {
        if (p[i].x == x_key)
        {
            ans2 = i;
            break;
        }
    }
    if((ans1+ans2)/2>0)
        return (ans1+ans2)/2;
    else
        return -1;
}
//按照点的y坐标来检索点在容器中的位置
int get_point_position_y(const vector<Point> &p, int l, int r, double y_key)
{
    int ans1,ans2;
    for (int i=l; i<=r; i++)
    {
        if (p[i].y == y_key)
        {
            ans1 = i;
            break;
        }
    }
    for (int i=r; i>=l; i--)
    {
        if (p[i].y == y_key)
        {
            ans2 = i;
            break;
        }
    }
    if((ans1+ans2)/2>0)
        return (ans1+ans2)/2;
    else
        return -1;
}


//找到p中y坐标第order大的点
Point select_point(vector<Point> &p,int l, int r, int order)
{
    vector<double> point_y;
    for (int i=l; i<=r; i++)
    {
        point_y.push_back(p[i].y);
    }
    double key_y = select(point_y,0,point_y.size()-1,order);
    int position_y = get_point_position_y(p, 0, p.size()-1,key_y);
    return p[position_y];
}

double get_minimum_distance(vector<Point> &p,int l, int r,vector<Point> &result)
{

    int i=0,j=0;
    // cout<<r-l+1<<endl;
   if ((r-l+1)==2)//如果点数为两个
    {
        double ret = Distance(p[l],p[r]);

        if (ret < delta)
        {
        result[0]=p[l];
        result[1]=p[r];
        }


        return ret;
    }
    else if ((r-l+1)==3) //如果点数为3个
    {
        double tmp_dis1 = Distance(p[l],p[l+1]);
        double tmp_dis2 = Distance(p[l],p[l+2]);
        double tmp_dis3 = Distance(p[l+1],p[l+2]);
        double ret = min(min(tmp_dis1,tmp_dis2),tmp_dis3);

    if (ret <delta )
    {

        if (tmp_dis1 == ret)
        {
            result[0] = p[l];
            result[1] = p[l+1];
        }
        else if (tmp_dis2==ret)
        {
            result[0]=p[l];
            result[1]=p[l+2];
        }
        else
        {
            result[0]= p[l+1];
            result[1]= p[l+2];
        }
    }
        return ret;
    }
    else //大于三个点的情况
    {
        //求出点集p的x坐标和y坐标
        vector<double> Pointx;
        vector<double> Pointy;

        for (i=l; i<=r; i++)
        {
            Pointx.push_back(p[i].x);
            Pointy.push_back(p[i].y);
        }
        //找到点x坐标的中位数
        double x_median = select(Pointx,0,Pointx.size()-1,(Pointx.size()+1)/2);
        int point_median_pos = get_point_position_x(p,l,r,x_median);
        swap_point(p[point_median_pos],p[r]);
        //利用找到的中位数对点集进行划分
        int point_pivot_index = partion_Point_Set(p,l,r);
        //利用x坐标作为中位数，将点集合划分好后，递归的求中位数左边点集S1和右边点集合S2距离最小值；
        //考虑如何将距离最小的两个点保存下来
        cout<<point_pivot_index<<endl;

        double min_s1 = get_minimum_distance(p,l,point_pivot_index,result);
        //cout<<"23"<<endl;
        double min_s2 = get_minimum_distance(p,point_pivot_index+1,r,result);

        if (min_s1>min_s2)
        {
            delta = min_s2;
        }
        else
        {
            //result[0] = tmp_result1;
            //result[1] = tmp_result2;
            delta = min_s1;
        }
        //现在已经递归的求到了S1和S2中点集合最短距离，下面开始求S1和S2之间点之间的距离
        //找出点集合S2中，y坐标前六大的点,如果|S2|<6，则只需找出|S2|个点
        int size_s2 = (r-point_pivot_index<6)?r-point_pivot_index:6;
        vector<Point> S2;
        Point tmp;
        for (i=1;i<=size_s2;i++)
        {
            tmp = select_point(p,point_pivot_index+1,r,i);
            S2.push_back(tmp);
        }

        for (i=l; i<=point_pivot_index; i++)
        {
            for (j=0; j<size_s2; j++)
            {
                double d = Distance(p[i],S2[j]);
                if (d < delta)
                {
                    result[0]= p[i];
                    result[1]= S2[j];
                    delta = d;
                }
            }
        }

        return delta;
    }
}
int judge=0;
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
    quicksort(n,low,first-1);
    quicksort(n,first+1,high);
}

void getinput(vector<Point> &p)//
{
    fstream fin;
    fin.open("Data.txt",fstream::in);
    string str;
    Point pp;
    double sum[2067];

    int n=0;
    while(!fin.eof())
    {
        fin>>sum[n];
        //cout<<sum[n]<<endl;
        //getline(fin,str);
        ++n;
    }
    fin.clear();
    fin.close();
    quicksort(sum,0,n-1);
    for(int i=0;i<n;i++)
        cout<<sum[i]<<endl;


    int Pointnumber = n;
    for (int i=0; i<Pointnumber/2; i++)
    {
        pp.x=sum[i];
        pp.y=sum[i+n/2];
        p.push_back(pp);
        //cout<<pp.x<<pp.y<<endl;
    }

}
int main()
{

    vector<Point> result(2);
    vector<Point> input;
    getinput(input);

    double minimum_distance = get_minimum_distance(input,0,input.size()-1,result);
    cout << "最近的2个基站对是： "<<result[0] << " 和 " << result[1] << endl;
    cout << "距离为 : "<<minimum_distance <<"米"<< endl;
    minimum_distance = get_minimum_distance(input,0,input.size()-1,result);
    cout << "次最近的2个基站点是："<<result[0] << " 和 " << result[1] << endl;
    cout << "距离为 : "<<minimum_distance <<"米"<< endl;
    return 0;
}
