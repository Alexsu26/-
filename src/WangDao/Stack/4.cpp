/*
L为头结点的链表，data为字符型，判断其是否对称，如xyyx
*/
bool symmLL(LNode *L)
{
    int n = 0;
    LNode *p = L->next;
    while( p!= NULL )
        n++;
    int count = n/2;
    stack<char>S;
    p = L->next;
    while( count-- )
    {
        S.push(p->data);
        p = p->next;
    }
    if( n%2 == 1)
        p = p->next;
    while( p!=NULL && !Empty(S))        //while( p!=NULL && S.top()==p->data )
    {                                   //S.pop();p=p->next;
        if(p->data != S.top() )
            break;
        else
        {
            p = p->next;
            S.pop();
        }
    }
    if( p==NULL && Empty(S))
        return true;
    else
        return false;
}