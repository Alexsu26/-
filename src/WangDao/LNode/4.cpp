/*
带头节点，单链表，删除最小节点
*/
void Delete_minNode(LNode *&L, int &min)
{
    LNode *p;
    if( L == NULL)
        return;
    if( L->data < min)
    {
        min = L->data;
        Delete_minNode(L->next, min);
    }
    if( L->data == min)
    {
        p = L;
        L = L->next;
        free(p);
    } 
}

//书上使用pre和p遍历链表，用premin和minp存min的结点和前驱
{
    LNode *pre = L, *p = L->next;
    LNode *minpre = pre, *minp = p;
    while( p!= NULL)
    {
        if( p->data < minp->data)
        {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    minpre->next = minp->next;
    free(minp);
    return L;
}