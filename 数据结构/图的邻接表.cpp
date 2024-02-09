#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct EdgeNode {
    int adjvex;              
    struct EdgeNode *next;   
} EdgeNode;

typedef struct VHeadNode {
    char data;              
    EdgeNode *firstedge;    
} VHeadNode;

typedef struct {
    VHeadNode adjlist[MAX]; 
    int n, e;               
} AdjList;

void CreateAGraph(AdjList *g, int flag) {
    int i, j, k;
    EdgeNode *p;

    if (flag == 0)
        printf("\n������һ������ͼ��\n");
    else
        printf("\n������һ������ͼ��\n");

    printf("������ͼ�Ķ�������");
    scanf("%d", &g->n);

    printf("������ͼ�ı�����");
    scanf("%d", &g->e);

    printf("\n������ͼ�ĸ�������Ϣ��\n");
    for (i = 0; i < g->n; i++) {
        printf("��%d��������Ϣ��", i + 1);
        scanf("\n%c", &(g->adjlist[i].data));
        g->adjlist[i].firstedge = NULL;
    }

    printf("\n������ߵ���Ϣ�������ʽΪ�����1�����2���������Ϊ0��1��2...):\n");
    for (k = 0; k < g->e; k++) {
        printf("�������%d���ߣ�", k);
        scanf("\n%d,%d", &i, &j);

        p = (EdgeNode *)malloc(sizeof(EdgeNode));
        p->adjvex = j;
        p->next = g->adjlist[i].firstedge;
        g->adjlist[i].firstedge = p;

        if (flag == 0) {
            p = (EdgeNode *)malloc(sizeof(EdgeNode));
            p->adjvex = i;
            p->next = g->adjlist[j].firstedge;
            g->adjlist[j].firstedge = p;
        }
    }
}

void PrintGraph(AdjList *g) {
    int i;
    EdgeNode *p;
    printf("\n�ڽӱ��������£�\n");
    for (i = 0; i < g->n; i++) {
        printf("%d(%c):", i, g->adjlist[i].data);

        p = g->adjlist[i].firstedge;
        while (p) {
            printf("->%d", p->adjvex);
            p = p->next;
        }

        printf("->NULL\n");
    }
}

int main() {
    AdjList G;
    int flag;
    printf("���ݳ� 202220105004\n"); 
    printf("������ͼ�����ͣ�����ͼ����0������ͼ����1��");
    scanf("%d", &flag);
    CreateAGraph(&G, flag);
    PrintGraph(&G);
    return 0;
}
