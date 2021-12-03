/*
利用两个栈s1和s2模拟队列：
栈操作：
Push(S,x);
Pop(S,x);
StackEmpty(S);
StackOverflow(S);//栈满
队列操作：
Enqueue();
Dequeue();
QueueEmpty();

思路：通过s1表示入队，s2表示出队；
*/
/*
少了一种条件：当s1满了，s2为空时，可以再进入1个；
*/
void Enqueue(Stack &s1, Stack &s2, Elemtype x)
{
    // if(!StackOverflow(S1))                           //s1为满，都能入队
    // {
    //     Push(s1, x);
    //     return 1;
    // }
    //if(StackOverflow(s1) && !StackEmpty(s2))          //队列满的条件
    if(StackOverflow(s1) || StackOverflow(s2) )
    {
        cout << "栈满了\n";
        exit(0);
    }
    Elemtype temp;
    while(!StackEmpty(s2))
    {
        Pop(s2, temp);
        Push(s1, temp);
    }
    Push(s1, x);
}
//错太多了,重写一边书上答案
int EnQueue(Stack &s1, Stack &s2 Elemtype x)
{
    if( !StackOverflow(s1))
    {
        Push(s1, x);
        return 1;
    }
    if( StackOverflow(s1) && !StackEmpty(s2 ))
    {
        cout << "队满了";
        return 0;
    }
    if( StackOverflow(s1) && StackEmpty(s2))
        while(!StackEmpty(s1))
        {
            Pop(s1, temp);
            Push(s2, temp);
        }
    Push(s1, x);
    return 1;
}
//出队时不需要先从s1进栈，s2只要非空，就直接出，为空就把s1全入栈再出
//书上答案
void Dequeue(Stack &s1, Stack &s2, Elemtype &x)
{
    if( !StackEmpty(s2))
        Pop(s2, x);
    else if(StackEmpty(s1))
        cout << "队空";
    else
    {
        while( !StackEmpty(s1))
        {
            Pop(s1, x);
            Push(s2, x);
        }
        Pop(s2,x);
    }
}
void Dequeue(Stack &s1, Stack &s2, Elemtype &x)
{
    if(StackEmpty(s2) && StackEmpty(s1))
    {
        cout << "队是空的\n";
        exit(0);
    }
    Elemtype temp;  
    while(!StackEmpty(s1) )
    {
        Pop(s1, temp);
        Push(s2, temp);
    }
    Pop(s2, x);
}

//队为空
bool QueueEmpty(Stack &s1, Stack &s2)
{
    if(StackEmpty(s1) && StackEmpty(s2))
        return true;
    else
        return false;
}