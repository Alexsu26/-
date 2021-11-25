void Delete_x(LNode *&L, int x)
{
    LNode *p;
    if( L == NULL)
        return;
    if( L->data == x)
    {
        p = L;
        L = L->next;
        free(p);
        Delete_x(L, x);
    }
    else
        Delete_x(L->next, x); 
}

