/*����ϵͳ*/
#include <stdio.h>
#include <malloc.h>
#define  MAX  100
int  count=0;                   /*�������������ı���*/
typedef  struct  tnode
{ 
   char  data;
   struct  tnode  *lchild,*rchild;
}BT;

BT  *CreateBTree()
{
   BT  *t;
   char  ch;
   scanf("%c",&ch);
   getchar();
   if(ch=='0')
      t=NULL;
   else
   {
   	  t=(BT *)malloc(sizeof(BT));
   	  t->data=ch;
   	  printf("������%c�������ӽ�㣺",t->data);
   	  t->lchild=CreateBTree();
   	  printf("������%c�����Һ��ӽ�㣺",t->data);
   	  t->rchild=CreateBTree();
   }
   return  t;
}

void ShowBTree(BT *T)                     /*�ù�����ʾ����ʾ������*/
{   if (T!=NULL)                          /*���������ǿ�ʱ*/
    {   printf("%c",T->data);             /*����ý��������*/
        if(T->lchild!=NULL)               /*�����������ǿ�*/
        {   printf("(");                  /*����������*/
            ShowBTree(T->lchild);         /*�ݹ���øú�������������������*/
            if(T->rchild!=NULL)           /*�����������ǿ�*/
            {    printf(",");             /*�������*/
                 ShowBTree(T->rchild);    /*�ݹ���øú�������������������*/
            }
             printf(")");
        }
        else
          if(T->rchild!=NULL)              /*������������Ϊ�գ���������Ϊ��ʱ*/
          {
        	 printf("(");                  /*����������*/
        	 ShowBTree(T->lchild);         /*�ݹ���øú�������������������*/
             if(T->rchild!=NULL)           /*�����������ǿ�*/
             {   printf(",");              /*�������*/
                 ShowBTree(T->rchild);     /*�ݹ���øú�������������������*/
             }
             printf(")");
          }
    }
}


void  MenuTree()                                     /*��ʾ�˵��Ӻ���*/
{
	printf("\n                  ��������ϵͳ");
    printf("\n =================================================");  
    printf("\n|               1��������һ���¶�����            |");
    printf("\n|               2����������ʾ����ʾ            |");
    printf("\n|               3�����������                    |");
    printf("\n|               4�����������                    |");
    printf("\n|               5�����������                    |");
   
    printf("\n������˵��ţ�0-9��:"); 	
}

main()
{
   
   	  scanf("%c",&ch2);
   	  getchar();
   	  switch(ch2)
   	  {
   	  	 
         case  '4':
             printf("�������������������Ϊ��");
             InOrder(T);break;
         case  '5':
             printf("�������ĺ����������Ϊ��");
             PostOrder(T);break;
         case  '6':    
             printf("�������Ĳ�α�������Ϊ��");
             LevelOrder(T);break;
         case  '7':
             count=0;Leafnum(T);
             printf("�ö�������%d��Ҷ�ӡ�",count);break;
         case  '8':
             count=0;Nodenum(T);
             printf("�ö���������%d����㡣",count);break; 
         case  '9':
             printf("�ö������������%d��",TreeDepth(T));break; 
         case  '0':
             ch1='n';break;
         default:
             printf("��������������0-9����ѡ��");
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
