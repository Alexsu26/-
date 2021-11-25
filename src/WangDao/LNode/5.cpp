/*
逆置 带头节点的单链表
*/
void ReverseLL(LNode *L)
{
    LNode *head = L;
    if(head == NULL)
        return;
    LNode* pre,*p,*next;
    pre = NULL;
    p = head->next;
    while( p->next != NULL)
    {
        next = p->next;
        p->next = pre;
        pre = p;
        p = next;
    }
    p->next = pre;
    head->next = p;
}
//书上解法2一致；解法1单独提出头结点，剩余结点用头插法，也不错
//时间复杂度都为O(n);
LNode* ReverseLL(LNode *L)
{
    LNode *p ,*r;
    p = L->next;
    L->next = NULL;
    while( p != NULL)
    {
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
    return L;
}