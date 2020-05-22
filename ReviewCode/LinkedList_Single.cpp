#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
    int data;
    struct LNode *next;
} LNode, *LinkedList;

// 不带头结点的初始化
bool InitList_0(LinkedList &L)
{
    L = NULL;
    return true;
}

// 带头结点的初始化
bool InitList_1(LinkedList &L)
{
    L = (LNode*)malloc(sizeof(LNode));
    if(L==NULL) return false;
    L -> next = NULL;
    return true;
}

// 不带头结点的头插法建立单链表
LinkedList List_HeadInsert_0(LinkedList &L)
{
    LNode *s;
    int x=1;
    L = (LinkedList)malloc(sizeof(LNode));
    // L = NULL;
    // 对第一个结点特殊处理
    L->data = x;
    L->next = NULL;
    // 对第二个及之后的结点进行处理
    x++;
    while(x!=7)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        x++;
    }
    return L;
}

// 带头结点的头插法建立单链表
LinkedList List_HeadInsert_1(LinkedList &L)
{
    LNode *s;
    int x;
    L = (LinkedList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while(x!=9999)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->next = L->next;
        s->data = x;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

// 不带头结点的尾插法建立单链表
LinkedList List_TailInsert_0(LinkedList &L)
{
    int x;
    L = (LinkedList)malloc(sizeof(LNode));
    LNode *s, *r=L;
    // 对第一个结点特殊处理
    scanf("%d", &x);
    L->data = x;
    L->next = NULL;
    // 对第二个及之后结点的处理
    scanf("%d", &x);
    while(x!=9999)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

// 带头结点的尾插法建立单链表
LinkedList List_TailInsert_1(LinkedList &L)
{
    int x;
    L = (LinkedList)malloc(sizeof(LNode));
    LNode *s, *r=L;
    scanf("%d", &x);
    while(x!=9999)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

// 不带头结点的按位序插入：在第i个结点插入元素e
bool ListInsert_0(LinkedList &L, int i, int e)
{
    if(i<1) return false;
    if(i == 1)
    {
        LNode* s = (LNode*)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;  // 头指针指向新节点
        return true;
    }
    int j=1;
    LNode* p = L;
    while (p!=NULL&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(p==NULL) return false;
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 带头结点的按位序插入：在第i个结点插入元素e
bool ListInsert_1(LinkedList &L, int i, int e)
{
    if(i<1) return false;
    LNode *p;  // 当前扫描到的结点
    int j = 0;  // 当前扫描到的第j个结点
    p = L;
    while(p!=NULL&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(p==NULL) return false;  // 可以检查i值不合法
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 在指定结点之后插入操作
bool InsertNextNode(LNode*p, int e)
{
    if(p==NULL) return false;
    LNode* s = (LNode*)malloc(sizeof(LNode));
    if(s==NULL) return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 在指定结点前插操作
bool InsertPriorNode(LNode*p, int e)
{
    if(p==NULL) return false;
    LNode* s = (LNode*)malloc(sizeof(LNode));
    if(s==NULL) return false;
    s->data = p->data;
    p->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 不带头结点按位序查找元素
LNode* GetElem_0(LinkedList &L, int i)
{
    if(i<1) return NULL;
    if(i==1) return L;
    int j=1;
    LNode* p=L;
    while(j<i-1 && p!=NULL)
    {
        p=p->next;
        j++;
    }
    return p->next;
}

// 带头结点按位序查找元素
LNode * GetElem_1(LinkedList &L, int i)
{
    if(i<0) return NULL;
    LNode *p = L;
    int j = 0;
    while(j<i-1 && p!=NULL)
    {
        p=p->next;
        j++;
    }
    return p;
}

// 不带头结点的按值查找元素
int LocateElem_0(LinkedList L, int e)
{
    LNode* p = L;
    while(p!=NULL)
    {
        if(e == p->data)
            return 1;
        p=p->next;
    }
    return 0;
}

// 带头结点的按值查找元素
int LocateElem_1(LinkedList L, int e)
{
    LNode* p = L->next;
    while(p!=NULL) 
    {
        if(e == p->data)
            return 1;
        p=p->next;
    }
    return 0;
}

// 不带头结点的按位序删除结点，并将值返回给e
bool DeleteLNode_0(LinkedList &L, int i, int &e)
{
    if(i<1) return false;
    LNode* p=L;
    if(i == 1)
    {
        L = L->next;
        free(p);
        return true;
    }
    int j=1;
    while(p!=NULL&&j<i-1)
    {
        p = p->next;
        j++;
    }
    if(p==NULL) return false;
    e = p->next->data;
    p->next = p->next->next;
    free(p->next);
    return true;
}

// 带头结点的按位序删除结点
bool DeleteLNode_1(LinkedList &L, int i, int &e)
{
    if(i<1) return false;
    LNode* p = L;
    int j=0;
    while(p!=NULL&&j<i-1)
    {
        p = p->next;
        j++;
    }
    if(p==NULL) return false;
    e = p->next->data;
    p->next = p->next->next;
    free(p->next);
    return true;
}

// 删除指定节点
bool DeleteLNode(LNode *p)
{
    if(p==NULL) return false;
    // LNode* q = p->next;
    p->data = p->next->data;
    p->next = p->next->next;
    // free(q);
    return true;
}

void PrintList(LinkedList L)
{
    LNode* p = L;
    int j=1;
    while(p!=NULL)
    {
        printf("第%d个结点，data=%d\n", j, p->data);
        p=p->next;
        j++;
    }
    printf("\n");
}

int main()
{
    // 不带头链表_头插法建立
    LinkedList L0;
    InitList_0(L0);
    printf("不带头的链表\n");
    List_HeadInsert_0(L0);  // 数据 1 2 3 4 5 6
    printf("使用头插法建立链表\n");
    PrintList(L0);

    ListInsert_0(L0, 3, 30);  // 按位序在第三个结点插入元素30
    printf("按位序插入元素：在第三个结点上插入元素30\n");
    PrintList(L0);

    InsertNextNode(L0, 10);
    printf("后插法：在第一个结点之后插入元素10\n");
    PrintList(L0);

    InsertPriorNode(L0, 20);
    printf("前插法：在第一个结点之前插入元素20\n");
    PrintList(L0);

    printf("按位查找链表中第4个位置上的元素的值为%d\n", GetElem_0(L0, 4)->data);

    printf("按值查找链表中元素值为2的结点是否存在%d\n", LocateElem_0(L0, 2));
    
    int e;
    DeleteLNode_0(L0,3,e);
    printf("不带头结点按位序删除元素：删除第三个节点上的元素，其值为%d\n",e);
    PrintList(L0);

    DeleteLNode(L0);
    printf("删除链表中的第一个结点\n");
    PrintList(L0);
}