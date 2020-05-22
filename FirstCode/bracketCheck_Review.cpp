#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10

typedef struct{
    char bracket[MaxSize];
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

bool PushStack(SqStack &S, char x)
{
    if(S.top==MaxSize-1) return false;
    S.bracket[++S.top]=x;
    return true;
}

bool DeStack(SqStack &S, char &x)
{
    if(S.top==-1) return false;
    x=S.bracket[S.top--];
    return true;
}

bool bracketChect(char str[], int length)
{
    SqStack S;
    InitStack(S);
    for(int i=0;i<length;i++){
        if(str[i]=='('||str[i]=='['||str[i]=='{') 
            PushStack(S, str[i]);
        else
        {
            if(IsEmpty(S)) return false;
            char Elem;
            DeStack(S, Elem);
            if(str[i]==')'&&Elem!='(') return false;
            if(str[i]==']'&&Elem!='[') return false;
            if(str[i]=='}'&&Elem!='{') return false;
        }
    }
    return IsEmpty(S);
}

int main()
{
    char str[10]={'{','{','(','(',')',')','[',']','}','}'};
    int length = sizeof(str)/sizeof(char);
    if(bracketChect(str, length)==true)
        printf("true");
    else 
        printf("false");
    return 0;
}