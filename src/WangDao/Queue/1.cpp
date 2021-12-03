/*
循环队列，有front和rear，并设置有tag，以tag=0表示队空，tag=1表示队满，
*/
/*
队满条件:Q.front == Q.rear && Q.tag == 0
队空条件：Q.front == Q.rear && Q.tag == 1
*/


typedef struct
{  
    Elemtype a[maxsize];
    int front;
    int rear;
    int tag;
}Queue;
Queue q;
//入队
void push(Queue &q, Elemtype x)
{
    if(front == rear && tag == 1)
    {
        cout << "队满了\n";
        exit(0);
    }
    //q.a[q.rear] = x;
    rear = (rear + 1 )%maxsize;
}
//书上答案：
int EnQueue(SqQueue &Q, Elemtype x)
{
    if(Q.front == Q.rear && Q.tag == 1)
        return 0;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1 ) % maxsize;
    Q.tag = 1;                              //有入队就可能队满
    return 1;
}

//出队
Elemtype pop(Queue &q)
{
    if(front == rear && tag == 0)
    {
        cout << "队空了\n";
        exit(0); //
    }
    Elemtype x = q.a[front];
    front = ( front + 1 ) % maxsize;
    return x;
}
//书上答案：
int DeQueue(SqQueue &Q, Elemtype &x)
{
    if(Q.front == Q.rear && Q.tag = 0)
        return 0;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % maxsize;
    Q.tag = 0;                          //有出队就可能队空
    return 1;
}