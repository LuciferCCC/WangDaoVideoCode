#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

bool InitList(LinkList &L)
{
    LNode *s=(LNode*)malloc(sizeof(LNode));
    if(s==NULL) return false;
    s->next=NULL;
    s->data=0;
    return true;
}

int GetLenght(LinkList L)
{
    if(L==NULL) return -1;
    LNode *p=L;
    int length=0;
    while(p)
    {
        length++;
        p=p->next;
    }
    return length-1;  // 注意这里要删除头结点
}

// 建立单链表：头插法
bool Building_Head(LinkList &L)
{
    L=(LNode*)malloc(sizeof(LNode));
    LNode *s;
    int x;
    L->next=NULL;
    scanf("%d", &x);
    while(x!=9999)
    {
        s=(LNode*)malloc(sizeof(LNode));
        if(s==NULL) return false;
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d", &x);
    }
    return true;
}

// 建立单链表：尾插法
bool Building_Tail(LinkList &L)
{
    L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;
    int x;
    LNode *s, *r=L;
    scanf("%d", &x);
    while(x!=9999)
    {
        s=(LNode*)malloc(sizeof(LNode));
        if(s==NULL) return false;
        s->next=NULL;
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d", &x);
    }
    return true;
}

// 按位序插入：在第i各节点插入元素e
bool ListInsert(LinkList &L, int i, int e)
{
    if(i<1) return false;
    LNode *p=L;  // 用于扫描结点
    int j=0;  //用于计数扫描到第几个节点
    while(p!=NULL&&j<i-1)
    {
        j++;
        p=p->next;
    }
    if(p==NULL) return false;  // 可以用于检查i值是否超出了链表最大结点的范围，
                               // 换句话说，i值小于1时会不合法，i值大于链表最大节点范围时也会不合法
    // 注意：通过这种方式找到的永远是第i-1个结点，我们要添加的节点是第i个结点
    LNode *s=(LNode*)malloc(sizeof(LNode));
    if(s==NULL) return false;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}

// 按结点插入：后插法
bool InertNextNode(LNode *p, int e)
{
    if(p==NULL) return false;
    LNode *s=(LNode*)malloc(sizeof(LNode));
    if(s==NULL) return false;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}

// 按节点插入：前插法
bool InsertPriorNode(LNode *p, int e)
{
    if(p==NULL) return false;
    LNode *s=(LNode*)malloc(sizeof(LNode));
    if(s==NULL) return false;
    s->data=p->data;
    p->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}

// 按位序查找元素：返回元素
int LocateElem(LinkList L, int i)
{
    if(i<0) return -1;
    LNode *p=L;
    int j=0;  // 注意这里的j值，如果是带头结点的链表，j=0；如果是不带头结点的链表，j=1
    while(j<i&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    return p->data;  // 注意这里的p指向的是哪一个结点
} 

// 按值查找元素：返回结点
LNode* GetElem(LinkList L, int e)
{
    if(L==NULL) return NULL;
    LNode *p=L;
    while(p!=NULL)
    {
        if(p->data==e)
            return p;
        else
            p=p->next;
    }
    return NULL;
}

void PrintList(LinkList L)
{
    LNode *s=L->next;
    while(s!=NULL)
    {
        printf("%d\n", s->data);
        s=s->next;
    }
}

int main()
{
    LinkList L;
    InitList(L);
    Building_Tail(L);
    PrintList(L);
    printf("\n");
    int e=LocateElem(L, 2);
    printf("e=%d\n", e);
    
}
