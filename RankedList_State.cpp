#include <stdio.h>

#define MaxSize 10

typedef struct 
{
    int data[MaxSize];  
    int length;  // 当前顺序表长度
}SqList;

// 初始化顺序表
void InitList(SqList &L)
{
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] =  0;
    }
    L.length = 0;
}

// 向顺序表中指定位置上添加元素
bool ListIncrease(SqList &L, int i, int e)
{
    if(i<1||i>L.length+1)
        return false;
    if(L.length >= MaxSize)
        return false;
    for (int j = L.length; j >= i - 1; j--)
    {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

// 删除顺序表中第i个位置上的元素并返回给e
bool ListDelete(SqList &L, int i, int &e)
{
    if(i<1||i>L.length) return false;
    e = L.data[i-1];
    for(int j = i; j < L.length; j++)
    {
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}

// 按位序查找顺序表中的元素，返回元素值
int GetElem(SqList L, int i)
{
    return L.data[i-1];
}

// 按值查找元素，返回顺序表中第一个值为e的元素，并返回其位序
int LocateElem(SqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if(L.data[i] == e)
            return i+1;
    }
    return 0;
    
}

void ListPrint(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("第 %d 个元素= %d \n", i, L.data[i]);
    }
}

int main()
{
    SqList L;
    // 初始化顺序表
    InitList(L);
    // 向顺序表中增加元素
    for (int i = 0; i < 6; i++)
    {
        ListIncrease(L, i, i);
    }

    ListPrint(L);

    printf("\n");

    // 删除线性表中的第三个元素并返回给e
    int e;
    ListDelete(L, 3, e);
    printf("删除的元素的值 = %d", e);
    printf("\n");
    ListPrint(L);

    // 按位查找顺序表中第4个元素的值
    e = GetElem(L, 6);
    printf("第四个元素的值 = %d", e);
    printf("\n");
    
    // 按值查找顺序表中第一个值为5的元素的位序
    e = LocateElem(L, 7);
    printf("顺序表中第一个值为5的元素额位序 = %d", e);
    printf("\n");
}