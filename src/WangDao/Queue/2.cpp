/*
Q为队列，S为空栈，将Q中的元素逆置
*/
void ReverseQueue(Queue &Q, Stack &S)
{
    while( !Q.empty() )
    {
        S.push(Q.front());
        Q.pop();
    }
    while( !S.empty() )
    {
        Q.push(S.top());
        S.pop();
    }
}