#include<stdio.h>
#include<stdlib.h>

typedef int DataType;

typedef struct qnode
{
   DataType data;
   struct qnode *next;
} LinkListQ;

typedef struct
{
   LinkListQ *front,*rear;
} LinkQueue;

LinkQueue *InitQueue()
{
   LinkQueue *Q;
   LinkListQ *p;
   Q = (LinkQueue *)malloc(sizeof(LinkQueue));
   p = (LinkListQ *)malloc(sizeof(LinkListQ));
   Q->front = p;
   Q->rear = p;
   return Q;
}

int EmptyQueue(LinkQueue *Q)
{
   if(Q->front==Q->rear)
       return 1;
   else
       return 0;
}

void InQueue(LinkQueue *Q,DataType x)
{
   LinkListQ *p;
   p = (LinkListQ *)malloc(sizeof(LinkListQ));
   p->data = x;
   p->next = NULL;
   Q->rear->next = p;
   Q->rear = p;
}

int DeQueue(LinkQueue *Q,DataType *x)
{
   LinkListQ *p;
   if(EmptyQueue(Q))
   {
       printf("�ӿգ������ó�Ԫ��!\n");
       return 0;
   }
   else
   {
       p = Q->front->next;
       *x = p->data;
       Q->front->next = p->next;
       if(p->next==NULL)
           Q->rear = Q->front;
       free(p);
       return 1;
   }
}

int GetFront(LinkQueue *Q,DataType *x)
{
   if(EmptyQueue(Q))
   {
       printf("�ӿգ����ܻ�ö�ͷԪ��!\n");
       return 0;
   }
   else
   {
       *x = Q->front->next->data;
       return 1;
   }
}

int main()
{
   LinkListQ *p;
   LinkQueue *Q;
   DataType x;
   int ch;
   while(1)
   {
       printf("1.��ʼ������\n");
       printf("2.�����\n");
       printf("3.������\n");
       printf("4.��ö�ͷԪ��\n");
       printf("5.�ж϶����Ƿ�Ϊ��\n");
       printf("6.�˳�\n");
       printf("���ݳ� 202220105004\n");
       printf("���������ѡ��\n");
       scanf("%d", &ch);
       switch(ch)
       {
           case 1:
               Q = InitQueue();
               break;
           case 2:
               printf("������һ������\n");
               scanf("%d", &x);
               InQueue(Q, x);
               break;
           case 3:
               if(DeQueue(Q, &x))
                   printf("�����е�Ԫ���ǣ�%d\n\n", x);
               break;
           case 4:
               if(GetFront(Q, &x))
                   printf("��ͷԪ���ǣ�%d\n\n", x);
               break;
           case 5:
               if(EmptyQueue(Q))
                   printf("����Ϊ�գ�\n");
               else
                   printf("���в�Ϊ�գ�\n");
               break;
           case 6:
               exit(0);
           default:
               printf("�������\n");
               break;
       }
   }
   return 0;
}
