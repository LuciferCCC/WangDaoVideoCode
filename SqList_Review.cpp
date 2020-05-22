#include<stdio.h>
#include<stdlib.h>

#define Maxsize 10

typedef struct{
    int data[Maxsize];
    int length;
}SqList;

// 初始化一个空的顺序表
void InitList(SqList &L)
{
    L.length=0;
    for(int i=0;i<Maxsize;i++)
        L.data[i]=0;
}

// 创建一个顺序表
bool CreatList(SqList &L, int n)
{
    if(n<0||n>Maxsize) return false;
    int x=1, i=1;
    while(i<=n)
    {
        L.data[i-1]=x;
        x++;
        i++;
        L.length++;
    }
    return true;
}

// 插入函数：在第i个位置上插入元素e
bool InsertList(SqList &L, int i, int e)
{
    if(i<1||i>Maxsize) return false;
    if(L.length>=Maxsize) return false;
    for(int j=L.length;j>=i;j--)
        L.data[j]=L.data[j-1];  // 往后移动元素和往前移动元素，不要弄反了！！！
    L.data[i-1]=e;
    L.length++;
    return true;
}

// 删除函数：删除第i个位置上的元素，并将元素返回给变量e
bool DeleteList(SqList &L, int i)
{
    if(i<1||i>L.length) return false;
    for(int j=i;j<L.length;j++)  // 要注意这里的 length !!!
        L.data[j-1]=L.data[j];
    L.length--;
    return true;
}

// 按位序查找元素
int LocateList(SqList L, int e)
{
    for(int i=0;i<L.length;i++)
    {
        if(L.data[i]==e) return i+1;
    }
    return 0;
}

// 输出功能函数
void PrintList(SqList L)
{
    for(int i=0;i<L.length;i++)
        printf("%d = %d\n", i, L.data[i]);
}

// 顺序表的倒置
void ReverseList(SqList &L)
{
    if(L.length)
    {
        for(int i=0;i<L.length-1-i;i++)
        {
            int temp=0;
            temp=L.data[i];
            L.data[i]=L.data[L.length-1-i];
            L.data[L.length-1-i]=temp;
        }
    }
}

int main()
{
    SqList L;
    InitList(L);
    CreatList(L,5);
    printf("创建顺序表：\n");
    PrintList(L);
    printf("\n");
    printf("在第4个位置上插入元素400\n");
    InsertList(L, 4, 400);
    PrintList(L);
    printf("\n");    
    printf("删除元素：第4个位置上的400\n");
    DeleteList(L, 4);
    PrintList(L);
    printf("\n");
    printf("按位查找第4个位置上的元素为：");
    int e=5;
    LocateList(L, e);
    printf("%d\n",e);
    printf("\n");
    printf("顺序表元素完整输出：");
    PrintList(L);
    getchar();
}