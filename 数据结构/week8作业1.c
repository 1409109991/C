/*ջ��ϵͳ*/
#include <stdio.h>
#include <malloc.h>
#define  MAXSIZE  100             /*������󳤶�Ϊ100*/
typedef  int  DataType;           /*����DataTypeΪint����*/
typedef  struct  stacknode        /*��ջ�洢����*/
{
   DataType        data;          /*�������������*/
   struct  stacknode    *next;    /*�������ָ����*/
} LinkStack;

LinkStack  *InitStack()
{  /*��ʼ����ջ����*/

   return S;   /*��ʼ��ջΪ��*/
}

LinkStack *Push(LinkStack *S,DataType x)
{  /*��ջ����*/
   LinkStack *p;
   �ص�
   return S;      /*����ջ��S*/
}

int EmptyStack(LinkStack *S)
{  /*�ж�ջ�պ���*/
   
}

LinkStack *Pop(LinkStack *S,DataType *x)
{  /*��ջ����*/
   LinkStack *p;
   if(EmptyStack(S))    /*�����пպ���EmptyStack(S)���ж�ջ�Ƿ�Ϊ��*/
   {
       printf("\tջ�գ����ܳ�ջ!");
       return NULL;         /*ջ�ղ��ܳ�ջ*/
   }
   else                     /*ջ��Ϊ��*/
   {
      *x=S->data;           /*ջ��Ԫ��ȡ������x*/
      p=S;                  /*p���ָ��ԭջ��S*/
      S=S->next;            /*ԭջ��Sָ������һ�����*/
      free(p);              /*�ͷ�ԭջ���ռ�*/
      return S;             /*����ջ��S*/
   }
}

int GetTop(LinkStack *S,DataType *x)
{  /*��ȡջ��Ԫ�غ���*/
   if(EmptyStack(S))      /*�����пպ���EmptyStack(S)���ж�ջ�Ƿ�Ϊ��*/
   {
       printf("ջ��!");
       return 0;
    }
    else                 /*ջ��Ϊ��*/
    {
       *x=S->data;       /*ջ��Ԫ�ظ�������x*/
       return 1;
    }
}

void ShowStack(LinkStack *S)
{
	LinkStack *p=S;
	if(  )
	  printf("\tջ�գ�");
	else
	{
	  	printf("��ջ��Ԫ����ջ�и�Ԫ��Ϊ��");
        while(p!=NULL) 
        {
           printf("%d ",p->data);
           ��ʽ;
        }
    }
}
              
void  MenuStack()                                    
{   /*��ʾ�˵��Ӻ���*/ 
	printf("\n                     ջ��ϵͳ");
    printf("\n==================================================");  
    printf("\n|               1������ʼ��ջ                    |");
    printf("\n|               2������ջ����                    |");
    printf("\n|               3������ջ����                    |");
    printf("\n|               4������ջ��Ԫ��                  |");
    printf("\n|               0��������                        |");
    printf("\n=================================================="); 
    printf("\n������˵��ţ�0-4��:"); 	
}

main()
{
   int i,n,flag;

   char  ch1,ch2,a;
   char exp[MAXSIZE],postexp[MAXSIZE];  /*����ʽֵ����������*/
   ch1='y';
   while(ch1=='y'||ch1=='Y') 
   {  MenuStack();

   	  getchar();
   	  switch()
   	  {
   	  	 case  '1':   	  	 
             S=InitStack();
             printf("ջ�ĳ�ʼ����ɣ�");
             break;
         case  '2':
             printf("������Ҫ��ջ��Ԫ�ظ�����");
             scanf("%d",&n);
             printf("������%d������������ջ��",n);
             for()
             {   
             
             }
            
             break;
         case  '3':

             for()
             {  
             	 if()
             	    printf("%5d",x);
             }
             break;    
         case  '4':
             if(flag=GetTop(S,&x))
                 printf("��ǰ��ջ��Ԫ��ֵΪ��%d",x);
             break;
        
         case  '0':
             ch1='n';break;
         default:
             printf("��������������0-5����ѡ��");
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

