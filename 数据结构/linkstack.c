/*ջ��ϵͳ*/
#include <stdio.h>
#include <malloc.h>
#define  MAXSIZE  100             /*������󳤶�Ϊ100*/
typedef  int  DataType;           /*����DataTypeΪint����*/
typedef  struct  qnode        /*��ջ�洢����*/
{
   DataType data;          /*�������������*/
   struct  qnode    *next;    /*�������ָ����*/
} LinkListQ;

typedef struct linkstack
{
    /* data */
};


LinkStack  *InitStack()
{  /*��ʼ����ջ����*/
   LinkStack *S;
   S=NULL;
   return S;   /*��ʼ��ջΪ��*/
}

int EmptyStack(LinkStack *S)
{  /*�ж�ջ�պ���*/
   if(S==NULL)           /*ջΪ��*/
      return 1;
   else
      return 0;
}

LinkStack *Push(LinkStack *S,DataType x)
{  /*��ջ����*/
   LinkStack *p;
   p=(LinkStack *)malloc(sizeof(LinkStack));/*�����½��*/
   p->data=x;     /*��x�����½���������*/
   p->next=S;     /*���½����������ͷ֮ǰ*/
   S=p;           /*�½����Ϊջ��*/
   return S;      /*����ջ��S*/
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
	if(p==NULL)
	  printf("\tջ�գ�");
	else
	{
	  	printf("��ջ��Ԫ����ջ�и�Ԫ��Ϊ��");
        while(p!=NULL) 
        {
           printf("%d ",p->data);
           p=p->next;
        }
    }
}

void D_B(LinkStack *S,DataType x)
{
  while(x)
  {
    S=Push(S,x%2);      /*������ջ*/
    x/=2;             /*������data������2���õ��µı�����*/
  }
  printf("ת����Ķ�����Ϊ��");
  while (!EmptyStack(S))
  {                     
        S=Pop(S,&x);      /*���δ�ջ�е���ÿһ�����������*/
        printf("%d",x);
  }
}

void trans(char *exp,char *postexp)
{   /*����׺���ʽת���ɺ�׺���ʽ����*/
    struct
    {
        char data[MAXSIZE];
        int top;
    } op;    /*�����ջ*/
    int i=0;
    op.top=-1;
    while(*exp!='#')   /*�����ʽû����ʱ*/
    {
        switch(*exp)    /*�жϱ��ʽ��ÿ���ַ�*/
        {
            case '(':   /*���ַ�Ϊ'('ʱ*/
                op.top++;op.data[op.top]=*exp;   /*ջ��ָ����1���������ջ*/
                exp++;   /*��׺���ʽָ����1*/
                break;
            case ')':   /*���ַ�Ϊ')'ʱ*/
                while(op.data[op.top]!='(')   /*ֻҪ�����ջ��Ԫ�ز���'('ʱ*/
                {
                    postexp[i++]=op.data[op.top];  /*��ջ�������д���׺���ʽ������*/
                    op.top--;   /*ջ��ָ���1*/
                }            
                op.top--;exp++; /*ջ��ָ���1�����ʽָ���1*/
                break;    
            case '+':
            case '-':
                while(op.top!=-1&&op.data[op.top]!='(')  /*�����ջ��Ϊ����ջ��Ԫ�ز�Ϊ'('ʱ*/
                {
                    postexp[i++]=op.data[op.top];  /*��ջ�������д���׺���ʽ������*/
                    op.top--;   /*�����ջ��ָ���1*/
                }        
                op.top++;  /*�����ջ��ָ���1*/
                op.data[op.top]=*exp;  /*����׺���ʽԪ�������ջ*/
                exp++; /*��׺���ʽָ���1*/
                break;
            case '*':
            case '/':
                while(op.data[op.top]=='*'||op.data[op.top]=='/') /*��ջ��Ԫ�ز���'*'��'/'ʱ*/
                {
                    postexp[i++]=op.data[op.top];  /*ջ�������д����׺���ʽ������*/
                    op.top--;   /*ջ��ָ���1*/
                } 
                op.top++;/*ջ��ָ���1*/
                op.data[op.top]=*exp; /*��׺���ʽ��Ԫ����ջ*/
                exp++; /*���ʽָ���1*/
                break;
            case ' ':break;
            default:
                while(*exp>='0'&&*exp<='9') /*�����ʽ����������ʱ*/
                {
                    postexp[i++]=*exp;   /*������д����׺���ʽ������*/
                    exp++;  /*��׺ָ���1*/
                }     
                postexp[i++]='#';  /*��ÿ��������֮�����ӷָ���'#'*/
        }    
    }   
    while(op.top!=-1)  /*�������ջ��Ϊ��ʱ*/
    {
        postexp[i++]=op.data[op.top];  /*��ջ�������д���׺���ʽ������*/
        op.top--;    /*ջ��ָ���1*/
    }   
    postexp[i]='\0';  /*Ϊ��׺���ʽ��һ��������־*/
}   

float compvalue(char *postexp)
{   /*���ݺ�׺���ʽ��ֵ����*/
    struct
    {
        float data[MAXSIZE];
        int top;
    } st; /*��ջ�������*/
    float a,b,c,d;
    st.top=-1;   /*ջ��ָ�븳��ֵ-1*/
    while(*postexp!='\0')  /*����׺���ʽû����ʱ*/
    {
        switch(*postexp) 
        {
            case '+':
                a=st.data[st.top]; /*��ջ��Ԫ�ظ�������a*/
                st.top--;          /*ջ��ָ���1*/
                b=st.data[st.top]; /*��ջ��Ԫ�ظ�������b*/
                st.top--;          /*ջ��ָ���1*/
                c=b+a;             /*��a��b�Ľ���������c*/
                st.top++;          /*ջ��ָ���1*/
                st.data[st.top]=c; /*������c��ջ*/
                break;
            case '-':
                a=st.data[st.top]; 
                st.top--;
                b=st.data[st.top];
                st.top--;
                c=b-a;
                st.top++;
                st.data[st.top]=c;
                break;
            case '*':
                a=st.data[st.top];
                st.top--;
                b=st.data[st.top];
                st.top--;
                c=b*a;
                st.top++;
                st.data[st.top]=c;
                break;
            case '/':
                a=st.data[st.top];
                st.top--;
                b=st.data[st.top];
                st.top--;
                if(a!=0)
                {
                    c=b/a;
                    st.top++;
                    st.data[st.top]=c;
                }    
                else
                    printf("\n\t�������!\n");

                break;
            default: /*��׺���ʽ���ַ��������ַ�ʱ������ת��Ϊ����*/
                d=0;
                while(*postexp>='0'&&*postexp<='9')
                {
                    d=10*d+*postexp-'0';
                    postexp++;
                }    
                st.top++;
                st.data[st.top]=d;  /*��ת��֮���������ջ*/
                break;
        }    
        postexp++;
    }    
    return st.data[st.top];   /*������ջ��ջ��Ԫ�ؼ�Ϊ����Ľ��*/
}   
              
void  MenuStack()                                    
{   /*��ʾ�˵��Ӻ���*/ 
	printf("\n                     ջ��ϵͳ");
    printf("\n==================================================");  
    printf("\n|               1������ʼ��ջ                    |");
    printf("\n|               2������ջ����                    |");
    printf("\n|               3������ջ����                    |");
    printf("\n|               4������ջ��Ԫ��                  |");
    printf("\n|               5������ʾջ��Ԫ��                |");
    printf("\n|               6����ʮ����������ת��            |");
    printf("\n|               7�������ʽת������ֵ            |");
    printf("\n|               0��������                        |");
    printf("\n=================================================="); 
    printf("\n������˵��ţ�0-7��:"); 	
}

main()
{
   int i,n,flag;
   LinkStack *S;
   DataType x;
   char  ch1,ch2,a;
   char exp[MAXSIZE],postexp[MAXSIZE];  /*����ʽֵ����������*/
   ch1='y';
   while(ch1=='y'||ch1=='Y') 
   {  MenuStack();
   	  scanf("%c",&ch2);
   	  getchar();
   	  switch(ch2)
   	  {
   	  	 case  '1':   	  	 
             S=InitStack();
             printf("ջ�ĳ�ʼ����ɣ�");
             break;
         case  '2':
             printf("������Ҫ��ջ��Ԫ�ظ�����");
             scanf("%d",&n);
             printf("������%d������������ջ��",n);
             for(i=0;i<n;i++)
             {   
             	 scanf("%d",&x);
             	 S=Push(S,x);
             }
             printf("��ջ�ɹ���");
             break;
         case  '3':
             printf("������Ҫ��ջ��Ԫ�ظ�����");
             scanf("%d",&n);
             printf("��ջ��Ԫ��Ϊ��"); 
             for(i=0;i<n;i++)
             {   
             	 S=Pop(S,&x);
             	 if(S!=NULL)
             	    printf("%5d",x);
             }
             break;    
         case  '4':
             if(flag=GetTop(S,&x))
                 printf("��ǰ��ջ��Ԫ��ֵΪ��%d",x);
             break;
         case  '5':
             ShowStack(S);
             break;    
         case  '6':
             S=InitStack();
             printf("������ʮ����������Ϊ:");
             scanf("%d",&x);     /*����ʮ����������*/ 
             D_B(S,x);          /*���ý���ת������*/
             break;
         case  '7':
             printf("�������������ʽ��ֻ��+��-��*��/���������������'#'������");
             scanf("%s",&exp);
             trans(exp,postexp);
             printf("��ñ��ʽ����׺���ʽΪ��%s\n",exp);
             printf("ת��֮��ĺ�׺���ʽΪ��ÿ���������á�#���ָ�����%s\n",postexp);
             printf("���ʽ��ֵΪ:%.2f\n",compvalue(postexp));
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


