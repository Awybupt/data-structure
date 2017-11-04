/*有n个加里森敢死队的队员要炸掉敌人的一个军火库，谁都不想去，队长加里森决定用轮回数数的办法来决定哪个战士去执行任务。
  规则如下：如果前一个战士没完成任务，则要再派一个战士上去。现给每个战士编一个号，大家围坐成一圈，随便从某一个编号
  为x的战士开始计数，当数到y时，对应的战士就去执行任务，且此战士不再参加下一轮计数。如果此战士没完成任务，再从下一
  个战士开始数数，被数到第y时，此战士接着去执行任务。以此类推，直到任务完成为止。
  加里森本人是不愿意去的，假设加里森为1号，请你设计一程序为加里森支招，求出n,x,y满足何种条件时,加里森能留到最后而不用去执行任务;*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node * next;
}linknode, * link;

void Delete(link & pre,link & p,link & head);                       //删除数到y的队员 
bool Judgenum(link head);                           //判断循环链表中还有几个队员，如果只有一个返回false 

main()
{
	link head,p,pre;
	int n,x,y,i;
	printf("请输入加里森敢死队的队员数：");
    scanf("%d",&n);
	printf("请输入第一个数数的队员编号x：");
	scanf("%d",&x);
	printf("请输入数到y的队员执行任务的y值：");
	scanf("%d",&y);
	
	//创建一个循环链表
    head=(link)malloc(sizeof(linknode));
    p=head;
    for(i=0;i<n;++i)
    { 
    	p->next=(link)malloc(sizeof(linknode));
    	p=p->next;
      	p->data=i+1;
    }
    p->next=head->next;
    
	for(p=head,i=0;i<x;++i,p=p->next)        //指针p指向了第x个队员，pre指向p的前一个队员 
	    pre=p;
	
	printf("去执行任务的队员有：");
	while(Judgenum(head))
	{
	    for(i=1;i<y;++i,p=p->next)               //指针p指向了数到y的队员，也就是要去执行任务的队员，pre指向p的前一个队员 
		    pre=p;
		printf("%d ",p->data);
     	Delete(pre,p,head);                           //删除一个队员，p指向下一个队员，pre指向队员不变 
     	
    }
    printf("\n");
    
    if(head->next->data==1)
        printf("漂亮！加里森队长留了下来！\n");
    else
        printf("很遗憾，加里森队长得留下来执行任务。\n");
        
    p=head->next;
    free(head);
    free(p);
}


bool Judgenum(link head)
{
	link p;
	p=head->next;
	if(p->next==head->next)
	    return false;
	else
	    return true;
}

void Delete(link & pre,link & p,link & head)
{
	link ptr=p;
	if(p==head->next);
	    head->next=p->next;
	pre->next=p->next;
    p=p->next;
   	free(ptr);
}

