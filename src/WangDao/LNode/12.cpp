/*
递增有序的单链表，删除重复结点
*/
void UniqueLL(LNode *&L)
{
    LNode *p = L->next;
    LNode *q;
    // if( p == NULL)              //先判断是否为空
    //     return ;
    
    while( p->next != NULL)
    {
        q = p->next;
        if( p->data == q->data )
        {
            p->next = q->next;
            free(q);
        }
        else
            p = p->next;
    }
}