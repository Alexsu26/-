/*
A,B链表，判断B是否为A的连续子序列
*/
bool isSublist(LNode *A, LNode *B)
{
    LNode *p = A->next, *q = B->next;
    LNode *tempA,*tempB;

    while( p!=NULL )
    {
        if( p->data == q->data)
        {
            tempA = p;
            tempB = q;
            while( tempA!=NULL && tempB!=NULL)
            {
                if( tempA->data == tempB->data)
                {
                    tempA = tempA->next;
                    tempB = tempB->next;
                }
                else
                    break;
            }
            if( tempB == NULL )
            {
                return true;
            }
            else
            {
                p = tempA;
            }
        }
        else
            p = p->next;
    }
    return false;
}