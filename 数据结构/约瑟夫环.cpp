/* Լɪ������ */
#include"stdio.h"
#include"stdlib.h"
#define MAXPV 20/*ÿ���������ֵΪ20*/
#define MAXNUM 30 /*��Ҫ������������Ϊ30*/
#define MAXFV 10 /*��ʼ���ҵ�����ֵΪ10*/
typedef struct LinkList
{ int data;
int password;
struct LinkList *next;
}LinkList;
/*����������*/
LinkList *CreatList();
void InitList(LinkList *, int );
int GetPassword();
int GetPersonNumber();
int GetFirstCountValue();
void GetOutputOrder(LinkList* , int, int, int* );
void printResult(int * , int );

LinkList *CreatList()
{ /*��ʼ����������*/
LinkList *L;
L = (LinkList *) malloc(sizeof(LinkList));
if (L == NULL)
{ printf("�����ڴ�ʧ��!");
exit(1);
}
return L;
}

void InitList(LinkList *L, int personNumber)
{ /*����ѭ����������*/
LinkList *p, *q;
int i ;
p = L;
p->data =1;
p->password = GetPassword();
for (i = 2; i <= personNumber; i++)
{ q = (LinkList *) malloc(sizeof(LinkList));
if (q == NULL)
{ printf("�����ڴ�ռ�ʧ��!");
exit(1);
}
q->password = GetPassword();
q->data = i;
p->next = q;
p = q;
}
p->next = L;
}

int GetPersonNumber()
{ /*���봦�����������*/
int personNumber;
printf("����������:");
scanf("%d",&personNumber);
while (personNumber > MAXNUM || personNumber < 0)
{ printf("\n�������������Ч,��������0��%d������",MAXNUM);
scanf("%d",&personNumber);
}
printf("������Լɪ�򻷵ĳ���˳������Ϊ%d�ˡ�\n",personNumber);
return personNumber;
}

int GetPassword()
{ /*��ÿ���˸����뺯��*/
int password;
static int count= 1;
printf("�������%d�˵�����:", count);
scanf("%d", &password);
while (password > MAXPV || password < 0)
{ printf("�������������Ч,��������0��%d������:",MAXPV);
scanf("%d", &password);
}
count++;
return password;
}

int GetFirstValue()
{/*ȷ����ʼ������ֵ����*/
int firstValue;
printf("���������������ֵ: ");
scanf("%d",&firstValue);
while (firstValue > MAXFV||firstValue < 0)
{
printf("\n���������������Ч,��������0��%d������: ",MAXFV);
scanf("%d",&firstValue);
}
printf("���յ���������ֵΪ%d��\n",firstValue);
return firstValue;
}

void GetOutputOrder(LinkList *L, int personNumber, int reportValue, int 
array[MAXNUM])
{ /*�õ�����˳����*/
LinkList *p, *q;
int count = 1, i = 0;
p = L;
while (personNumber)
{while (count != reportValue)
{ q = p;
p= p->next;
count++;
}
array[i++] = p ->data;
reportValue = p->password;
q->next = p->next;
free(p);
p = q->next;
count= 1;
personNumber--;
}
}

void printResult(int array[], int personNumer)
{ /*����������*/
int i;
printf("\n��ÿ�˳��еı�����γ��е�˳��Ϊ��");
for(i=0; i<personNumer; i++)
printf("%-3d", array[i]);
printf("\n");
}

int main()
{LinkList *L;
   int personNumber, reportValue;
   int array[MAXNUM];
   printf("Լɪ�����⡣\n");
   personNumber = GetPersonNumber();
   reportValue = GetFirstValue();
   L=CreatList();
   InitList(L, personNumber);
   GetOutputOrder(L, personNumber, reportValue, array);
   printResult(array, personNumber);
   system("pause");
   printf("\n���ݳ� 202220105004");
   return 0;
}
