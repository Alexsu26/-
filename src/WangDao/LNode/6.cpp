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
//解答用的头插法，每次找到当前结点在前面递增的位置，好处
//是没有额外的空间；但时间复杂度仍为O(n)；可以先讲链表数据
//存放在数组中，再通过排序，时间复杂度为O(n)
void Sort(LNode *L)
{
    LNode *p = L->next, *pre;
    LNode *r = p->next;
    p-next = NULL;              //第一个结点
    p = r;
    while( p != NULL )
    {
        r = p->next;
        pre = L;
        while( pre->next != NULL && pre->data < p->data)
            pre = pre->next;
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
}