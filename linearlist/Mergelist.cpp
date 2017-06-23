/***
已知线性表La和Lb中的元素按值非递减排列
归并La和Lb得到新的线性表Lc，使Lc的数据元素也按非递减排列
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


void MergeList(List La,List Lb,List &Lc){
    InitList(Lc);
    int i=1;
    int j=1;
    int k=0;
    int La_len=ListLength(La);
    int Lb_len=ListLength(Lb);
    while((i<=La_Len)&&(j<=Lb_len))
    {
        GetElem(La,i,ai);
        GetElem(Lb,j,bj);
        if(ai<=bj){
            ListInsert(Lc,++k,ai);
            ++i;
        }
        else{
            ListInsert(Lc,++k,bi);
            ++j;
        }
    }
    while(i<=La_len){
        GetElem(La,i++,ai);
        ListInsert(Lc,++k,ai);
    }
    while(i<=La_len){
        GetElem(La,i++,ai);
        ListInsert(Lc,++k,ai);
    }
}
