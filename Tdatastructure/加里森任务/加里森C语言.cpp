/*��n������ɭ�����ӵĶ�ԱҪը�����˵�һ������⣬˭������ȥ���ӳ�����ɭ�������ֻ������İ취�������ĸ�սʿȥִ������
  �������£����ǰһ��սʿû���������Ҫ����һ��սʿ��ȥ���ָ�ÿ��սʿ��һ���ţ����Χ����һȦ������ĳһ�����
  Ϊx��սʿ��ʼ������������yʱ����Ӧ��սʿ��ȥִ�������Ҵ�սʿ���ٲμ���һ�ּ����������սʿû��������ٴ���һ
  ��սʿ��ʼ��������������yʱ����սʿ����ȥִ�������Դ����ƣ�ֱ���������Ϊֹ��
  ����ɭ�����ǲ�Ը��ȥ�ģ��������ɭΪ1�ţ��������һ����Ϊ����ɭ֧�У����n,x,y�����������ʱ,����ɭ��������������ȥִ������;*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node * next;
}linknode, * link;

void Delete(link & pre,link & p,link & head);                       //ɾ������y�Ķ�Ա 
bool Judgenum(link head);                           //�ж�ѭ�������л��м�����Ա�����ֻ��һ������false 

main()
{
	link head,p,pre;
	int n,x,y,i;
	printf("���������ɭ�����ӵĶ�Ա����");
    scanf("%d",&n);
	printf("�������һ�������Ķ�Ա���x��");
	scanf("%d",&x);
	printf("����������y�Ķ�Աִ�������yֵ��");
	scanf("%d",&y);
	
	//����һ��ѭ������
    head=(link)malloc(sizeof(linknode));
    p=head;
    for(i=0;i<n;++i)
    { 
    	p->next=(link)malloc(sizeof(linknode));
    	p=p->next;
      	p->data=i+1;
    }
    p->next=head->next;
    
	for(p=head,i=0;i<x;++i,p=p->next)        //ָ��pָ���˵�x����Ա��preָ��p��ǰһ����Ա 
	    pre=p;
	
	printf("ȥִ������Ķ�Ա�У�");
	while(Judgenum(head))
	{
	    for(i=1;i<y;++i,p=p->next)               //ָ��pָ��������y�Ķ�Ա��Ҳ����Ҫȥִ������Ķ�Ա��preָ��p��ǰһ����Ա 
		    pre=p;
		printf("%d ",p->data);
     	Delete(pre,p,head);                           //ɾ��һ����Ա��pָ����һ����Ա��preָ���Ա���� 
     	
    }
    printf("\n");
    
    if(head->next->data==1)
        printf("Ư��������ɭ�ӳ�����������\n");
    else
        printf("���ź�������ɭ�ӳ���������ִ������\n");
        
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

