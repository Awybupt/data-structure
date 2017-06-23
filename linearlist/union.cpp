/***
利用两个线性表LA，LB合并成为一个新的线性表LA
***/
class linear_list{
    int L[n];
    void InitList(int &L);//构造一个空的线性表L
    void DestroyList(int &L);//销毁一个以&L为首地址的线性表
    void ClearList(int &L);//将&L为首地址的线性表重置为空表
    bool ListEmpty(int &L);//如果以L为首地址的线性表是空表，返回true，否则返回FALSE
    int ListLength(int &L);//返回线性表L的长度
    void GetElem(int L[],int i,int &e);//用e返回线性表L中第i个值
    int LocateElem(int L[],int e,compare());//返回l中第一个与e满足compare()关系的元素的位序，否则返回0
    void PriorElem(int L[],int cur_e,int pre_e);//如果cur是l的数据元素，且不是第一个，返回他的前驱
    void NextElem(int L[],int cur_e,int next_e);// 如果cur是l的数据元素，且不是最后一个，返回他的后继
    void ListInsert(int &L,int i,int e);//在l中第i个元素之前插入新的数据元素e,l的长度+1
    void ListDelete(int &L,int i,int &e)//在l中第i个元素删除，用e返回删除的元素的值,l的长度-1 
    void ListTraverse(int L[],void visit());//对l中每一个元素调用函数visit（）                                                                                                                  
}   
void union(List &La,List Lb)
{
    La_len=ListLength(La);
    Lb_len=ListLength(La);//求线性表的长度
    for(int i=1;i<=Lb_len;i++){
        GetElem(Lb,i,e);//get a element from Lb
        if(!locateElem(La,e,equal))
            ListInsert(La,++La_len,e);//if not exist,insert Lb to La
    }
}
