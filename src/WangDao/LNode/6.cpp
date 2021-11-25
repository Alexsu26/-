/*
带头节点，使其递增有序
时间空间复杂度都有点高
*/
void SortLL(LNode* L, LNode *&L2)
{
    LNode* head = L;
    if( head == NULL)
        return;
    LNode *p;
    LNode *newhead = L2;
    while(head->next != NULL)
    {
        p = head->next;
        int min = 1000000;
        while( p != NULL )
        {
            if( p->data <= min)
                min = p->data;
            p = p->next;
        }
        LNode *pre = head;
        p = head->next;
        while( p->data != min)
        {
            pre = p;
            p = p->next;
        }
        pre-next = p->next;
        newhead->next = p;
        newhead = newhead->next;
    }
    newhead->next = NULL;
}