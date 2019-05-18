```
今天我们看到的阿里巴巴提供的任何一项服务后边都有着无数子系统和组件的支撑，子系统之间也互相依赖关联，

其中任意一个环节出现问题都可能对上游链路产生影响。小明做为新人接收到的第一个任务就是去梳理所有的依赖关系，

小明和每个系统的负责人确认了依赖关系，记录下调用对应系统的耗时，用这些数据分析端到端链路的数目和链路上最长的耗时。

输入： 小明搜集到的系统耗时和依赖列表

5  4   // 表示有5个系统和 4个依赖关系

3      // 调用1号系统耗时 3 ms

2      // 调用2号系统耗时 2 ms

10     // 调用3号系统耗时 10 ms

5      // 调用4号系统耗时 5 ms

7      //  调用5号系统耗时 7 ms

1 2    //  2号系统依赖1号系统

1 3    //  3号系统依赖1号系统

2 5    //  2号系统依赖5号系统

4 5    //  4号系统依赖5号系统

输出:  调用链路的数目 和最大的耗时， 这里有三条链路1->2->5，1->3， 4->5，最大的耗时是1到3的链路 3+10 = 13，无需考虑环形依赖的存在。

3  13
```


```cpp
#include <map>
#include <iostream>
#include <vector>
using namespace std;
 
void findPath(multimap<int, int> &m_sRelev, vector<double> &timeUsed,
    vector<int>& path, vector<vector<int> > &paths, int key, int &time, int &maxTime) {
 
    multimap<int, int>::iterator iter;
    time += timeUsed[key];
    path.push_back(key);
 
    if ((iter = m_sRelev.find(key)) != m_sRelev.end()) {//有孩子
        int n = m_sRelev.count(key);
        for (int j = 0; j < n; ++j, ++iter) {
            findPath(m_sRelev, timeUsed, path, paths, iter->second, time, maxTime);
        }
    } else {//子节点
        paths.push_back(path);
        if (maxTime < time)
            maxTime = time;
    }
 
    time -= timeUsed[key];
    path.pop_back();
}
int main()
{
    int numSystem, numRelev;
    while (cin >> numSystem >> numRelev) {
        vector<double> timeUsed(numSystem+1);//保存时间
        bool* isHead = new bool[numSystem + 1];//该系统是否要依赖其它系统
        memset(isHead, 1, numSystem + 1);//首先全部置为true
        multimap<int, int> m_sRelev;//依赖关系
        int maxTime = 0;
        vector<vector<int> > paths;
        for (int i = 1; i <= numSystem; ++i) {
            double time;
            cin >> time;
            timeUsed[i] = time;
        }
        for (int i = 0; i < numRelev; ++i) {
            int sysMaster, sysSlave;
            cin >> sysMaster >> sysSlave;
            m_sRelev.insert(make_pair(sysMaster, sysSlave));
            isHead[sysSlave] = false;//依赖其它系统，那么不能作为链路的开端
        }
 
        for (int i = 1; i <= numSystem; ++i) {
            if (isHead[i]) {//如果是链路的开端
                int time = 0;
                vector<int>path;
                findPath(m_sRelev, timeUsed, path, paths, i, time, maxTime);
            }
        }
        delete[] isHead;
        cout << paths.size() << " " << maxTime << endl;
    }
 
 
    return 0;
}
 


```
