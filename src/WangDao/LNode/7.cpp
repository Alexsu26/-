/*
删除带头节点，介于mn中间值的节点
*/
void Delete_m_n(LNode *L, Elemtype m, Elemtype n)
{
    LNode *p = L;
    while( p->next != NULL)
    {
        LNode *q = p->next;
        if( q->data >=m && q->data <=n )
        {
            p->next = q->next;
            free(q);
        }
        else
            p = q;

    }
}