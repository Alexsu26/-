/*
带头结点A，B，递增，找到公共元素组成C，不能破坏原结点
*/
LNode* SameLL_A_B(LNode* L1, LNode* L2)
{
    LNode *C = new LNode();
    C->next = NULL;
    LNode *rc = C;
    LNode *p = L1->next, *q = L2->next;
    while( p!=NULL && q !=NULL)
    {
        if( p->data == q->data)
        {
            LNode *temp = new LNode();
            temp->data = p->data;
            temp->next = NULL;
            rc->next = temp;
            rc = rc->next;
            p = p->next;
            q = q->next;
        }
        else if( p->data < q->data)
            p = p->next;
        else
            q = q->next;
    }
    return C;
}