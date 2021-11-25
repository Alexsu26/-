/*
带头结点A，分解为A，B，A为奇数项，B为偶数
*/
void Divide_A(LNode *A, LNode *B)
{
    LNode *p = A->next;
    LNode *pb = B;
    while( p != NULL )
    {
        pb->next = p->next;
        if(p->next != NULL)
            p->next = p->next->next;
        pb = pb->next;
        p = p->next;
    }
}