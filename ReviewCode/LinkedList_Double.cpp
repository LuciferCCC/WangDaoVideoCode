#include <stdio.h>
#include <stdlib.h>

typedef struct DNode{
    int data;
    struct DNode *prior, *next;
}DNode, *DLinkList;

// 初始化双链表
bool InitDLinkList(DLinkList &L)
{
    L = (DNode*)malloc(sizeof(DNode));
    if(L==NULL) return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}

// 向双链表中p节点后插入s结点
bool InsertNextDNode(DNode *p, DNode *s)
{
    if(p==NULL||s==NULL) return false;
    s->next = p->next;
    if(p->next!=NULL) p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

// 向双链表中p结点之前插入s结点
bool InsertPriorDNode(DNode *p, DNode *s)
{
    if(p==NULL||s==NULL) return false;
    if(p->prior!=NULL) p->prior->next = s;
    s->prior = p->prior;
    s->next = p;
    p->prior = s;
    return true;
}

// 删除p结点之后的结点  不能删除头结点
bool DeleteNextDNode(DNode *p)
{
    if(p==NULL) return false;
    DNode *q = p->next;
    if(q==NULL) return false;
    p->next = q->next;
    if(q->next!=NULL) q->next->prior = p;
    free(q);
    return true;
}

// 删除整个链表
void DestoryList(DLinkList &L)
{
    while (L->next != NULL) DeleteNextDNode(L);
    free(L);  // 释放头结点  只有在这个时候才能完全删除链表，删除头结点
    L=NULL;  // 将头结点指针指向NULL
}

void PrintDLinkList(DLinkList L)
{
    int j = 1;
    DNode *p=L;
    while(p!=NULL)
    {
        printf("第%d个结点的数据域的值为%d\n", j, p->data);
        p=p->next;
        j++;
    }
}

int main()
{
    DLinkList L;
    InitDLinkList(L);
    DNode* d;
    d->data = 12;
    d->next = NULL;
    d->prior = NULL;
    InsertPriorDNode(L, d);
    PrintDLinkList(L);
    printf("\n");
    DNode* a;
    d->data = 10;
    d->next = NULL;
    d->prior = NULL;
    InsertNextDNode(L, a);
    PrintDLinkList(L);

    printf("\n");
}