#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define InitSize 10  // 顺序表的初始长度

typedef struct{
    int * data;  // 指向动态分配数组的指针
    int MaxSize;
    int length;
}SqList;

// 初始化一个顺序表
void InitList(SqList &L)
{
    L.data = (int*)malloc(sizeof(int)*InitSize);
    L.length = 0;
    L.MaxSize = InitSize;
}

// 动态增加顺序表的最大容量，增加len个容量
bool IncreaseSize(SqList &L, int len)
{
    int * p = L.data;
    L.data = (int*)malloc(sizeof(int)*(len+L.MaxSize));
    if(L.data == NULL) return false;
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];
    }
    L.MaxSize += len;
    free(p);
    return true;
}

// 动态从后往前减少顺序表的长度
bool ReduceSize(SqList &L, int len)
{
    if(len > L.MaxSize) return false;
    int* p = L.data;
    L.data = (int*)malloc(sizeof(int)*(L.MaxSize-len));
    if(L.data == NULL) return false;
    for (int i = 0; i < (L.MaxSize-len); i++)
    {
        L.data[i] = p[i];
    }
    L.MaxSize -= len;
    free(p);
    return true;
}

int main()
{
    SqList L;
    InitList(L);
    printf("L.length = %d, L.MaxSize = %d\n", L.length, L.MaxSize);
    bool y = IncreaseSize(L, 10);
    int s = 0;
    if(y==true)
        s = 1;
    printf("isIncrease = %d, L.length = %d, L.MaxSize = %d\n", s, L.length, L.MaxSize);

    y = ReduceSize(L, 25);
    s = 0;
    if(y==true)
        s = 1;
    printf("isDelete = %d, L.length = %d, L.MaxSize = %d\n", s, L.length, L.MaxSize);
}