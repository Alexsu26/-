/*
hc为C的表头，C = {a,b,a,b,a,b},拆分其分A，B，空间复杂度为O(1)
代码跟10题一样
*/
LNode* Divide_A(LNode *A)
{
    LNode *B = new LNode();
    B->next = NULL;
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
    return B;
}