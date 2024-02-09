/* ˳��ջ���� */
#include "stdio.h"
#define  MAXLEN  100             /*˳��ջ�洢�ռ���ܷ�����*/
typedef  int  DataType;          /*����DataTypeΪint����*/ 
typedef  struct                  /*˳��ջ�洢����*/
{   DataType   data[MAXLEN];     /*���˳��ջ������*/
    int  top;                    /*��¼ջ��Ԫ��λ�õı���*/
}SeqStack;

void  InitStack( SeqStack  *S )
{   /*��ʼ��ջ����*/
    S->top=-1;               /*��ʼ����˳��ջΪ��*/
}

int EmptyStack(SeqStack *S)
{   /*�ж�ջ�պ���*/
    if(S->top==-1)               /*ջΪ��*/
        return 1;
    else
        return 0;
}

int FullStack(SeqStack *S)
{   /*�ж�ջ������*/
    if(S->top==MAXLEN-1)               /*ջΪ��*/
        return 1;
    else
        return 0;
}

int Push(SeqStack *S,DataType x)
{   /*��ջ��������*/
    if(FullStack(S))      /*������������FullStack(S)���ж�ջ�Ƿ�Ϊ��*/
    {   printf("ջ�������ܽ�ջ!");
        return 0;                /*ջ�����ܽ�ջ*/
    }
    else                          /*ջ��Ϊ��*/
    {   S->top++;
        S->data[S->top]=x;
        return 1;
    }
}

int Pop(SeqStack *S,DataType *x)
{   /*��ջ��������*/
    if(EmptyStack(S))     /*�����пպ���EmptyStack(S)���ж�ջ�Ƿ�Ϊ��*/
    {   printf("ջ�գ����ܳ�ջ!");
        return 0;              /*ջ�ղ��ܳ�ջ*/
    }
    else                        /*ջ��Ϊ��*/
    {   *x=S->data[S->top];
        S->top--;
        return 1;
    }
}

int GetTop(SeqStack *S,DataType *x)
{   /*ȡջ��Ԫ�غ���*/
    if(EmptyStack(S))    /*�����пպ���EmptyStack(S)���ж�ջ�Ƿ�Ϊ��*/
    {   printf("ջ�գ�ȡջ��Ԫ��ʧ��!");
        return 0;
    }
    else                   /*ջ��Ϊ��*/
    {   *x=S->data[S->top];
        return 1;
    }
}

void  Menu()                                    
{   /*��ʾ�˵��Ӻ���*/
	printf("\n                  ˳��ջ�ĸ��ֲ���");
    printf("\n==================================================");  
    printf("\n|               1������ʼ��ջ                    |");
    printf("\n|               2������ջ����                    |");
    printf("\n|               3������ջ����                    |");
    printf("\n|               4������ջ��Ԫ��                  |");
    printf("\n|               5����10������ת��Ϊ2����          |");
    printf("\n|               0��������                        |");
    printf("\n================���ݳ� 202220105004================"); 
    printf("\n������˵��ţ�0-4��:"); 	
}

void decimalToBinary(int num) {
   int temp = num;
   int result[100];
   int i = 0;
   while (temp > 0) {
       result[i++] = temp % 2;
       temp /= 2;
   }
   printf("%d�Ķ����Ʊ�ʾΪ��", num);
   for (int j = i - 1; j >= 0; j--) {
       printf("%d", result[j]);
   }
   printf("\n");
}


int main()
{
   int i,n,flag;
   SeqStack S;
   DataType x;
   int aa;
   char  ch1,ch2,a;
   ch1='y';
   while(ch1=='y'||ch1=='Y') 
   {  Menu();
   	  scanf("%c",&ch2);
   	  getchar();
   	  switch(ch2)
   	  {
   	  	 case  '1':   	  	 
             InitStack(&S);
             printf("ջ�ĳ�ʼ����ɣ�");
             break;
         case  '2':
             printf("������Ҫ��ջ��Ԫ�ظ�����");
             scanf("%d",&n);
             printf("������%d����ջ��������",n); 
             for(i=0;i<n;i++)
             {   
             	 scanf("%d",&x);
             	 flag=Push(&S,x);
             }
             if(flag==1)
                printf("��ջ�ɹ���");
             break;
         case  '3':
             printf("������Ҫ��ջ��Ԫ�ظ�����");
             scanf("%d",&n);
             printf("��ջ��Ԫ��Ϊ��"); 
             for(i=0;i<n;i++)
             {   
             	 flag=Pop(&S,&x);
             	 printf("%5d",x);
             }
             if(flag==1)
                 printf("\n��ջ�ɹ�!");
             else
                 printf("��ջʧ�ܣ�");
             break;
         case  '4':
             if(flag=GetTop(&S,&x))
                 printf("��ǰ��ջ��Ԫ��ֵΪ��%d",x);
             break;
         case  '5':
             
             printf("������10��������");
             scanf("%d",&aa);
             decimalToBinary(aa);
            break;
         case  '0':
             ch1='n';break;
         default:
             printf("��������������0-4����ѡ��");
   	  }
   	  if(ch2!='0')
   	  {   printf("\n���س�����������������������˵���\n");
   	  	  a=getchar();
   	  	  if(a!='\xA')
   	  	  {
   	  	  	 getchar();ch1='n';
   	  	  }
   	  }
   }
}
