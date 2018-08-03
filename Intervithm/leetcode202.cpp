class Solution {
public:
    typedef struct history{
        int hi;
        struct history * next;
    }his;
    his* create_list_node(int data)
    {
        his *node = nullptr ;
        node = new(his);//(his *)malloc(sizeof(his));
        if(node == nullptr){
            printf("malloc fair!\n");
        }
        memset(node,0,sizeof(his));
        node->hi = data ;
        node->next = NULL ;
        return node ;
    }
    his* head = create_list_node(-1);
    //his* head=&ll;
    bool isCalculate(int n)
    {
        his * temp=head;
        while((*temp).next!=nullptr)
        {
            if ((*temp).hi==n)
                return false;
            temp=(*temp).next;
        }
        if((*temp).hi==n)
            return false;
        else
            temp->next=create_list_node(n);
        return true;
    }
    bool isHappy(int n) {
        if(0 == n)
            return false;
        while(isCalculate(n))
        {
            int midans=0;
            for(;n>0;n/=10)
            {
                int ts=n%10;
                midans+=ts*ts;
            }
            if (midans==1)
                return true;
            return isHappy(midans);
        }
        return false;
    }
};
