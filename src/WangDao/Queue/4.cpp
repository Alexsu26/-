/*
1。 该选择链式存储
带front和rear指针的单循环链表；
2。 队空：
front = rear = NULL;
队满：
stackoverflow 应该是rear->next == front;

仿照循环队列，牺牲一个结点作为队空队满的标志：
队空：
front == rear;
队满：
rear->next == front;
*/
//入队
void Push(queue &q, Elemtype x)
{
    if( 队满 )      //跟下面是一种情况；且这里的队满是指front没有空余了，而不是没有空间分配给队列
    {
        cout << "队满\n";
        exit(0);
    }
    if( rear->next == front )
    {
        LNode *temp = new LNode();
        temp->next = NULL;
        temp->data = x;
        rear->next = temp;
        temp->next = front;
    }
    else
    {
        rear = rear->next;
        rear->data = x;
    }
}
//出队：
Elemtype Pop(queue &q, Elemtype &x)
{
    if( 队空 )
    {
        cout << "队空\n";
        exit(0);
    }
    x = front->data;
    front = front->next;
    return x;
}