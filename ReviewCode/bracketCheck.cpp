#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10

typedef struct{
    char data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack &S)
{
    S.top=-1;
}

bool IsEmpty(SqStack S)
{
    if(S.top==-1) return true;
    else return false;
}

bool Push(SqStack &S, char x)
{
    if(S.top==MaxSize-1) return false;
    S.data[++S.top]=x;
    return true;
}

bool Pop(SqStack &S, char &x)
{
    if(S.top==-1) return false;
    x=S.data[S.top--];
    return true;
}

bool bracketCheck(char str[], int length)
{
    SqStack S;
    InitStack(S);
    for(int i=0;i<length;i++)
    {
        if(str[i]=='('||str[i]=='{'||str[i]=='[')
            Push(S, str[i]);
        else{
            if(IsEmpty(S)) return false;
            char topElem;
            Pop(S, topElem);
            if(str[i]==')'&&topElem!='(') return false;
            if(str[i]==']'&&topElem!='[') return false;
            if(str[i]=='}'&&topElem!='{') return false;
        }
    }
    return IsEmpty(S);
}

