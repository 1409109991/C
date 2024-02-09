#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct linknode
{
	DataType data;
	struct linknode *next;
}LinkList;

LinkList *InitList()
{ //��ʼ��������
	LinkList *head;
	head=(LinkList*)malloc(sizeof(LinkList));
	head->next=NULL;
	return head;
}

void CreateListH(LinkList *head,int n)
{/*	ͷ�巨����������*/
	LinkList *s;
	int i;
	printf("������%d������:",n);
	for(i=0;i<n;i++)
	{
		s=(LinkList *)malloc(sizeof(LinkList));
		scanf("%d",&s->data);
		s->next=head->next;
		head->next=s;
	}
	printf("������������ɹ�!");
}

void CreateListL(LinkList *head,int n)
{/*	β�巨����������*/
	LinkList *s,*last;
	last=head;
	printf("������%d������:",n);
	for (int i = 0; i < n; i++)
	{
		s=(LinkList *)malloc(sizeof(LinkList));
		scanf("%d",&s->data);
		s->next=NULL;
		last->next=s;
		last=s;
	}
	printf("������������ɹ�!");
}

int LengthList(LinkList *head)
{
	LinkList *p=head->next;
	int j=0;
	while(p!=NULL)
	{
		p=p->next;
		j++;
	}
	return j;
}

void Locate(LinkList *head,DataType x)
{//��ֵ����
	int j=1;
	LinkList *p;
	p=head->next;
	while(p!=NULL&&p->data!=x)
	{
		p=p->next;
		j++;
	}
	if(p!=NULL)
		printf("��%d��Ԫ��Ϊ%d",j,p->data);
	else
		printf("δ�ҵ���Ԫ��");
}

void SearchList(LinkList *head,int i)
{//��λ�ò���
	LinkList *p;
	int j=0;
	if(i>LengthList(head))
		printf("λ�ô���������û�и�λ��.");
	while (p->next!=NULL&&j<i)
	{
		p=p->next;
		j++;
	}
	if(j==i)
		printf("�ڵ�%dλ�ϵ�Ԫ��ֵΪ%d.",i,p->data);			
}

void InsList(LinkList *head,int i,DataType x)
{//��λ�ò���Ԫ��
	int j=0;
	LinkList *p,*s;
	p=head;
	while(p->next!=NULL&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(p!=NULL)
	{
		s=(LinkList *)malloc(sizeof(LinkList));
		s->data=x;
		s->next=p->next;
		p->next=s;
		printf("����ɹ�!");
	}
	else
		printf("����λ�ô���!");
}

void DelList(LinkList *head,int i)
{
	int j=0;
	DataType x=0;
	LinkList *p=head,*s;
	while (p->next!=NULL&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(p->next!=NULL && j==i-1)
	{
		s=p->next;
		x=s->data;
		p->next=s->next;
		free(s);
		printf("ɾ���ɹ�!");
	}
	else
		printf("ɾ��λ�ô���!");
}

void DispList(LinkList *head)
{
	LinkList *p;
	p=head->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}

void Menu()
{
    printf("********************************************\n");
    printf("|1.����������							\n");
    printf("|2.����Ԫ��								\n");
    printf("|3.ɾ��Ԫ��								\n");
    printf("|4.��λ�ò���Ԫ��							 \n");
    printf("|5.��Ԫ��ֵ�������ڱ��е�λ��				  \n");
    printf("|6.��˳���ĳ���							 \n");
    printf("|0.����									\n");
    printf("|*******************************************\n");
    printf("|������˵���(0-6):						\n");
    printf("********************************************\n");
    printf("*********** ���ݳ� 202220105004 ************\n");
    printf("********************************************\n");
}

int main()
{
	LinkList head;
	int i,n;
	DataType x;
	InitList(&head);
	while(1)
	{
		Menu();
		scanf("%d",&i);
		switch(i)
		{
			case 1:printf("�������:");
					scanf("%d",&n);
					CreateListH(&head,n);
					break;
			case 2:printf("����������Ԫ�غ�λ��:");
					scanf("%d%d",&x,&i);
					InsList(&head,i,x);
					break;
			case 3:printf("������ɾ��Ԫ��:");
					scanf("%d",&x);
					DelList(&head,x);
					break;
			case 4:printf("���������Ԫ��:");
					scanf("%d",&x);
					SearchList(&head,x);
					break;
			case 5:printf("������Ҫ���ҵ�ֵ:");
					scanf("%d",&x);
					Locate(&head,x);
					break;
			case 6:printf("˳���ĳ���Ϊ:");
					printf("%d\n",LengthList(&head));
					break;
			case 0:exit(0);
			default:printf("�������,����������!\n");
        }
	}
}
