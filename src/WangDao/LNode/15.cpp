/*
A,B递增，求两集合交集，存放于A表中
*/
void UnionLL(LNode* A, LNode *B)
{
    LNode *p = A->next, *q= B->next;
    LNode *ra = A;
    ra->next = NULL;
    LNode *temp;
    while( p!=NULL && q!=NULL)
    {
        if( p->data == q->data )
        {
            ra->next = p;
            ra = ra->next;
            temp = q;
            q = q->next;
            free(temp);
            p = p->next;
        }
        else if( p->data < q->data)
        {
            temp = p;
            p = p->next;
            free(temp);
        }
        else
        {
            temp = q;
            q = q->next;
            free(temp);
        }
    }
    ra->next = NULL;
    // free(B);         释放b的表头
    while( p != NULL)
    {
        temp = p;
        p = p->next;
        free(temp);
    }
    while( q!= NULL)
    {
        temp = q;
        q = q->next;
        free(temp);
    }
}