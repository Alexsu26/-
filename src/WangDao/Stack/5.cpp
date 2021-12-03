/*
设计共享栈s1，s2，的入栈、出栈方式
*/
//假定s1的top1初始指向-1，s2的top2初始指向maxsize,数组叫Stack
//入栈

typedef struct{
    Elemtype stack[maxsize];
    int top[2];
}stk;
stk s;


void push(Elemtype x, int str)   //str=1表示s1入栈，str=2表示s2入栈
{
    if( top1+1 == top2 )            //判断是否栈满
        exit(0);
    if( str == 1 )
    {
        Stack[++top1] = x;
    }
    else if( str == 2)
    {
        Stack[--top2] = x;
    }
    else 
        exit(0); //
}
void pop(Elemtype x, int str, Elemtype &temp)
{
    if(str == 1)
    {
        if(top1 == -1)
            exit(0);
        temp = Stack[top1--];    
    }
    else if( str == 2)
    {
        if(top2 == maxsize)
            exit(0);
        temp = Stack[top2++];
    }
    else
        exit(0);
}