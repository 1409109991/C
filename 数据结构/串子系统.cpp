#include <stdio.h>
#define MAXSIZE 100  // ˳�򴮴洢�ռ���ܷ�����

typedef struct {  // ���ṹ����
   char ch[MAXSIZE];
   int Len;
} String;

int StrLength(String *S) {  // �󴮳��Ⱥ���
   int i;
   for (i = 0; S->ch[i] != '\0'; i++) {
   }
   return i;
}

void CreatStr(String *S) {  // ����һ���´�
   printf("������һ���ַ�����");
   scanf("%s", S->ch);
   S->Len = StrLength(S);
}

int SubString(String *S, String *Sub, int pos, int len) {  // ���Ӵ�����
   if (pos < 1 || pos > S->Len || len < 1 || len > S->Len - pos + 1) {
       return 0;
   }
   for (int i = 0; i < len; i++) {
       Sub->ch[i] = S->ch[pos + i - 1];
   }
   Sub->ch[len] = '\0';
   return 1;
}

int StrDelete(String *S, int i, int l) {  // �ڴ�s��ɾ����ָ��λ��i��ʼ������j���ַ�
   if (i + l - 1 > S->Len) {
       return 0;
   } else {
       for (int j = i; j < i + l; j++) {
           S->ch[j] = S->ch[j + l];
       }
       S->ch[i + l - 1] = '\0';
       S->Len -= l;
       return 1;
   }
}

int StrInsert(String *S, String *S1, int i) {  // �ڴ�s�в����Ӵ�s1����
   int j;
   if (i > S->Len + 1) {
       printf("����λ�ô���\n");
       return 0;
   } else if (S->Len + S1->Len > MAXSIZE) {
       printf("�������ȳ����洢�ռ䳤�ȣ�\n");
       return 0;
   } else {
       S->Len += S1->Len;
       for (j = S1->Len - 1; j >= 0; j--) {
           S->ch[i + j] = S1->ch[j];
       }
       S->ch[i + S1->Len] = '\0';
       return 1;
   }
}

int StrIndex(String *S, String *T) {  // ���Ķ�λ����
   int i, j;
   for (i = 0; i <= S->Len - T->Len; i++) {
       for (j = 0; j < T->Len; j++) {
           if (S->ch[i + j] != T->ch[j]) {
               break;
           }
       }
       if (j == T->Len) {
           return i;
       }
   }
   return -1;
}

int StrCompare(String *S1, String *S2) {  // �������ж��Ƿ����
   if (S1->Len != S2->Len) {
       return 0;
   }
   for (int i = 0; i < S1->Len; i++) {
       if (S1->ch[i] != S2->ch[i]) {
           return S1->ch[i] - S2->ch[i];
       }
   }
   return 0;
}

int StrCat(String *S, String *T) {  // �������Ӻ���
   int i, flag;  // ����T�����ڴ�S�ĺ���
   if (S->Len + T->Len <= MAXSIZE) {
             for (i = 0; i < T->Len; i++) {
          S->ch[i + S->Len] = T->ch[i];
      }
      S->ch[S->Len + T->Len] = '\0';
      S->Len += T->Len;
      flag = 1;
  } else if (S->Len < MAXSIZE) {
      S->Len += T->Len;
      for (i = S->Len - 1; i > 0; i--) {
          S->ch[i] = S->ch[i - 1];
      }
      S->ch[0] = '\0';
      flag = 1;
  } else {
      flag = 0;
  }
  return flag;
}

void StrReplace(String *S, String *T, String *V) {  // �Ӵ��滻����
  int i, m, n, p, q;
  n = S->Len;
  m = T->Len;
  q = V->Len;
  p = 1;
  do {
      i = StrIndex(S, T);   // ���ö�λ�����õ��Ӵ�T������S��λ��
      if (i != -1) {  // ������S���и��Ӵ�Tʱ
          StrDelete(S, i, m);  // ����ɾ���Ӵ�����ɾ�����Ӵ�T
          StrInsert(S, V, i);  // ���ò����Ӵ����������Ӵ�V
          p = i + q;
          S->Len = S->Len + q - m;  // �޸�����S�ĳ���
          n = S->Len;
      }
  } while ((p <= n - m + 1) && (i != -1));
}

void  MenuString()                                    
{   // ��ʾ�˵��Ӻ���
  printf("\n                     ����ϵͳ");
  printf("\n==================================================");  
  printf("\n|               1���������´�����ʾ�ô�������    |");
  printf("\n|               2�������Ӵ�                      |");
  printf("\n|               3����ɾ���Ӵ�                    |");
  printf("\n|               4���������Ӵ�                    |");
  printf("\n|               5���������Ӵ�                    |");
  printf("\n|               6�����Ƚ���������С              |");   
  printf("\n|               7��������������                  |"); 
  printf("\n|               8�����Ӵ��滻                    |");  
  printf("\n|               0��������                        |");
  printf("\n===============���ݳ� 202220105004=================="); 
  printf("\n������˵��ţ�0-8��:"); 	
}

int main()
{
  int i, len, flag;
  String  x, y, z;
  String *S=&x,*S1=&y,*S2=&z; 
  char  ch1,ch2,a;
  ch1='y';
  while(ch1=='y'||ch1=='Y') 
    {  
    MenuString();
    scanf("%c",&ch2);
    getchar();
        switch(ch2)
       {
           case '1':
               CreatStr(S);
               printf("�´�Ϊ��%s������Ϊ��%d\n", S->ch, S->Len);
               break;
           case '2':
               printf("�������Ӵ�����ʼλ�úͳ��ȣ�");
               scanf("%d%d", &i, &len);
               if (SubString(S, S1, i, len)) {
                   printf("�Ӵ�Ϊ��%s\n", S1->ch);
               } else {
                   printf("����λ�û򳤶ȴ���\n");
               }
               break;
           case '3':
               printf("������Ҫɾ�����Ӵ�����ʼλ�úͳ��ȣ�");
               scanf("%d%d", &i, &len);
               if (StrDelete(S, i, len)) {
                   printf("ɾ����Ĵ�Ϊ��%s\n", S->ch);
               } else {
                   printf("����λ�û򳤶ȴ���\n");
               }
               break;
           case '4':
               printf("������Ҫ������Ӵ���");
               CreatStr(S1);
               printf("����������λ�ã�");
               scanf("%d", &i);
               if (StrInsert(S, S1, i)) {
                   printf("�����Ĵ�Ϊ��%s\n", S->ch);
               } else {
                   printf("����ʧ�ܣ�\n");
               }
               break;
           case '5':
               printf("������Ҫ���ҵ��Ӵ���");
               CreatStr(S1);
               i = StrIndex(S, S1);
               if (i != -1) {
                   printf("�Ӵ��������е�λ��Ϊ��%d\n", i + 1);
               } else {
                   printf("������û�и��Ӵ���\n");
               }
               break;
           case '6':
               printf("������Ҫ�Ƚϵ���һ������");
               CreatStr(S1);
               int result;
			   result = StrCompare(S, S1);
               if (result == 0) {
                   printf("���������\n");
               } else if (result > 0) {
                   printf("��һ�������ڵڶ�����\n");
               } else {
                   printf("��һ����С�ڵڶ�����\n");
               }
               break;
           case '7':
               printf("������Ҫ���ӵ���һ������");
               CreatStr(S1);
               if (StrCat(S, S1)) {
                   printf("���Ӻ�Ĵ�Ϊ��%s\n", S->ch);
               } else {
                   printf("����ʧ�ܣ�\n");
               }
               break;
           case '8':
               printf("������Ҫ�滻���Ӵ���");
               CreatStr(S1);
               printf("�������滻����Ӵ���");
               CreatStr(S2);
               StrReplace(S, S1, S2);
               printf("�滻��Ĵ�Ϊ��%s\n", S->ch);
               break;
           case '0':
               return 0;
       }
        getchar();
        printf("\n�Ƿ������Y/N��?");
        scanf("%c",&ch1); 
        getchar();
    }
}
